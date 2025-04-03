/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:39:59 by hheng             #+#    #+#             */
/*   Updated: 2025/04/03 14:42:13 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * Creates a horde of N zombies, all with the same base name.
 *
 * @param N Number of zombies to create.
 * @param name Name to assign to each zombie.
 * @return Pointer to the first zombie in the horde.
 */
Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;

    // Allocate all zombies in a single block
    Zombie* horde = new Zombie[N];

    // Assign names using the constructor
    for (int i = 0; i < N; i++) {
        horde[i].setName(name); 
    }

    return horde;  // Return pointer to the first zombie
}
