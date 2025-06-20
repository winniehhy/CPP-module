#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

/*
Abstract class = A class that cannot be instantiated directly ( Instantiate means to create an object from a class.)

make the Animal class abstract, which means:
- > You can inherit from it, but you cannot create an instance of it directly.

*/

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const std::string& animalType);
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    // Pure virtual function - makes this class abstract == 0 , means no implementation
    virtual void makeSound() const = 0;
    const std::string& getType() const;
};

#endif