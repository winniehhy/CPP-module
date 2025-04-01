/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:59:52 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 09:59:55 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
private:
    std::string _name;
    Weapon& _weapon;  // Using a reference because HumanA will always have a weapon

public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    
    void attack() const;
};

#endif