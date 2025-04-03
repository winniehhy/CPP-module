/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:04:33 by hheng             #+#    #+#             */
/*   Updated: 2025/04/03 14:49:36 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("") {
}

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << "Zombie " << name << " created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    _name = name;
}