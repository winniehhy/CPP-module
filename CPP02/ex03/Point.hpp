/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:41:06 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:41:08 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const x;
    Fixed const y;

public:
    // Default constructor
    Point();
    
    // Parameterized constructor
    Point(const float x, const float y);
    
    // Copy constructor
    Point(const Point &src);
    
    // Copy assignment operator
    Point &operator=(const Point &rhs);
    
    // Destructor
    ~Point();
    
    // Getters
    Fixed getX() const;
    Fixed getY() const;
};

#endif