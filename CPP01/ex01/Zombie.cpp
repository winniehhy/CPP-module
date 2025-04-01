/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:44:30 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 09:51:02 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructor without parameters
Zombie::Zombie() : _name("") {
    std::cout << "Zombie created without a name" << std::endl;
}

// Constructor with name parameter
Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie " << _name << " created" << std::endl;
}

// Destructor
Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

// Announce method
void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Set name method (used by zombieHorde)
void Zombie::setName(std::string name) {
    _name = name;
}