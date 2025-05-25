/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:39:36 by hheng             #+#    #+#             */
/*   Updated: 2025/05/25 18:50:02 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap robot1("Robot1");
    ClapTrap robot2("Robot2");
    robot1.getStatus();
    robot2.getStatus();
    robot1.setDamage(3);
    robot1.attack("Robot2");
    robot2.takeDamage(robot1.getDamage());
    robot2.beRepaired(2);
    robot1.getStatus();
    robot2.getStatus();
    robot1.attack("Robot2");
    robot2.takeDamage(robot1.getDamage());
    robot2.beRepaired(1);
    robot1.getStatus();
    robot2.getStatus();
    
    return 0;
}
