/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:38:53 by hheng             #+#    #+#             */
/*   Updated: 2025/05/25 21:00:31 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) 
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " is constructed!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    // Check if ClapTrap can attack (has hit points and energy)
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
        return;
    }
    
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return;
    }
    
    if (amount >= hitPoints) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount 
                  << " points of damage and dies!" << std::endl;
    } else {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount 
                  << " points of damage! Hit points: " << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    // Check if ClapTrap can repair (has hit points and energy)
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is dead and cannot be repaired!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " has no energy left to repair!" << std::endl;
        return;
    }
    
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount 
              << " hit points! Current hit points: " << hitPoints << std::endl;
}

unsigned int ClapTrap::getHitPoints() const { return hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return energyPoints; }
unsigned int ClapTrap::getDamage() const { return attackDamage; }
std::string ClapTrap::getName() const { return name; }

void ClapTrap::getStatus() const {
    std::cout << "ClapTrap " << name << " - HP: " << hitPoints 
              << ", Energy: " << energyPoints << ", Damage: " << attackDamage << std::endl;
}

void ClapTrap::setDamage(unsigned int damage) {
    attackDamage = damage;
    std::cout << "ClapTrap " << name << " damage set to " << damage << std::endl;
}
