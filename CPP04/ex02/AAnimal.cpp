#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "🐰 AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& animalType) : type(animalType) {
    std::cout << "🐰 AAnimal parameterized constructor called for " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "🐰 AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "🐰 AAnimal assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "🐰 AAnimal destructor called for " << type << std::endl;
}

const std::string& AAnimal::getType() const {
    return type;
}