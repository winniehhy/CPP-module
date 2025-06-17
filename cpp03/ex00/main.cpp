/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:39:36 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 12:53:07 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=== OCF Initialization ===" << std::endl;

    // Default constructor
    /*
    Fixed a;
    Fixed b(a); 
    Fixed c ;
    
    c = b; 
    */
    ClapTrap bob; 
    ClapTrap dragon("Dragon"); 
    ClapTrap dragonClone(dragon);  
    ClapTrap bobClone;    
    
    bobClone = bob;

    std::cout << "\n=== Game Start: Bob vs Dragon ===" << std::endl;

    bob.getStatus();
    dragon.getStatus();

    // Set up their stats
    std::cout << "\n=== Setting Up Stats ===" << std::endl;
    bob.setAttackDamage(4);
    dragon.setAttackDamage(5);

    // bob.setHealthPoints(0);
    // dragon.setEnergyPoints(2);

    // Show initial status
    bob.getStatus();
    dragon.getStatus();

    std::cout << "\n=== Battle Begins ===" << std::endl;
    bob.attack("Dragon");
    dragon.takeDamage(bob.getAttackDamage());

    std::cout << "\n=== After Bob's Attack ===" << std::endl;
    dragon.attack("Bob");
    bob.takeDamage(dragon.getAttackDamage());

    // Both repair
    std::cout << "\n=== Repair Phase ===" << std::endl;
    bob.beRepaired(2);
    dragon.beRepaired(3);

    // Show final status
    std::cout << "\n=== Final Status ===" << std::endl;
    bob.getStatus();
    dragon.getStatus();

    std::cout << "\n=== Game End ===" << std::endl;

    // ClapTrap destructor called for Bob      ← bobClone (created 4th, destroyed 1st)
    // ClapTrap destructor called for Dragon   ← dragonClone (created 3rd, destroyed 2nd)  
    // ClapTrap destructor called for Dragon   ← dragon (created 2nd, destroyed 3rd)
    // ClapTrap destructor called for Bob      ← bob (created 1st, destroyed 4th)
    return 0;
}