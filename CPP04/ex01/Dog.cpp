#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "🐕 Dog constructor called" << std::endl;
    brain = new Brain();
    // Set some dog-specific ideas
    brain->setIdea(0, "I love bones!");
    brain->setIdea(1, "Squirrel!");
    brain->setIdea(2, "Walk time?");
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "🐕 Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain); // Deep copy
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "🐕 Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain); // Deep copy
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "🐕 Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "🔊 Woof! Woof! Bark!" << std::endl;
}

/*Get the idea stored at index 0 (the first idea in the array)
Returns: The string stored in ideas[0]
*/
Brain* Dog::getBrain() const {
    return brain;
}