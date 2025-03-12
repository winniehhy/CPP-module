/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:23:33 by hheng             #+#    #+#             */
/*   Updated: 2025/03/12 13:42:48 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie " << this->_name << " created" << std::endl;
}

// Destructor
Zombie::~Zombie() {
    std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
}

// Announce method
void Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}