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
    if (this != &other) {
        _priceDatabase = other._priceDatabase;
    }
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
    
    // Skip header if present
    if (std::getline(file, line)) {
        std::string cleaned = stripWhitespace(line);
        if (cleaned.find("date") == std::string::npos) {
            // First line is data, not header - process it
            std::string date;
            float rate;
            if (parseDatabaseLine(line, date, rate))
                _priceDatabase[date] = rate;
        }
    }
    
    // Read all data lines
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
    
    // Parse rate using strtof for better error handling
    char* endPtr = NULL;
    errno = 0;
    rate = std::strtof(rateStr.c_str(), &endPtr); // convert string to float
    
    // Check for conversion errors
    if (endPtr == rateStr.c_str() || *endPtr != '\0' || errno == ERANGE)
        return false;
    
    return true;
}



// =============================================================================
// Rate Lookup
// =============================================================================

float BitcoinExchange::lookupRate(const std::string& date) const {
    if (_priceDatabase.empty())
        return -1;
    
    // Try exact match first
    // Returns iterator pointing to the found pair
    // If not found, returns end()
    std::map<std::string, float>::const_iterator it = _priceDatabase.find(date);
    if (it != _priceDatabase.end()) // element found
        return it->second; // . Access value. Map store data as pair. First = KEY, second = VALUE
    
    // No exact match - find closest earlier date
    // lower_bound returns first element >= key
    it = _priceDatabase.lower_bound(date);
    
    // If lower_bound points to begin(), input date is before all data
    if (it == _priceDatabase.begin())
        return -1;
    
    // Move back one position to get closest earlier date
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
    // Must be exactly "YYYY-MM-DD" format
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    // Extract year, month, day strings
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    
    // Check all parts are numeric
    if (!isNumericString(yearStr) || !isNumericString(monthStr) || !isNumericString(dayStr))
        return false;
    
    // Convert to integers
    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());
    
    // Validate ranges
    if (year <= 0 || year >= INT_MAX)
        return false;
    
    if (month < 1 || month > 12)
        return false;
    
    if (day < 1)
        return false;
    
    // Days in each month
    static const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                                       31, 31, 30, 31, 30, 31};
    int maxDay = monthDays[month - 1];
    
    // Adjust for leap year in February
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
    
    // Parse the number using strtof
    char* endPtr = NULL;
    errno = 0;
    value = std::strtof(valueStr.c_str(), &endPtr);
    
    // Check for parsing errors
    if (endPtr == valueStr.c_str() || *endPtr != '\0' || errno == ERANGE) {
        std::cerr << RED << "Error: invalid value => " << valueStr << RESET << std::endl;
        return false;
    }
    
    // Check range constraints
    if (value < 0) {
        std::cerr << RED << "Error: not a positive number" << RESET << std::endl;
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
    // Divisible by 4
    if (year % 4 != 0)
        return false;
    
    // Century years must be divisible by 400
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
