/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:39:33 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 06:33:29 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string name;
    unsigned int hitsPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    
    //  Default Constructor
    ClapTrap();
    
    //  Parameterized Constructor (not part of OCF but needed for functionality)
    ClapTrap(const std::string& name);
    
    //  Copy Constructor
    ClapTrap(const ClapTrap& other);
    
    // Copy Assignment Operator
    ClapTrap& operator=(const ClapTrap& other);
    
    // Destructor
    ~ClapTrap();
    
    // Member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    // Getter functions
    unsigned int getHitsPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
    std::string getName() const;
    
    void getStatus() const;
    void setAttackDamage(unsigned int damage);
    void setHitsPoints(unsigned int hp);
    void setEnergyPoints(unsigned int ep);
};

#endif