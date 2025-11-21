/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:43:29 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 09:18:59 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    hitsPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "{ ScavTrap } default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitsPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "{ ScavTrap } " << name << " is string constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "{ ScavTrap } copy constructor called" << std::endl;
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "{ ScavTrap } copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "{ ScavTrap } " << name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (hitsPoints == 0) {
        std::cout << "{ ScavTrap } " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "{ ScavTrap } " << name << " has no energy left to attack!" << std::endl;
        return;
    }
    
    energyPoints--;
    std::cout << "{ ScavTrap } " << name << " fiercely attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "{ ScavTrap } " << name << " is now in Gate keeper mode!" << std::endl;
}