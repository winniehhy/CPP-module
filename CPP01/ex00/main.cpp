/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:23:58 by hheng             #+#    #+#             */
/*   Updated: 2025/04/03 13:39:25 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstring>

void testStackZombie(const char* name = "StackZombie") {
    std::cout << "\n----- Testing Stack Zombie -----" << std::endl;
    std::cout << "Creating a zombie on the stack using randomChump..." << std::endl;
    randomChump(name);
    std::cout << "Test auto complete" << std::endl;
}

void testHeapZombie(const char* name = "HeapZombie") {
    std::cout << "\n----- Testing Heap Zombie -----" << std::endl;
    std::cout << "Creating a zombie on the heap using newZombie..." << std::endl;
    Zombie* heapZombie = newZombie(name);
    heapZombie->announce();
    std::cout << "Manually deleting the heap zombie..." << std::endl;
    delete heapZombie;
    std::cout << "Test complete" << std::endl;
}

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "Running default test." << std::endl;
        testStackZombie();
        testHeapZombie();
        return 0;
    }
    
    if (ac == 2) {
        testStackZombie(av[1]);
        testHeapZombie(av[1]);
        return 0;
    }
    
    std::cout << "Usage: ./Braiiiiiinzzzzzz [ZombieName]" << std::endl;
    return 1;
}
