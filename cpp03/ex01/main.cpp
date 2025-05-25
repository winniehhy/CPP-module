/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:52:15 by hheng             #+#    #+#             */
/*   Updated: 2025/05/25 18:55:40 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "=== ClapTrap Tests ===" << std::endl;
    ClapTrap robot1("Robot1");
    ClapTrap robot2("Robot2");
    
    // Show initial status
    robot1.getStatus();
    robot2.getStatus();
    
    // Set damage for robot1
    robot1.setDamage(3);
    
    // Robot1 attacks Robot2
    robot1.attack("Robot2");
    robot2.takeDamage(robot1.getDamage());
    
    // Robot2 repairs itself
    robot2.beRepaired(2);
    
    // Show status after first round
    robot1.getStatus();
    robot2.getStatus();
    
    std::cout << "\n=== ScavTrap Tests ===" << std::endl;
    
    // Test ScavTrap construction (should show ClapTrap -> ScavTrap construction)
    ScavTrap scav1("Scavenger");
    ScavTrap scav2("Guardian");
    
    // Show initial status
    scav1.getStatus();
    scav2.getStatus();
    
    // Test ScavTrap attack (different message)
    scav1.attack("Enemy");
    scav2.takeDamage(scav1.getDamage());
    
    // Test special ability
    scav1.guardGate();
    scav2.guardGate();
    
    // Test repair
    scav2.beRepaired(10);
    
    // Show final status
    scav1.getStatus();
    scav2.getStatus();
    
    std::cout << "\n=== End of Tests (Destruction Order) ===" << std::endl;
    
    return 0;
}