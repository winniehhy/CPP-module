/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:00:18 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:00:20 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string _name;
    Weapon* _weapon;  // Using a pointer because HumanB might not always have a weapon

public:
    HumanB(std::string name);
    ~HumanB();
    
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif