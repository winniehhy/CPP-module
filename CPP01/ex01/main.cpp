/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:44:27 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 09:53:09 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int hordeSize = 5;
    std::cout << "Creating a horde of " << hordeSize << " zombies..." << std::endl;
    
    // Create a horde of zombies
    Zombie* horde = zombieHorde(hordeSize, "Horde Zombie");
    
    // Make each zombie announce itself
    std::cout << "\nZombies announcing themselves:" << std::endl;
    for (int i = 0; i < hordeSize; i++) {
        horde[i].announce();
    }
    
    // Delete the entire horde (to avoid memory leaks)
    std::cout << "\nDestroying the zombie horde..." << std::endl;
    delete[] horde;
    
    std::cout << "All zombies have been destroyed." << std::endl;
    
    return 0;
}