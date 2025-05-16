/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:41:12 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:41:14 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : x(0), y(0) {
}

// Parameterized constructor
Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val) {
}

// Copy constructor
Point::Point(const Point &src) : x(src.x), y(src.y) {
}

// Copy assignment operator
Point &Point::operator=(const Point &rhs) {
    // Since x and y are const, we can't modify them
    // This is a special case where we implement the operator
    // but can't actually perform the assignment
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