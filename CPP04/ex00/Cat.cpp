#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal("Cat") {
    std::cout << "🐱 Cat default constructor called " << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "🐱 Cat copy constructor called " << std::endl;
}

// Assignment operator
Cat& Cat::operator=(const Cat& other) {
    std::cout << "🐱 Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// Destructor
Cat::~Cat() {
    std::cout << "🐱 Cat destructor called " << std::endl;
}

// Override makeSound
void Cat::makeSound() const {
    std::cout << "🔊 Meow! Purr purr!" << std::endl;
}

