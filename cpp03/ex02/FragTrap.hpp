/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 06:42:02 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 06:42:02 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // Default Constructor
    FragTrap();
    
    // String Constructor
    FragTrap(const std::string& name);
    
    // Copy Constructor
    FragTrap(const FragTrap& other);
    
    // Copy Assignment Operator
    FragTrap& operator=(const FragTrap& other);
    
    // Destructor
    ~FragTrap();
    
    // Override attack function
    void attack(const std::string& target);
    
    // Special ability
    void highFivesGuys(void);
};

#endif