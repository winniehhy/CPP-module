#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
    brain = new Brain();
    // Set some dog-specific ideas
    brain->setIdea(0, "I love bones!");
    brain->setIdea(1, "Squirrel!");
    brain->setIdea(2, "Walk time?");
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain); // Deep copy
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain); // Deep copy
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}