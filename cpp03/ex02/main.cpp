/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:52:15 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 06:45:22 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void)
{
    std::cout << "=== ClapTrap OCF Initialization ===" << std::endl;

    // ClapTrap OCF test
    ClapTrap bob; 
    ClapTrap dragon("Dragon"); 
    ClapTrap dragonClone(dragon);  // Copy constructor
    ClapTrap bobClone;    
    bobClone = bob;               // Assignment operator

    std::cout << "\n=== ScavTrap OCF Initialization ===" << std::endl;
    
    // ScavTrap OCF test - Notice construction/destruction chaining
    ScavTrap alice("Alice");
    ScavTrap john("John");
    ScavTrap aliceClone(alice);   // Copy constructor
    ScavTrap johnClone;
    johnClone = john;             // Assignment operator

    std::cout << "\n=== FragTrap OCF Initialization ===" << std::endl;
    
    // FragTrap OCF test - Notice construction/destruction chaining
    FragTrap max("Max");
    FragTrap zoe("Zoe");
    FragTrap maxClone(max);       // Copy constructor
    FragTrap zoeClone;
    zoeClone = zoe;               // Assignment operator

    std::cout << "\n=== Initial Status Check ===" << std::endl;
    
    // Show ClapTrap stats
    std::cout << "ClapTrap Stats:" << std::endl;
    bob.getStatus();
    dragon.getStatus();
    
    // Show ScavTrap stats
    std::cout << "\nScavTrap Stats:" << std::endl;
    alice.getStatus();
    john.getStatus();
    
    // Show FragTrap stats
    std::cout << "\nFragTrap Stats:" << std::endl;
    max.getStatus();
    zoe.getStatus();

    std::cout << "\n=== Setting Up Stats ===" << std::endl;
    
    // Set up ClapTrap stats
    bob.setAttackDamage(4);
    dragon.setAttackDamage(5);
    // ScavTrap already has attack damage of 20
    // FragTrap already has attack damage of 30

    std::cout << "\n=== ClapTrap Battle ===" << std::endl;
    
    bob.attack("Dragon");
    dragon.takeDamage(bob.getAttackDamage());
    
    dragon.attack("Bob");
    bob.takeDamage(dragon.getAttackDamage());

    std::cout << "\n=== ScavTrap Battle ===" << std::endl;
    
    alice.attack("John");
    john.takeDamage(alice.getAttackDamage());
    
    john.attack("Alice");
    alice.takeDamage(john.getAttackDamage());

    std::cout << "\n=== FragTrap Battle ===" << std::endl;
    
    max.attack("Zoe");
    zoe.takeDamage(max.getAttackDamage());
    
    zoe.attack("Max");
    max.takeDamage(zoe.getAttackDamage());

    std::cout << "\n=== Special Abilities ===" << std::endl;
    
    // Test ScavTrap special ability
    alice.guardGate();
    john.guardGate();
    aliceClone.guardGate();
    johnClone.guardGate();
    
    // Test FragTrap special ability
    max.highFivesGuys();
    zoe.highFivesGuys();

    std::cout << "\n=== Repair Phase ===" << std::endl;
    
    // Test repairs
    bob.beRepaired(2);
    dragon.beRepaired(3);
    alice.beRepaired(10);
    john.beRepaired(15);
    max.beRepaired(5);
    zoe.beRepaired(8);

    // std::cout << "\n=== Cross-Class Battle ===" << std::endl;
    
    // // ClapTrap vs ScavTrap vs FragTrap
    // std::cout << "Multi-class battle demonstration:" << std::endl;
    
    // ClapTrap weakBot("WeakBot ");
    // ScavTrap mediumBot("MediumBot");
    // FragTrap strongBot("StrongBot");
    
    // weakBot.setAttackDamage(3);
    
    // std::cout << "Before cross-battle:" << std::endl;
    // weakBot.getStatus();
    // mediumBot.getStatus();
    // strongBot.getStatus();
    
    // // Round 1: Everyone attacks everyone
    // weakBot.attack("MediumBot");
    // mediumBot.takeDamage(weakBot.getAttackDamage());
    
    // mediumBot.attack("StrongBot");
    // strongBot.takeDamage(mediumBot.getAttackDamage());
    
    // strongBot.attack("WeakBot");
    // weakBot.takeDamage(strongBot.getAttackDamage());
    
    // std::cout << "After cross-battle:" << std::endl;
    // weakBot.getStatus();
    // mediumBot.getStatus();
    // strongBot.getStatus();

    std::cout << "\n=== Final Status ===" << std::endl;
    
    std::cout << "ClapTrap Final Stats:" << std::endl;
    bob.getStatus();
    dragon.getStatus();
    
    std::cout << "\nScavTrap Final Stats:" << std::endl;
    alice.getStatus();
    john.getStatus();
    
    std::cout << "\nFragTrap Final Stats:" << std::endl;
    max.getStatus();
    zoe.getStatus();

    std::cout << "\n=== End (Watch destruction order) ===" << std::endl;
    // Destructors will be called in reverse order of construction
    // FragTrap destructor → ClapTrap destructor
    // ScavTrap destructor → ClapTrap destructor
    // ClapTrap destructor
    
    return 0;
}