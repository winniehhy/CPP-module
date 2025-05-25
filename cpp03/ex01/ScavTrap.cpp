/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:52:04 by hheng             #+#    #+#             */
/*   Updated: 2025/05/25 18:55:05 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    // Override the inherited values with ScavTrap specific values
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " is constructed!" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " is destroyed!" << std::endl;
}

// Override attack function
void ScavTrap::attack(const std::string& target) {
    // Check if ScavTrap can attack (has hit points and energy)
    if (hitPoints == 0) {
        std::cout << "ScavTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ScavTrap " << name << " has no energy left to attack!" << std::endl;
        return;
    }
    
    // Perform attack with ScavTrap specific message
    energyPoints--;
    std::cout << "ScavTrap " << name << " fiercely attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

// Special ability
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}