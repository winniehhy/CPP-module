/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:47:47 by hheng             #+#    #+#             */
/*   Updated: 2025/05/25 21:01:40 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
    
    // Set DiamondTrap specific attributes (combination of both parent classes)
    // Hit points from FragTrap (100)
    hitPoints = 100;
    
    // Energy points from ScavTrap (50) 
    energyPoints = 50;
    
    // Attack damage from FragTrap (30)
    attackDamage = 30;
    
    std::cout << "DiamondTrap " << name << " is forged!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " is shattered!" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << name 
              << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}