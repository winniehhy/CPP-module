
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

/*
 * The virtual keyword is not needed for constructors as they don't support
 * runtime polymorphism. They are responsible for creating instances of a
 * class and are not meant to be overridden
 * 
 * 
 * Polymorphism mean = different object classes can respond to the same method (makeSound) call in their own way
 *                   = for reuse function purpose from the base class
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
