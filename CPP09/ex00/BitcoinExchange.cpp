#include "BitcoinExchange.hpp"

// =============================================================================
// Constructors & Destructor & Assignment
// =============================================================================

BitcoinExchange::BitcoinExchange() {
    if (!loadDatabase("data.csv"))
        throw DatabaseError();

    if (_priceDatabase.empty())
        throw EmptyDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
    _priceDatabase(other._priceDatabase) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _priceDatabase = other._priceDatabase;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// =============================================================================
// Database Loading
// =============================================================================

bool BitcoinExchange::loadDatabase(const std::string& filepath) {
    std::ifstream file(filepath.c_str());
    if (!file)
        return false;

    std::string line;

    // Skip header if present (contains "date")
    if (std::getline(file, line)) {
        std::string cleaned = stripWhitespace(line);
        if (cleaned.find("date") == std::string::npos) {
            // First line is data, not a header - process it
            std::string date;
            float rate;
            if (parseDatabaseLine(line, date, rate))
                _priceDatabase[date] = rate;
        }
    }

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::string date;
        float rate;
        if (parseDatabaseLine(line, date, rate))
            _priceDatabase[date] = rate;
    }

    return true;
}

bool BitcoinExchange::parseDatabaseLine(const std::string& line,
                                        std::string& date, float& rate) {
    // Expected format: "YYYY-MM-DD,rate"
    size_t commaPos = line.find(',');
    if (commaPos == std::string::npos)
        return false;

    date = stripWhitespace(line.substr(0, commaPos));
    std::string rateStr = stripWhitespace(line.substr(commaPos + 1));

    if (!checkDateFormat(date))
        return false;

    char* endPtr = NULL;
    errno = 0;
    rate = std::strtof(rateStr.c_str(), &endPtr);

    if (endPtr == rateStr.c_str() || *endPtr != '\0' || errno == ERANGE)
        return false;

    return true;
}

// =============================================================================
// Input File Processing
// =============================================================================

void BitcoinExchange::evaluateInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << RED << "Error: could not open file." << RESET << std::endl;
        return;
    }

    std::string line;

    // Skip header "date | value" if present
    if (std::getline(file, line)) {
        std::string cleaned = stripWhitespace(line);
        if (cleaned != "date | value") {
            // First line is not the header - rewind and process it as data
            file.seekg(0);
        }
    }

    while (std::getline(file, line)) {
        if (stripWhitespace(line).empty())
            continue;

        // Step 1: parse structure -> prints "bad input" if pipe missing
        std::string date, valueStr;
        if (!parseInputLine(line, date, valueStr))
            continue;

        // Step 2: validate date format -> prints "bad input" if date invalid
        if (!checkDateFormat(date)) {
            std::cerr << RED << "Error: bad input => " << date << RESET << std::endl;
            continue;
        }

        // Step 3: validate value -> prints "not a positive number" / "too large a number"
        // NOTE: validateValueRange() uses strtof internally, which correctly handles
        // negative numbers. We do NOT call isNumericString() on valueStr here because
        // it would reject "-1" (the '-' char fails the digit check) and wrongly
        // print "bad input" instead of "not a positive number".
        float value;
        if (!validateValueRange(valueStr, value))
            continue;

        // Step 4: look up exchange rate
        float rate = lookupRate(date);
        if (rate < 0) {
            std::cerr << RED << "Error: no exchange rate data for => " << date << RESET << std::endl;
            continue;
        }

        // Step 5: print result
        std::cout << date << " => " << valueStr << " = " << value * rate << std::endl;
    }
}

bool BitcoinExchange::parseInputLine(const std::string& line,
                                     std::string& date, std::string& valueStr) {
    // Expected format: "YYYY-MM-DD | value" (with spaces around pipe)
    size_t pipePos = line.find(" | ");
    if (pipePos == std::string::npos) {
        std::cerr << RED << "Error: bad input => " << stripWhitespace(line) << RESET << std::endl;
        return false;
    }

    date     = stripWhitespace(line.substr(0, pipePos));
    valueStr = stripWhitespace(line.substr(pipePos + 3)); // +3 skips " | "

    return true;
}

// =============================================================================
// Rate Lookup
// =============================================================================

float BitcoinExchange::lookupRate(const std::string& date) const {
    if (_priceDatabase.empty())
        return -1;

    // Try exact match first
    std::map<std::string, float>::const_iterator it = _priceDatabase.find(date);
    if (it != _priceDatabase.end())
        return it->second;

    // lower_bound returns first element >= key
    it = _priceDatabase.lower_bound(date);

    // Date is before all entries in the database
    if (it == _priceDatabase.begin())
        return -1;

    // Step back to get the closest earlier date
    --it;
    return it->second;
}

// =============================================================================
// Validation Functions
// =============================================================================

std::string BitcoinExchange::stripWhitespace(const std::string& str) const {
    if (str.empty())
        return "";

    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(start, end - start + 1);
}

bool BitcoinExchange::checkDateFormat(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr  = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr   = date.substr(8, 2);

    if (!isNumericString(yearStr) || !isNumericString(monthStr) || !isNumericString(dayStr))
        return false;

    int year  = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day   = std::atoi(dayStr.c_str());

    if (year <= 0 || month < 1 || month > 12 || day < 1)
        return false;

    static const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                                       31, 31, 30, 31, 30, 31};
    int maxDay = monthDays[month - 1];

    if (month == 2 && isLeapYear(year))
        maxDay = 29;

    if (day > maxDay)
        return false;

    return true;
}

bool BitcoinExchange::validateValueRange(const std::string& valueStr, float& value) const {
    if (valueStr.empty()) {
        std::cerr << RED << "Error: invalid value => " << valueStr << RESET << std::endl;
        return false;
    }

    char* endPtr = NULL;
    errno = 0;
    value = std::strtof(valueStr.c_str(), &endPtr);

    if (endPtr == valueStr.c_str() || *endPtr != '\0' || errno == ERANGE) {
        std::cerr << RED << "Error: invalid value => " << valueStr << RESET << std::endl;
        return false;
    }

    if (value < 0) {
        std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
        return false;
    }

    if (value > 1000) {
        std::cerr << RED << "Error: too large a number." << RESET << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::isNumericString(const std::string& str) const {
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::isLeapYear(int year) const {
    if (year % 4 != 0)
        return false;
    if (year % 100 == 0)
        return (year % 400 == 0);
    return true;
}

// =============================================================================
// Exception Messages
// =============================================================================

const char* BitcoinExchange::DatabaseError::what() const throw() {
    return "Error: could not open database file.";
}

const char* BitcoinExchange::EmptyDatabase::what() const throw() {
    return "Error: database is empty.";
}