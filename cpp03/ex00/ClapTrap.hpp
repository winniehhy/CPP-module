/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:39:33 by hheng             #+#    #+#             */
/*   Updated: 2025/05/25 18:48:45 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    // Constructor
    ClapTrap(const std::string& name);
    
    // Destructor
    ~ClapTrap();
    
    // Public member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    // Getter functions
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getDamage() const;
    std::string getName() const;
    
    // Additional functions for testing
    void getStatus() const;
    void setDamage(unsigned int damage);
};

#endif