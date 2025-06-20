#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() : type("Wrong Generic Animal") {
    std::cout << " WrongAnimal default constructor called" << std::endl;
}

// Parameterized constructor
WrongAnimal::WrongAnimal(const std::string& animalType) : type(animalType) {
    std::cout << " WrongAnimal parameterized constructor called " << animalType << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called  " << type << std::endl;
}

// Assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

// Non-virtual destructor
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called " << type << std::endl;
}

// Non-virtual makeSound function
void WrongAnimal::makeSound() const {
    std::cout << "🔊 Wrong generic animal makes wrong sound..." << std::endl;
}


const std::string& WrongAnimal::getType() const {
    return type;
}
