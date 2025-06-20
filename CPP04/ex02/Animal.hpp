
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"


// Brain is dynamically allocated using new Brain() when the object is created

class Animal {
protected:
    std::string type;
    Brain* brain; // allow each dog or cat has a Brain

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
