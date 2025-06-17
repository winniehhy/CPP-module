/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 06:42:19 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 06:42:19 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
FragTrap inherits from ClapTrap
- HP: 100, Energy: 100, Attack: 30
- Different construction/destruction messages
- Override attack function with different message
- Add highFivesGuys() special ability
*/

// Default constructor
FragTrap::FragTrap() : ClapTrap() {
    // Override the inherited values with FragTrap specific values
    hitsPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "< FragTrap > default constructor called for " << name << std::endl;
}

// String constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    // Override the inherited values with FragTrap specific values
    hitsPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "< FragTrap > string constructor called for " << name << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "< FragTrap > copy constructor called for " << name << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "< FragTrap > copy assignment operator called" << std::endl;
    
    if (this != &other) {
        ClapTrap::operator=(other);  // Call base class assignment operator
    }
    return *this;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "< FragTrap > destructor called for " << name << std::endl;
}

// Override attack function
void FragTrap::attack(const std::string& target) {
    if (hitsPoints == 0) {
        std::cout << "< FragTrap > " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "< FragTrap > " << name << " has no energy left to attack!" << std::endl;
        return;
    }
    
    // Perform attack with FragTrap specific message
    energyPoints--;
    std::cout << "< FragTrap > " << name << " explosively attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

// Special ability
void FragTrap::highFivesGuys(void) {
    std::cout << "< FragTrap > " << name << " requests a positive high-five! ✋" << std::endl;
}