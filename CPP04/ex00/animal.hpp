/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:09:15 by hheng             #+#    #+#             */
/*   Updated: 2025/06/05 18:09:15 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

/*
 * The virtual keyword is not needed for constructors as they don't support
 * runtime polymorphism. They are responsible for creating instances of a
 * class and are not meant to be overridden
*/

class Animal {
protected:
    std::string type;

public:

    Animal();
    Animal(const std::string& animalType);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    // if without virtual, will always call the base class version
    virtual void makeSound() const;

    const std::string& getType() const;
};

#endif
