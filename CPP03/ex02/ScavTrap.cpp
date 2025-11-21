/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:52:04 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 06:35:23 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
Inheritance means one class (child class) can reuse the code from another class (parent class).
- override ClapTrap -- contructor, destructor, attack function
- add new guardGate function

When destroying desctructor, it goes in reverse: child gets destroyed first, then the parent.
*/

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {
    // Override the inherited values with ScavTrap specific values
    hitsPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "{ ScavTrap } default constructor called for " << name << std::endl;
}

// string constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    // Override the inherited values with ScavTrap specific values
    hitsPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "{ ScavTrap } string constructor called for " << name << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "{ ScavTrap }ScavTrap copy constructor called for " << name << std::endl;
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "{ ScavTrap } copy assignment operator called" << std::endl;
    
    if (this != &other) {
        ClapTrap::operator=(other);  // Call base class assignment operator
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "{ ScavTrap } destructor called for " << name << std::endl;
}

// Override attack function
void ScavTrap::attack(const std::string& target) {
    if (hitsPoints == 0) {
        std::cout << "{ ScavTrap }" << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "{ ScavTrap } " << name << " has no energy left to attack!" << std::endl;
        return;
    }
    
    // Perform attack with ScavTrap specific message
    energyPoints--;
    std::cout << "{ ScavTrap } " << name << " fiercely attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

// Special ability
void ScavTrap::guardGate() {
    std::cout << "{ ScavTrap } " << name << " is now in Gate keeper mode!" << std::endl;
}