/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:47:47 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 18:14:13 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap() : ClapTrap(),  ScavTrap(), FragTrap(), name("Default") {
    std::cout << "( DiamondTrap ) default constructor called" << std::endl;
    
    // Set stats according to requirements:
    // Hit points from FragTrap (100), Energy from ScavTrap (50), Attack damage from FragTrap (30)
    this->hitsPoints = 100;      // FragTrap's HP
    this->energyPoints = 50;     // ScavTrap's Energy
    this->attackDamage = 30;     // FragTrap's Attack Damage
}

// String Constructor
DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
    std::cout << "( DiamondTrap ) string constructor called for " << name << std::endl;
    
    // Set stats according to requirements:
    // Hit points from FragTrap (100), Energy from ScavTrap (50), Attack damage from FragTrap (30)
    this->hitsPoints = 100;      // FragTrap's HP
    this->energyPoints = 50;     // ScavTrap's Energy  
    this->attackDamage = 30;     // FragTrap's Attack Damage
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "( DiamondTrap ) copy constructor called" << std::endl;
}

// Copy Assignment Operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "( DiamondTrap ) copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "( DiamondTrap ) destructor called for " << this->name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    FragTrap::attack(target);
}

// Special ability - shows both DiamondTrap name and ClapTrap name
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}