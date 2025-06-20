/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:52:15 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 17:50:34 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "=== ClapTrap OCF Initialization ===" << std::endl;

    // ClapTrap OCF test
    ClapTrap bob; 
    ClapTrap dragon("Dragon"); 
    ClapTrap dragonClone(dragon);  
    ClapTrap bobClone;    
    bobClone = bob;  

    std::cout << "\n=== ScavTrap OCF Initialization ===" << std::endl;
    
    ScavTrap alice("Alice");
    ScavTrap john("John");
    ScavTrap aliceClone(alice); 
    ScavTrap johnClone;
    johnClone = john;      

    std::cout << "\n=== Initial Status Check ===" << std::endl;
    
    // Show ClapTrap stats
    std::cout << "ClapTrap Stats:" << std::endl;
    bob.getStatus();
    dragon.getStatus();
    
    // Show ScavTrap stats (should have different default values)
    std::cout << "\nScavTrap Stats:" << std::endl;
    alice.getStatus();
    john.getStatus();

    std::cout << "\n=== Setting Up Stats ===" << std::endl;
    
    // Set up ClapTrap stats
    bob.setAttackDamage(4);
    dragon.setAttackDamage(5);
    // ScavTrap already has attack damage of 20

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

    std::cout << "\n=== Pointer ===" << std::endl;

    ClapTrap *c1 = new ClapTrap("Clappy");
    ClapTrap *c2 = new ScavTrap("Scavy");

    c1->attack("Scavy");
    c2->attack("Scavy");

    delete c1;
    delete c2;

    std::cout << "\n=== Special Abilities ===" << std::endl;
    
    // Test ScavTrap special ability
    alice.guardGate();
    john.guardGate();

    std::cout << "\n=== Repair Phase ===" << std::endl;
    
    // Test repairs
    bob.beRepaired(2);
    dragon.beRepaired(3);
    alice.beRepaired(10);
    john.beRepaired(15);

    std::cout << "\n=== Final Status ===" << std::endl;
    
    std::cout << "ClapTrap Final Stats:" << std::endl;
    bob.getStatus();
    dragon.getStatus();
    
    std::cout << "\nScavTrap Final Stats:" << std::endl;
    alice.getStatus();
    john.getStatus();

    std::cout << "\n=== End (Watch destruction order) ===" << std::endl;
    // Destructors will be called in reverse order of construction
    // Last created objects will be destroyed first
    
    return 0;
}