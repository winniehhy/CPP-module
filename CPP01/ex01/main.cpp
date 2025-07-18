/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:44:27 by hheng             #+#    #+#             */
/*   Updated: 2025/06/10 17:26:02 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::string baseName;
    std::cout << "Enter the zombie name: ";
    std::getline(std::cin, baseName);
    if (baseName.empty()) {
        std::cout << "Zombie name cannot be empty." << std::endl;
        return 1;
    }

    int arraySize = 0;
    std::cout << "Enter the number of zombies in the horde: ";
    std::cin >> arraySize;
    if (arraySize <= 0) {
        std::cout << "Invalid horde size. Please enter a positive number." << std::endl;
        return 1;
    }

    std::cout << "Creating a horde of " << arraySize
              << " zombies with base name \"" << baseName << "\"..." << std::endl;
    
    Zombie* zombieArray = zombieHorde(arraySize, baseName);
    
    std::cout << "\nZombies announcing themselves:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        zombieArray[i].announce();
    }
    
    std::cout << "\nDestroying the zombie horde..." << std::endl;
    delete[] zombieArray;  //delete the entire array at once

    std::cout << "All zombies have been destroyed." << std::endl;
    return 0;
}
