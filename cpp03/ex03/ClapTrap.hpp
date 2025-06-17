/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:39:16 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 09:05:29 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected:  
    std::string name;
    unsigned int hitsPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    //  Default Constructor
    ClapTrap();
    
    //  string contructor
    ClapTrap(const std::string& name);
    
    //  Copy Constructor
    ClapTrap(const ClapTrap& other);
    
    // Copy Assignment Operator
    ClapTrap& operator=(const ClapTrap& other);
    
    // Destructor
    virtual ~ClapTrap();  
    
    // Member functions
    virtual void attack(const std::string& target);  // for overriding purpose
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