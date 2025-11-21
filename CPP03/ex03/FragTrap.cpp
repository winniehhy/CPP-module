/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:44:06 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 09:10:10 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    hitsPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "< FragTrap > default constructor called!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitsPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "< FragTrap > " << name << " is assembled!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "< FragTrap > copy constructor called" << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "< FragTrap > copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "< FragTrap > " << name << " is disassembled!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    // Check if FragTrap can attack (has hit points and energy)
    if (hitsPoints == 0) {
        std::cout << "< FragTrap > " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "< FragTrap > " << name << " has no energy left to attack!" << std::endl;
        return;
    }
    
    energyPoints--;
    std::cout << "< FragTrap > " << name << " explosively attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "< FragTrap > " << name << " requests a high five! ✋" << std::endl;
}