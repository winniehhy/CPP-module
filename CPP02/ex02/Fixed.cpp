/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:38:09 by hheng             #+#    #+#             */
/*   Updated: 2025/06/11 10:43:40 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    // Convert int to fixed point by shifting left by _fractionalBits
    _fixedPointValue = value << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    // Convert float to fixed point by multiplying by 2^_fractionalBits and rounding
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Get raw bits
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

// Set raw bits
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// Convert to float
float Fixed::toFloat(void) const {
    // Convert fixed point to float by dividing by 2^_fractionalBits
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

// Convert to int
int Fixed::toInt(void) const {
    // Convert fixed point to int by shifting right by _fractionalBits
    return this->_fixedPointValue >> _fractionalBits;
}

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    // We need to divide by 2^_fractionalBits because both values are already scaled
    Fixed result;
    result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    // Check for division by zero
    if (other._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    
    // We need to multiply by 2^_fractionalBits to maintain precision
    Fixed result;
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / other._fixedPointValue);
    return result;
}

// Increment/decrement operators
Fixed& Fixed::operator++() {
    // Pre-increment: increment by epsilon (1 / 2^_fractionalBits)
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    // Post-increment: return current value, then increment
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed& Fixed::operator--() {
    // Pre-decrement: decrement by epsilon
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    // Post-decrement: return current value, then decrement
    Fixed temp(*this);
    operator--();
    return temp;
}

// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}