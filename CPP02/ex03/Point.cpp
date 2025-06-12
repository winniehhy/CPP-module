/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:41:12 by hheng             #+#    #+#             */
/*   Updated: 2025/06/12 16:13:41 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor, set the point origin (0,0)
Point::Point() : x(0), y(0) 
{
    //std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor to store x and y as Fixed point values
Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val) {
}

// Copy constructor
Point::Point(const Point &src) : x(src.x), y(src.y) {
}

// Copy assignment operator
// Since x and y are const, we can't modify them
// This is a special case where we implement the operator
// but can't actually perform the assignment
Point &Point::operator=(const Point &rhs)
 {
    (void)rhs;
    return *this;
}

// Destructor
Point::~Point() {
}

// Getter for x
Fixed Point::getX() const {
    return this->x;
}

// Getter for y
Fixed Point::getY() const {
    return this->y;
}