#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "🐱 Cat constructor called" << std::endl;
    brain = new Brain();
    // Set some cat-specific ideas
    brain->setIdea(0, "I need more sleep");
    brain->setIdea(1, "Food bowl is empty!");
    brain->setIdea(2, "Knock things off tables");
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "🐱 Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain); // Deep copy
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "🐱 Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain); // Deep copy
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "🐱 Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "🔊 Meow! Purr purr!" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}