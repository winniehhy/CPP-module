/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:04:00 by hheng             #+#    #+#             */
/*   Updated: 2025/06/05 18:04:00 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() : type("Generic Animal") {
    std::cout << "Animal default constructor called " << std::endl;
}

// Parameterized constructor
Animal::Animal(const std::string& animalType) : type(animalType) {
    std::cout << "Animal parameterized constructor called  " << animalType << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called " << type << std::endl;
}

// Assignment operator
Animal& Animal::operator=(const Animal& other) {
    std::cout <<" Animal assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called " << type << std::endl;
}

// Virtual makeSound function
void Animal::makeSound() const {
    std::cout << "🔊 Generic animal makes some sound..." << std::endl;
}

const std::string& Animal::getType() const {
    return type;
}