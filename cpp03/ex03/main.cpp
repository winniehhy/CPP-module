/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:48:28 by hheng             #+#    #+#             */
/*   Updated: 2025/05/25 21:04:56 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "=== ClapTrap Tests ===" << std::endl;
    ClapTrap robot1("Robot1");
    robot1.getStatus();
    robot1.setDamage(3);
    robot1.attack("Target");
    
    std::cout << "\n=== ScavTrap Tests ===" << std::endl;
    ScavTrap scav1("Scavenger");
    scav1.getStatus();
    scav1.attack("Enemy");
    scav1.guardGate();
    
    std::cout << "\n=== FragTrap Tests ===" << std::endl;
    FragTrap frag1("Exploder");
    frag1.getStatus();
    frag1.attack("Target");
    frag1.highFivesGuys();
    
    std::cout << "\n=== DiamondTrap Tests ===" << std::endl;
    DiamondTrap diamond1("Diamond");
    DiamondTrap diamond2("Hybrid");
    
    diamond1.getStatus();
    diamond2.getStatus();
    
    std::cout << "Diamond1 HP: " << diamond1.getHitPoints() << " (should be 100 from FragTrap)" << std::endl;
    std::cout << "Diamond1 Energy: " << diamond1.getEnergyPoints() << " (should be 50 from ScavTrap)" << std::endl;
    std::cout << "Diamond1 Damage: " << diamond1.getDamage() << " (should be 30 from FragTrap)" << std::endl;
    
    diamond1.attack("Enemy");
    diamond2.takeDamage(diamond1.getDamage());
    
    diamond1.guardGate();
    diamond1.highFivesGuys();
    diamond1.whoAmI();
    diamond2.whoAmI();
    diamond2.beRepaired(20);
    diamond1.getStatus();
    diamond2.getStatus();
    
    std::cout << "\n=== Mixed Inheritance Combat ===" << std::endl;
    
    ClapTrap basic("Basic");
    ScavTrap guard("Guard");  
    FragTrap bomber("Bomber");
    DiamondTrap ultimate("Ultimate");
    
    basic.getStatus();
    guard.getStatus();
    bomber.getStatus();
    ultimate.getStatus();
    ultimate.attack("Basic");
    basic.takeDamage(ultimate.getDamage());
    
    ultimate.guardGate();
    ultimate.highFivesGuys();
    ultimate.whoAmI();
    
    std::cout << "\n=== End of Tests (Destruction Order) ===" << std::endl;
    
    return 0;
}