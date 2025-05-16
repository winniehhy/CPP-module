/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:42:36 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:43:00 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor - initializes value to 0
Fixed::Fixed() : value(0) {
}

// Int constructor - converts int to fixed-point
Fixed::Fixed(const int intValue) : value(intValue << fractionalBits) {
}

// Float constructor - converts float to fixed-point
Fixed::Fixed(const float floatValue) : value(roundf(floatValue * (1 << fractionalBits))) {
}

// Copy constructor
Fixed::Fixed(const Fixed &src) {
    *this = src;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &rhs) {
    if (this != &rhs) {
        this->value = rhs.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
}

// Returns the raw value of the fixed-point number
int Fixed::getRawBits(void) const {
    return this->value;
}

// Sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

// Converts fixed-point to float
float Fixed::toFloat(void) const {
    return (float)this->value / (1 << fractionalBits);
}

// Converts fixed-point to int
int Fixed::toInt(void) const {
    return this->value >> fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed &rhs) const {
    return this->value > rhs.value;
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->value < rhs.value;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return this->value >= rhs.value;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return this->value <= rhs.value;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->value == rhs.value;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return this->value != rhs.value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->value + rhs.value);
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->value - rhs.value);
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits((int64_t)this->value * rhs.value >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    if (rhs.value == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits(((int64_t)this->value << fractionalBits) / rhs.value);
    return result;
}

// Pre-increment operator
Fixed &Fixed::operator++() {
    ++this->value;
    return *this;
}

// Post-increment operator
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

// Pre-decrement operator
Fixed &Fixed::operator--() {
    --this->value;
    return *this;
}

// Post-decrement operator
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Min/max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Output stream operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}