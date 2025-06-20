#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const std::string& animalType);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal(); // Non-virtual destructor (this is the problem!)

    // no virtual
    void makeSound() const;

    // Getter for type
    const std::string& getType() const;
};

#endif