/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:35:42 by hheng             #+#    #+#             */
/*   Updated: 2025/06/11 10:13:57 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath> // for roundf

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // Constructors
    Fixed();                        // Default constructor
    Fixed(const int value);         // Int constructor
    Fixed(const float value);       // Float constructor
    Fixed(const Fixed& other);      // Copy constructor
    
    // Assignment operator
    Fixed& operator=(const Fixed& other);
    
    // Destructor
    ~Fixed();
    
    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif