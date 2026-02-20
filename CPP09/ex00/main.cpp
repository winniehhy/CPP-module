#include "BitcoinExchange.hpp"

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
            // Process first line as data if it's not the header
            file.seekg(0); // Rewinds the file cursor back to byte position 0 (start of file
        }

    }
    
    // Process each line
    while (std::getline(file, line)) {
        if (stripWhitespace(line).empty())
            continue;
        
        std::string date, valueStr;
        if (!parseInputLine(line, date, valueStr)) {
            std::cerr << RED << "Error: Bad Input => " << line << RESET << std::endl;
            continue;
        }
        
        // Validate date format
        if (!checkDateFormat(date)) {
            std::cerr << RED << "Error: invalid date => " << date << RESET << std::endl;
            continue;
        }
        
        // Validate and convert value
        float value;
        if (!validateValueRange(valueStr, value)) {
            continue; // Error message already printed
        }
        
        // Look up exchange rate
        float rate = lookupRate(date);
        if (rate < 0) {
            std::cerr << RED << "No exchange rate data for this date => " << date << RESET << std::endl;
            continue;
        }
        
        // Calculate and output result
        float result = value * rate;
        std::cout << date << " => " << valueStr << " = " << result << std::endl;
    }
}

bool BitcoinExchange::parseInputLine(const std::string& line,
                                     std::string& date, std::string& valueStr) {
    // Expected format: "YYYY-MM-DD | value" (space-pipe-space)
    size_t pipePos = line.find(" | ");
    if (pipePos == std::string::npos)
        return false;
    
    date = stripWhitespace(line.substr(0, pipePos));
    valueStr = stripWhitespace(line.substr(pipePos + 3)); // +3 to skip " | "
    
    return true;
}



int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << RED << "Error: could not open file." << RESET << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange exchange;
        exchange.evaluateInputFile(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return 1;
    }
    
    return 0;
}