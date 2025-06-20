/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:48:28 by hheng             #+#    #+#             */
/*   Updated: 2025/06/17 18:03:45 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

/*
ClapTrap : HP : 10 | EP : 10 | Damage : 0
ScavTrap : HP : 100 | EP : 50 | Damage : 20 + guardGate
FragTrap : HP : 100 | EP : 100 | Damage : 30 + highFivesGuys
DiamondTrap : HP : 100 | EP : 50 | Damage : 30 + whoAmI
*/

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
    ScavTrap johnClone; // default constructor (bob)
    johnClone = john;             // Assignment operator

    std::cout << "\n=== FragTrap OCF Initialization ===" << std::endl;
    
    // FragTrap OCF test - Notice construction/destruction chaining
    FragTrap max("Max");
    FragTrap zoe("Zoe");
    FragTrap maxClone(max);       // Copy constructor
    FragTrap zoeClone;
    zoeClone = zoe;               // Assignment operator

    std::cout << "\n=== DiamondTrap OCF Initialization ===" << std::endl;
    
    // DiamondTrap OCF test - Notice virtual inheritance construction/destruction
    DiamondTrap sam("Sam");
    DiamondTrap lee("Lee");
    DiamondTrap samClone(sam);    // Copy constructor
    DiamondTrap leeClone;
    leeClone = lee;               // Assignment operator

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

    // Show DiamondTrap stats
    std::cout << "\nDiamondTrap Stats:" << std::endl;
    sam.getStatus();
    lee.getStatus();

    std::cout << "\n=== DiamondTrap Attribute Verification ===" << std::endl;
    
    // Verify DiamondTrap inherits correct attributes
    std::cout << "Sam HP: " << sam.getHitsPoints() << " (should be 100 from FragTrap)" << std::endl;
    std::cout << "Sam Energy: " << sam.getEnergyPoints() << " (should be 50 from ScavTrap)" << std::endl;
    std::cout << "Sam Damage: " << sam.getAttackDamage() << " (should be 30 from FragTrap)" << std::endl;
    
    std::cout << "Lee HP: " << lee.getHitsPoints() << " (should be 100 from FragTrap)" << std::endl;
    std::cout << "Lee Energy: " << lee.getEnergyPoints() << " (should be 50 from ScavTrap)" << std::endl;
    std::cout << "Lee Damage: " << lee.getAttackDamage() << " (should be 30 from FragTrap)" << std::endl;

    std::cout << "\n=== Setting Up Stats ===" << std::endl;
    
    // Set up ClapTrap stats
    bob.setAttackDamage(4);
    dragon.setAttackDamage(5);
    // ScavTrap already has attack damage of 20
    // FragTrap already has attack damage of 30
    // DiamondTrap already has attack damage of 30

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

    std::cout << "\n=== DiamondTrap Battle ===" << std::endl;
    
    sam.attack("Lee");
    lee.takeDamage(sam.getAttackDamage());
    
    lee.attack("Sam");
    sam.takeDamage(lee.getAttackDamage());

    std::cout << "\n=== Special Abilities ===" << std::endl;
    
    // Test ScavTrap special ability
    alice.guardGate();
    john.guardGate();
    // aliceClone.guardGate();
    // johnClone.guardGate();
    
    // Test FragTrap special ability
    max.highFivesGuys();
    zoe.highFivesGuys();
    // maxClone.highFivesGuys();
    // zoeClone.highFivesGuys();

    // Test DiamondTrap special abilities
    sam.guardGate();      // From ScavTrap
    sam.highFivesGuys();  // From FragTrap
    sam.whoAmI();         // DiamondTrap's own method
    
    lee.guardGate();      // From ScavTrap
    lee.highFivesGuys();  // From FragTrap
    lee.whoAmI();         // DiamondTrap's own method

    //samClone.whoAmI();    // Test copy constructor
    //leeClone.whoAmI();    // Test assignment operator

    std::cout << "\n=== Repair Phase ===" << std::endl;
    
    // Test repairs
    bob.beRepaired(2);
    dragon.beRepaired(3);
    alice.beRepaired(10);
    john.beRepaired(15);
    max.beRepaired(5);
    zoe.beRepaired(8);
    sam.beRepaired(12);
    lee.beRepaired(18);

    // std::cout << "\n=== Cross-Class Battle ===" << std::endl;
    
    // // ClapTrap vs ScavTrap vs FragTrap vs DiamondTrap
    // std::cout << "Multi-class battle demonstration:" << std::endl;
    
    // ClapTrap weakBot("WeakBot");
    // ScavTrap mediumBot("MediumBot");
    // FragTrap strongBot("StrongBot");
    // DiamondTrap ultimateBot("UltimateBot");
    
    // weakBot.setAttackDamage(3);
    
    // std::cout << "Before cross-battle:" << std::endl;
    // weakBot.getStatus();
    // mediumBot.getStatus();
    // strongBot.getStatus();
    // ultimateBot.getStatus();
    
    // // Round 1: Chain attacks
    // weakBot.attack("MediumBot");
    // mediumBot.takeDamage(weakBot.getAttackDamage());
    
    // mediumBot.attack("StrongBot");
    // strongBot.takeDamage(mediumBot.getAttackDamage());
    
    // strongBot.attack("UltimateBot");
    // ultimateBot.takeDamage(strongBot.getAttackDamage());
    
    // ultimateBot.attack("WeakBot");
    // weakBot.takeDamage(ultimateBot.getAttackDamage());
    
    // std::cout << "After cross-battle:" << std::endl;
    // weakBot.getStatus();
    // mediumBot.getStatus();
    // strongBot.getStatus();
    // ultimateBot.getStatus();

    // // Show special abilities
    // mediumBot.guardGate();
    // strongBot.highFivesGuys();
    // ultimateBot.guardGate(); // to prove that diamond can access all
    // ultimateBot.highFivesGuys();
    // ultimateBot.whoAmI();

    std::cout << "\n=== Pointer ===" << std::endl;
    ClapTrap *c1 = new ClapTrap("Clappy");
    ClapTrap *c2 = new ScavTrap("Scavy");
    ClapTrap *c3 = new FragTrap("Fraggy");
    ClapTrap *c4 = new DiamondTrap("Dima");

    c1->attack("Scavy");
    c2->attack("Scavy");
    c3->attack("Clappy");
    c4->attack("Clappy");

    delete c1; 
    delete c2;
    delete c3;
    delete c4; 

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

    std::cout << "\nDiamondTrap Final Stats:" << std::endl;
    sam.getStatus();
    lee.getStatus();

    std::cout << "\n=== OCF Clone Testing ===" << std::endl;
    
    std::cout << "Testing cloned objects:" << std::endl;
    samClone.getStatus();
    leeClone.getStatus();
    samClone.whoAmI();
    leeClone.whoAmI();

    std::cout << "\n=== End (Watch destruction order) ===" << std::endl;
    // Destructors will be called in reverse order of construction
    // DiamondTrap destructor → FragTrap destructor → ScavTrap destructor → ClapTrap destructor (virtual inheritance)
    // FragTrap destructor → ClapTrap destructor
    // ScavTrap destructor → ClapTrap destructor
    // ClapTrap destructor
    
    return 0;
}