/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:44:37 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 09:53:50 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

/**
 * Creates a horde of N zombies with the given name
 * @param N Number of zombies to create
 * @param name Name to give to each zombie
 * @return Pointer to the first zombie in the horde
 */
Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;
        
    // Allocate N zombies in a single allocation
    Zombie* horde = new Zombie[N];
    
    // Initialize each zombie with the given name
    for (int i = 0; i < N; i++) {
        // Use stringstream instead of std::to_string (which is C++11)
        std::stringstream ss;
        ss << name << " #" << (i + 1);
        horde[i].setName(ss.str());
    }
    
    return horde;
}