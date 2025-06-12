/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:42:43 by hheng             #+#    #+#             */
/*   Updated: 2025/06/12 16:32:47 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

void printResult(std::string testName, bool result) {
    std::cout << testName << ": " << (result ? "Inside" : "Outside") << " triangle" << std::endl;
}

int main() {
    // Create triangle vertices, point object
    Point triA(0, 0);
    Point triB(10, 0);
    Point triC(5, 10);

    std::cout << "Testing with triangle [(0,0), (10,0), (5,10)]" << std::endl;

    // Test cases
    Point inside(5, 5);               // Point inside triangle
    Point onVertex(0.0f, 0.0f);       // Point on vertex, 1 subarea = 0
    Point onEdge(5.0f, 0.0f);         // Point on edge
    Point outside(20.0f, 20.0f);      // Point outside triangle

    // Additional test cases
    Point negativeInside(-15, -20);
    Point negativeOutside(-20, -20);
    Point outsideDegenerate(10, 10);
    Point insideDegenerate(10, 5);
    Point exactCenter(5, 10.0f/3.0f); // Centroid for this triangle

    // Run tests
    printResult("Point (5,5)", bsp(triA, triB, triC, inside));
    printResult("Point (0,0)", bsp(triA, triB, triC, onVertex));
    printResult("Point (5,0)", bsp(triA, triB, triC, onEdge));
    printResult("Point (20,20)", bsp(triA, triB, triC, outside));
    printResult("Negative Inside (-15, -20)", bsp(triA, triB, triC, negativeInside));
    printResult("Negative Outside (-20, -20)", bsp(triA, triB, triC, negativeOutside));
    printResult("Outside Degenerate (10, 10)", bsp(triA, triB, triC, outsideDegenerate));
    printResult("Inside Degenerate (10, 5)", bsp(triA, triB, triC, insideDegenerate));
    printResult("Exact Center (5, 10.0f/3.0f)", bsp(triA, triB, triC, exactCenter));

    return 0;
}