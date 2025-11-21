/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:39:53 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 08:22:33 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// VIRTUAL inheritance prevents diamond problem
class ScavTrap : virtual public ClapTrap {
public:
    // Default Constructor
    ScavTrap();
    
    // String Constructor
    ScavTrap(const std::string& name);
    
    // Copy Constructor
    ScavTrap(const ScavTrap& other);
    
    // Copy Assignment Operator
    ScavTrap& operator=(const ScavTrap& other);
    
    // Destructor
    ~ScavTrap();
    
    // Override attack function
    void attack(const std::string& target);
    
    // Special ability
    void guardGate();
};

#endif