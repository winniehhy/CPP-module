#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal("Dog") {
    std::cout << "🐕 Dog default constructor called " << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "🐕 Dog copy constructor called" << std::endl;
}

// Assignment operator
Dog& Dog::operator=(const Dog& other) {
    std::cout << "🐕 Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// Destructor
Dog::~Dog() {
    std::cout << "🐕 Dog destructor called ." << std::endl;
}

// Override makeSound
void Dog::makeSound() const {
    std::cout << "🔊 Woof! Woof! Bark!" << std::endl;
}