/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:38:09 by hheng             #+#    #+#             */
/*   Updated: 2025/06/12 12:27:37 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    //std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    //std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
   //std::cout << "Copy constructor called" << std::endl;
    this->_fixedPointValue = other._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& other) {
    //std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// CONVERTION FUNCTION

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// OPERATORS

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

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

// ARITHMETIC OPERATORS

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
    Fixed result;
    result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / other._fixedPointValue);
    return result;
}


// INCREMENT/DECREMENT OPERATORS
// pre-incremnt = after add
Fixed& Fixed::operator++() {
    //std::cout << "Pre-increment operator called" << std::endl;
    this->_fixedPointValue++;
    return *this;
}

//post-increment = before add
Fixed Fixed::operator++(int) {
    //std::cout << "Post-increment operator called" << std::endl;
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed& Fixed::operator--() {
   //std::cout << "Pre-decrement operator called" << std::endl;
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
   //std::cout << "Post-decrement operator called" << std::endl;
    Fixed temp(*this);
    operator--();
    return temp;
}

// STATIC MEMBER FUNCTIONS (MIN/MAX)
/*
if (a < b)
    return a;
else
    return b;
*/
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



/*
1. Fixed a = default constructor
2. (Fixed(5.05f) * Fixed(2)); perform multiplication temporary
    2.1 Fixed(5.05f) = float constructor called
         _fixedPointValue = roundf(5.05 * (1 << 8)); ( << left = *)
                            = roundf(5.05 * 256)
                            = roundf(1292.8)
                            = 1293
    2.2 Fixed(2) = int constructor called
         _fixedPointValue = 2 << 8 ( 2 * 256 )
                            = 512
    2.3 Fixed(5.05f) * Fixed(2) = operator* called
         _fixedPointValue = (1293 * 512) >> 8 ( >> right = /)
                            = (661056) >> 8
                            = 2586
3. new Fixed with _fixedPointValue = 2586


4. Default constructor called" (inside multiplication operator)
5. continue for ++ a (finished a then go b)
6. ++a preicrement (add + 1 before used)
    6.1 so now a = 0.00390625 ( 1/256.0f) a.tofloat (output <<)
7. now a = 0.00390625
8. a++ post increment (add + 1 after used)
    8.1   Fixed temp(*this); -- copy constructor called
        -   to create a copy of a before increment to store a 0.00390625
        -   operator++();  -- pre-increment operator called
        -   so now before increment  a is 0.00390625
        -   return temp; -- return the copy of a that contains 0.00390625
        -   when return temp, temp destroy and descructor called
9. so now a do the post increment = 0.0078125 (0.00390625 + 0.00390625)


10. Fixed const b(...) continue from 3
    10.1  2 x destructor called to destroy the temporary Fixed objects created during the multiplication
    10.2 2586 / 256.0 = 10.1016 (a.tofloat)

11. compare a and b
    11.1 a = 0.0078125
    11.2 b = 10.1016
    11.3 Fixed::max(a, b) = b (because b > a)
    11.4 return b (const Fixed& max(const Fixed& a, const Fixed& b))
    11.5 so output is 10.1016

*/