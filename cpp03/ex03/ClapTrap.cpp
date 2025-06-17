/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:38:53 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 09:05:01 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// default constructor
ClapTrap::ClapTrap() 
    : name("Bob"), hitsPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "[ ClapTrap ] default constructor called for " << name << std::endl;
}

//string constructor
ClapTrap::ClapTrap(const std::string& name) 
    : name(name), hitsPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "[ ClapTrap ] string constructor called  " << name <<  std::endl;
}

//Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other) 
    : name(other.name), hitsPoints(other.hitsPoints), 
      energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "[ ClapTrap ] copy constructor called for " << name << std::endl;
}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "[ ClapTrap ] copy assignment operator called" << std::endl;
    
    // Self-assignment check
    if (this != &other) {
        name = other.name;
        hitsPoints = other.hitsPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "[ ClapTrap ] destructor called for " << name << std::endl;
}

// Attack function
/*
- if HP = 0 , dead and cannot attack
- if EP = 0, no energy points (power) left to attack
- whenever bob attack, EP (power)--
*/
void ClapTrap::attack(const std::string& target) {
    if (hitsPoints == 0) {
        std::cout << "[ ClapTrap ] " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "[ ClapTrap ]" << name << " has no energy points left to attack!" << std::endl;
        return;
    }
    
    energyPoints--;
    std::cout << "[ ClapTrap ] " << name << " attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

// Take damage (hurt level) function
/*
- if amount (damage > HP), HP = 0, dead
- else (damage < HP), deduct BP -= amount
*/
void ClapTrap::takeDamage(unsigned int amount) {
    if (hitsPoints == 0) {
        std::cout << "[ ClapTrap ] " << name << " is already dead!" << std::endl;
        return;
    }
    
    if (amount >= hitsPoints) {
        hitsPoints = 0;
        std::cout << "[ ClapTrap ] " << name << " gets " << amount 
                  << " points of damage and dies!" << std::endl;
    } else {
        hitsPoints -= amount;
        std::cout << "[ ClapTrap ] " << name << " kena " << amount 
                  << " points of damage! HP remaining: " << hitsPoints << std::endl;
    }
}

// Repair function
/*
- each repair costs 1 energy point (EP)
*/
void ClapTrap::beRepaired(unsigned int amount) {
    if (hitsPoints == 0) {
        std::cout << "[ ClapTrap ] " << name << " is dead and cannot be repaired!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "[ ClapTrap ] " << name << " has no energy points left to repair!" << std::endl;
        return;
    }
    
    energyPoints--;
    hitsPoints += amount;
    std::cout << "[ ClapTrap ] " << name << " repairs itself for " << amount 
              << " heath point! Current HP: " << hitsPoints << std::endl;
}

// Getter functions
unsigned int ClapTrap::getHitsPoints() const { 
    return hitsPoints; 
}

unsigned int ClapTrap::getEnergyPoints() const { 
    return energyPoints; 
}

unsigned int ClapTrap::getAttackDamage() const { 
    return attackDamage; 
}

std::string ClapTrap::getName() const { 
    return name; 
}

//setter
void ClapTrap::setAttackDamage(unsigned int damage) {
    attackDamage = damage;
    std::cout << "[ ClapTrap ] " << name << " attack damage set to " << damage << std::endl;
}

void ClapTrap::setHitsPoints(unsigned int hp) {
    hitsPoints = hp;
}

void ClapTrap::setEnergyPoints(unsigned int ep) {
    energyPoints = ep;
}


void ClapTrap::getStatus() const {
    std::cout << "[ ClapTrap ] " << name << " - HP: " << hitsPoints 
              << "| Energy (Power) point: " << energyPoints << "| Attack Damage: " << attackDamage << std::endl;
}

