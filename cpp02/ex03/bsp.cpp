/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:42:39 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:43:18 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Calculate the area of a triangle using cross product
static Fixed area(Point const &a, Point const &b, Point const &c) {
    // Area = |(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))| / 2
    Fixed area = ((a.getX() * (b.getY() - c.getY())) +
                 (b.getX() * (c.getY() - a.getY())) +
                 (c.getX() * (a.getY() - b.getY()))) / 2;
    
    // We need the absolute value
    if (area < 0)
        area = area * -1;
    
    return area;
}

// BSP function to check if point is inside triangle
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate the area of the triangle ABC
    Fixed areaABC = area(a, b, c);
    
    // If the triangle has zero area, point can't be inside
    if (areaABC == 0)
        return false;
    
    // Calculate areas of three triangles formed by the point and two vertices
    Fixed areaPAB = area(point, a, b);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPCA = area(point, c, a);
    
    // If any sub-area is zero, the point lies on an edge or vertex
    if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
        return false;
    
    // Point is inside if the sum of the three areas equals the area of the triangle
    return (areaPAB + areaPBC + areaPCA) == areaABC;
}