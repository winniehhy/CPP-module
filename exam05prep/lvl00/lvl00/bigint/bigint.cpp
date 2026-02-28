#include "bigint.hpp"

// remove leading zeros
std::string bigint::normalize(const std::string& s) const {
    size_t start = 0;
    while (start < s.length() - 1 && s[start] == '0') start++;
    return s.substr(start);
}

// Constructors
bigint::bigint() : value("0") {}

bigint::bigint(unsigned int n) {
    if (n == 0) {
        value = "0";
        return;
    }
    value = "";
    while (n != 0) {
        value = char('0' + n % 10) + value;
        n /= 10;
    }
}

bigint::bigint(const std::string& s) : value(normalize(s)) {}

bigint::bigint(const bigint& other) : value(other.value) {}

// Assignment
bigint& bigint::operator=(const bigint& other) {
    if (this != &other) value = other.value;
    return *this;
}

// Addition
bigint bigint::operator+(const bigint& other) const {
    std::string result;
    int carry = 0;
    
    // Start from the rightmost digits
    int i = value.length() - 1;
    int j = other.value.length() - 1;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? value[i--] - '0' : 0;
        int digit2 = (j >= 0) ? other.value[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        
        result = char('0' + sum % 10) + result;
        carry = sum / 10;
    }
    
    return bigint(result);
}

bigint& bigint::operator+=(const bigint& other) {
    return *this = *this + other;
}

// Digit shift
bigint bigint::operator<<(unsigned int shift) const {
    std::string result = value;
    for (unsigned int i = 0; i < shift; i++) {
        result += '0';
    }
    return bigint(result);
}

bigint bigint::operator>>(unsigned int shift) const {
    if (shift >= value.length()) {
        return bigint();
    }
    return bigint(value.substr(0, value.length() - shift));
}

bigint& bigint::operator<<=(unsigned int shift) {
    return *this = *this << shift;
}

bigint& bigint::operator>>=(unsigned int shift) {
    return *this = *this >> shift;
}

bigint& bigint::operator>>=(const bigint& shift) {
    // Convert bigint to unsigned int for shifting
    unsigned int shiftValue = 0;
    for (size_t i = 0; i < shift.value.length(); i++) {
        shiftValue = shiftValue * 10 + (shift.value[i] - '0');
    }
    return *this = *this >> shiftValue;
}

// Comparison operators
bool bigint::operator==(const bigint& other) const {
    return value == other.value;
}

bool bigint::operator!=(const bigint& other) const {
    return value != other.value;
}

bool bigint::operator<(const bigint& other) const {
    return value.length() < other.value.length() || 
           (value.length() == other.value.length() && value < other.value);
}

bool bigint::operator>(const bigint& other) const {
    return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

// Increment 
bigint bigint::operator++(int) {
    bigint temp(*this);
    *this += bigint(1);
    return temp;
}

bigint& bigint::operator++() {
    return *this += bigint(1);
}

// Subtraction 
bigint bigint::operator-(const bigint& other) const {
    return bigint("0"); // As in original implementation
}

// Output operator
std::ostream& operator<<(std::ostream& os, const bigint& b) {
    return os << b.value;
}