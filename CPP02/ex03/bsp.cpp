/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:42:39 by hheng             #+#    #+#             */
/*   Updated: 2025/06/12 15:30:26 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// This function to check if the given point is strictly inside the triangle a,b,c 
// if point is on the edge or vertex, retrun false
// area of triangle = shoelace formula
static Fixed area(Point const &a, Point const &b, Point const &c) {
    Fixed area = ((a.getX() * (b.getY() - c.getY())) +
                 (b.getX() * (c.getY() - a.getY())) +
                 (c.getX() * (a.getY() - b.getY()))) / 2;
    
    if (area < 0)
        area = area * -1;
    
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = area(a, b, c);
    
    // 1. If the area of the main triangle is zero, return false, means the three point are on the same straight line
    // so area is zero and no point can be inside the triangle
    if (areaABC == 0)
        return false;
    
    // 2. small triangle of test point
    //If any of the sub-areas (areaPAB, areaPBC, areaPCA) is zero, the point lies on an edge or vertex, so return false.
    Fixed areaPAB = area(point, a, b);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPCA = area(point, c, a);
    
    if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
        return false;
    
    return (areaPAB + areaPBC + areaPCA) == areaABC;
}


/*
normal area of triangle = 1/2 *b *h

-> but in this case, no height, but only 3 vertice point of the tria

*/
