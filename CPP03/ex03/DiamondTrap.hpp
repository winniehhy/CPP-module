/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:39:33 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 18:11:33 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// DiamondTrap inherits from both FragTrap and ScavTrap
// This creates the "diamond problem" - ClapTrap is inherited twice
class DiamondTrap :  public ScavTrap, public FragTrap {
private:
    std::string name;  // DiamondTrap's own name (same variable name as ClapTrap)

public:
    // Default Constructor
    DiamondTrap();
    
    // String Constructor
    DiamondTrap(const std::string& name);
    
    // Copy Constructor
    DiamondTrap(const DiamondTrap& other);
    
    // Copy Assignment Operator
    DiamondTrap& operator=(const DiamondTrap& other);
    
    // Destructor
    ~DiamondTrap();
    
     void attack(const std::string& target);
    
    // Special ability unique to DiamondTrap
    void whoAmI();
};

#endif