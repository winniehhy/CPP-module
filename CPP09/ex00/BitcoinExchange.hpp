#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <climits>

// ANSI color codes for terminal output
#define RED   "\033[31m"
#define RESET "\033[0m"

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    // Entry point: open input file and evaluate each line
    void evaluateInputFile(const std::string& filename);

    class DatabaseError : public std::exception {
    public:
        const char* what() const throw();
    };

    class EmptyDatabase : public std::exception {
    public:
        const char* what() const throw();
    };

private:
    std::map<std::string, float> _priceDatabase;

    // Database
    bool  loadDatabase(const std::string& filepath);
    bool  parseDatabaseLine(const std::string& line, std::string& date, float& rate);

    
    bool  parseInputLine(const std::string& line, std::string& date, std::string& valueStr);
    void  processAndPrint(const std::string& date, const std::string& valueStr);

    // Rate lookup
    float lookupRate(const std::string& date) const;

    // Helpers
    std::string stripWhitespace(const std::string& str) const;
    bool        checkDateFormat(const std::string& date) const;
    bool        validateValueRange(const std::string& valueStr, float& value) const;
    bool        isNumericString(const std::string& str) const;
    bool        isLeapYear(int year) const;
};

#endif