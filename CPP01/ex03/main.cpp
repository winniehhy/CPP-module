/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:00:37 by hheng             #+#    #+#             */
/*   Updated: 2025/04/03 15:55:26 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

//human A always have weapon  -- using reference
//human B can to have / no weapon -- using pointer
// Jim only hold the club address

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim"); //weapon default = null
		jim.setWeapon(club); //make Jim's weapon pointer point to the same club object.
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
return 0;
}
