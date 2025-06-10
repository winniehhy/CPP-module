/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:39:59 by hheng             #+#    #+#             */
/*   Updated: 2025/06/10 17:21:24 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;

    // set up a dynamic array of Zombie objects on heap with empty
    Zombie* array = new Zombie[N];

    // Assign names using the constructor
    for (int i = 0; i < N; i++) {
        array[i].setName(name); 
    }

    return array;  // Return pointer to the first zombie
}
