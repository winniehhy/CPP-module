/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:42:43 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:43:25 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void printResult(std::string testName, bool result) {
    std::cout << testName << ": " << (result ? "Inside" : "Outside") << " triangle" << std::endl;
}

int main() {
    // Create triangle vertices
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);
    
    std::cout << "Testing with triangle [(0,0), (10,0), (5,10)]" << std::endl;
    
    // Test cases
    Point inside(5.0f, 5.0f);         // Point inside triangle
    Point onVertex(0.0f, 0.0f);       // Point on vertex
    Point onEdge(5.0f, 0.0f);         // Point on edge
    Point outside(20.0f, 20.0f);      // Point outside triangle
    
    // Run tests
    printResult("Point (5,5)", bsp(a, b, c, inside));
    printResult("Point (0,0)", bsp(a, b, c, onVertex));
    printResult("Point (5,0)", bsp(a, b, c, onEdge));
    printResult("Point (20,20)", bsp(a, b, c, outside));
    
    return 0;
}