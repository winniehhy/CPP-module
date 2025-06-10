/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:33:09 by hheng             #+#    #+#             */
/*   Updated: 2025/06/10 19:19:53 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();
    
    // Copy constructor
    Fixed(const Fixed& other);
    
    // Copy assignment operator
    Fixed& operator=(const Fixed& other);
    
    // Destructor
    ~Fixed();
    
    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif