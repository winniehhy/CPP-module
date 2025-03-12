/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:23:58 by hheng             #+#    #+#             */
/*   Updated: 2025/03/12 13:43:50 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstring>

void displayHelp() {
    std::cout << "Usage: ./zombie [TEST_CASE]" << std::endl;
    std::cout << "TEST_CASES:" << std::endl;
    std::cout << "  stack    - Test stack allocation (randomChump)" << std::endl;
    std::cout << "  heap     - Test heap allocation (newZombie)" << std::endl;
    std::cout << "  both     - Test both allocation methods" << std::endl;
    std::cout << "  custom   - Create a custom zombie with a given name" << std::endl;
    std::cout << "  horde    - Create multiple zombies" << std::endl;
    std::cout << "  all      - Run all tests" << std::endl;
}

void testStackZombie(const char* name = "StackZombie") {
    std::cout << "\n----- Testing Stack Zombie -----" << std::endl;
    std::cout << "Creating a zombie on the stack using randomChump..." << std::endl;
    randomChump(name);
    std::cout << "Test complete - notice the zombie was automatically destroyed" << std::endl;
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

void testCustomZombie(const char* name) {
    std::cout << "\n----- Testing Custom Zombie -----" << std::endl;
    
    // Create on stack
    std::cout << "Creating " << name << " on the stack:" << std::endl;
    {
        Zombie stackZombie(name);
        stackZombie.announce();
    }
    std::cout << "Stack zombie scope ended" << std::endl;
    
    // Create on heap
    std::cout << "\nCreating " << name << " on the heap:" << std::endl;
    Zombie* heapZombie = newZombie(name);
    heapZombie->announce();
    delete heapZombie;
    std::cout << "Test complete" << std::endl;
}

void testZombieHorde(int count = 3) {
    std::cout << "\n----- Testing Zombie Horde -----" << std::endl;
    std::cout << "Creating " << count << " zombies on the heap..." << std::endl;
    
    Zombie** horde = new Zombie*[count];
    
    // Create zombies
    for (int i = 0; i < count; i++) {
        std::string name = "Zombie";
        name += static_cast<char>('A' + i);  // ZombieA, ZombieB, ZombieC, etc.
        horde[i] = newZombie(name);
    }
    
    // Make them announce
    for (int i = 0; i < count; i++) {
        horde[i]->announce();
    }
    
    // Clean up
    std::cout << "\nDeleting zombie horde..." << std::endl;
    for (int i = 0; i < count; i++) {
        delete horde[i];
    }
    delete[] horde;
    
    std::cout << "Test complete" << std::endl;
}

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "No test case specified. Running default test." << std::endl;
        testStackZombie();
        testHeapZombie();
        return 0;
    }
    
    const char* testCase = av[1];
    
    if (strcmp(testCase, "help") == 0 || strcmp(testCase, "--help") == 0 || strcmp(testCase, "-h") == 0) {
        displayHelp();
    }
    else if (strcmp(testCase, "stack") == 0) {
        testStackZombie();
    }
    else if (strcmp(testCase, "heap") == 0) {
        testHeapZombie();
    }
    else if (strcmp(testCase, "both") == 0) {
        testStackZombie();
        testHeapZombie();
    }
    else if (strcmp(testCase, "custom") == 0) {
        if (ac >= 3) {
            testCustomZombie(av[2]);
        } else {
            std::cout << "Error: Custom test requires a zombie name" << std::endl;
            std::cout << "Example: ./zombie custom Bob" << std::endl;
        }
    }
    else if (strcmp(testCase, "horde") == 0) {
        int count = 3;  // Default count
        if (ac >= 3) {
            count = atoi(av[2]);
            if (count <= 0) count = 3;  // Validate input
        }
        testZombieHorde(count);
    }
    else if (strcmp(testCase, "all") == 0) {
        testStackZombie();
        testHeapZombie();
        testCustomZombie("CustomZombie");
        testZombieHorde();
    }
    else {
        std::cout << "Unknown test case: " << testCase << std::endl;
        displayHelp();
    }
    
    return 0;
}