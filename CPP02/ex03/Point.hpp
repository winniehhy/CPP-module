/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:41:06 by hheng             #+#    #+#             */
/*   Updated: 2025/06/12 16:16:18 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

/*
Point class - represent a 2D point with 2 coordinates (x, y)
- have 2 fixedp point value (x, y)
- every point object is immutable, meaning once created, the x and y values cannot be changed.
*/


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