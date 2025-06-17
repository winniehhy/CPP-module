/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:38:18 by hheng             #+#    #+#             */
/*   Updated: 2025/06/13 14:36:03 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main(void) {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));
    
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max(a, b) << std::endl; // b is const
    
//     return 0;
// }


int main(void) {
    // 1. Pre/Post Increment & Decrement Test
    Fixed a;
    std::cout << "----- Pre/Post Increment & Decrement Test -----" << std::endl;
    std::cout << "Original a: " << a << std::endl;
    std::cout << "++a (pre-increment): " << ++a << std::endl;
    std::cout << "a after pre-increment: " << a << std::endl;
    std::cout << "a++ (post-increment): " << a++ << std::endl;
    std::cout << "a after post-increment: " << a << std::endl;
    std::cout << "--a (pre-decrement): " << --a << std::endl;
    std::cout << "a after pre-decrement: " << a << std::endl;
    std::cout << "a-- (post-decrement): " << a-- << std::endl;
    std::cout << "a after post-decrement: " << a << std::endl;
    std::cout << std::endl;

    // 2. max/min with non-const and const
    Fixed a2(1.5f);
    Fixed b2(2.5f);
    const Fixed ca(3.5f);
    const Fixed cb(4.5f);

    std::cout << "----- max/min with non-const and const -----" << std::endl;
    Fixed& maxRef = Fixed::max(a2, b2);
    Fixed& minRef = Fixed::min(a2, b2);
    std::cout << "Non-const maxRef(a2, b2): " << maxRef << std::endl;
    std::cout << "Non-const minRef(a2, b2): " << minRef << std::endl;

    // Can modify the result through the reference!
    maxRef = Fixed(1.0f); //b2
    minRef = Fixed(-5.0f); //a2
    std::cout << "After modifying maxRef and minRef:" << std::endl;
    std::cout << "a2 = " << a2 << ", b2 = " << b2 << std::endl;

    // Const version: at least one argument is const
    const Fixed& maxCRef = Fixed::max(a2, ca);
    const Fixed& minCRef = Fixed::min(cb, b2);
    std::cout << "Const maxCRef(a2, ca): " << maxCRef << std::endl;
    std::cout << "Const minCRef(cb, b2): " << minCRef << std::endl;
    std::cout << std::endl;

    // 3. Test with const and assignment
    Fixed a3;
    Fixed const b3(Fixed(5.05f) * Fixed(2));
    std::cout << "----- Const and Assignment Test -----" << std::endl;
    std::cout << "Initial values:" << std::endl;
    std::cout << "a3 = " << a3 << ", b3 = " << b3 << std::endl;

    // Change a3 (allowed)
    a3 = Fixed(42.42f);
    std::cout << "After changing a3:" << std::endl;
    std::cout << "a3 = " << a3 << ", b3 = " << b3 << std::endl;
    
    std::cout << "----- Compare max min after a3 modified ------ " << std::endl;
    std::cout << "max(a3, b3): " << Fixed::max(a3, b3) << std::endl;
    std::cout << "min(a3, b3): " << Fixed::min(a3, b3) << std::endl;
    // Try to change b3 (not allowed, will cause compile error if uncommented)
    // b3 = Fixed(99.99f); // ❌ Error: assignment of read-only variable ‘b3’

    // Try to change max(a3, b3)
    // This will return a const reference because b3 is const, so you cannot modify it
    // Fixed::max(a3, b3) = Fixed(123.45f); // ❌ Error: assignment of read-only location
    
    Fixed a5 = Fixed(10.0f);
    Fixed b5 = Fixed(20.0f);

    std :: cout << "compare a5 and b5 = " << (a5 > b5) << std::endl;
    std :: cout << "compare a5 and b5 = " << (a5 < b5) << std::endl;
    std :: cout << "compare a5 and b5 = " << (a5 >= b5) << std::endl;
    std :: cout << "compare a5 and b5 = " << (a5 <= b5) << std::endl;
    std :: cout << "compare a5 and b5 = " << (a5 == b5) << std::endl;
    std :: cout << "compare a5 and b5 = " << (a5 != b5) << std::endl;
    return 0;
}
