#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal("Wrong Cat") {
    std::cout << " WrongCat default constructor called " << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called " << std::endl;
}

// Assignment operator
WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << " WrongCat assignment operator called" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

// Destructor
WrongCat::~WrongCat() {
    std::cout << " WrongCat destructor called " << std::endl;
}

// makeSound - won't be called polymorphically
void WrongCat::makeSound() const {
    std::cout << "🔊 Wrong meow! This won't be heard through base pointer!" << std::endl;
}
