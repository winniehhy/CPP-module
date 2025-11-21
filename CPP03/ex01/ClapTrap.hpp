/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:39:33 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 12:34:18 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>


/*
Private Members
- Only accessible within the same class
- Not accessible by derived classes (child classes)

Protected Members
- Accessible within the same class and derived classes
- Allows inheritance while maintaining encapsulation

when child class inherits from parent class, it can access protected members of the parent class.

Virtual functions enable polymorphism in C++
Polymorphism = same function name (attack), different behaviors
*/

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