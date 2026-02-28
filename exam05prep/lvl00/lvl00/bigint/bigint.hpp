#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
private:
    std::string value;
    
    // Helper to remove leading zeros
    std::string normalize(const std::string& s) const;

public:
    // Constructors
    bigint();
    bigint(unsigned int n);
    bigint(const std::string& s);
    bigint(const bigint& other);
    
    // Assignment
    bigint& operator=(const bigint& other);
    
    // Addition
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);
    
    // Digit shift
    bigint operator<<(unsigned int shift) const;
    bigint operator>>(unsigned int shift) const;
    bigint& operator<<=(unsigned int shift);
    bigint& operator>>=(unsigned int shift);
    bigint& operator>>=(const bigint& shift);
    
    // Comparison operators
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;
    
    // Increment (for main.cpp compatibility)
    bigint operator++(int);
    bigint& operator++();
    
    // Subtraction (for main.cpp compatibility - simplified)
    bigint operator-(const bigint& other) const;
    
    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const bigint& b);
};

#endif