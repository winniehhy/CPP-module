/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:59:30 by hheng             #+#    #+#             */
/*   Updated: 2025/04/03 15:32:20 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("") {
}

Weapon::Weapon(std::string type) : _type(type) {
}

Weapon::~Weapon() {
}

//Returns the current weapon type
const std::string& Weapon::getType() const {
    return _type;
}

// Modifies the weapon type dynamically.
void Weapon::setType(std::string newType) {
    _type = newType;
}
