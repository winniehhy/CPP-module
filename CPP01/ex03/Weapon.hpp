/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:59:18 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 09:59:21 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string _type;

public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    
    const std::string& getType() const;
    void setType(std::string newType);
};

#endif