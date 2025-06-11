/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:35:49 by hheng             #+#    #+#             */
/*   Updated: 2025/06/11 10:42:10 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
// Convert int to fixed point by shifting left by _fractionalBits
Fixed::Fixed(const int value) 
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

// Float constructor
// Convert float to fixed point by multiplying by 2^_fractionalBits and rounding
// 42.42 *256 = 10859.52
// in main , then tofloat ( 10860/256) = 42.421875 (roundf = 42.4219)

Fixed::Fixed(const float value) 
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) 
{
    this->_fixedPointValue = raw;
}

// Convert fixed point to float by dividing by 2^_fractionalBits
//static_cast= used to covert int to float safely

float Fixed::toFloat(void) const 
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

// Convert fixed point to int by shifting right by _fractionalBits
int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// << = Stream insertion operator overload ,for a
std::ostream &operator<<(std::ostream& out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}