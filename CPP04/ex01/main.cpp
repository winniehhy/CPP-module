#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testDeepCopy() {
    std::cout << "\n=== TESTING DEEP COPY ===" << std::endl;
    
    // Test Dog deep copy
    std::cout << "\n--- Testing Dog Deep Copy ---" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Original dog idea");
    
    Dog copiedDog = originalDog; // Copy constructor --create new Dog object
    copiedDog.getBrain()->setIdea(0, "Copied dog idea"); //change idea in index 0 
    std::cout << "Original dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Brain addresses same? " << (originalDog.getBrain() == copiedDog.getBrain() ? "YES" : "NO") << std::endl;
     std::cout << "Original dog brain address: " << originalDog.getBrain() << std::endl;
    std::cout << "Copied dog brain address: " << copiedDog.getBrain() << std::endl;

    // Test Cat deep copy
    std::cout << "\n--- Testing Cat Deep Copy ---" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Original cat idea");
    
    Cat copiedCat;
    copiedCat = originalCat; // Assignment operator
    copiedCat.getBrain()->setIdea(0, "Copied cat idea");
    
    std::cout << "Original cat idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied cat idea: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Brain addresses same? " << (originalCat.getBrain() == copiedCat.getBrain() ? "YES" : "NO") << std::endl;
    std::cout << "Original cat brain address: " << originalCat.getBrain() << std::endl;
    std::cout << "Copied cat brain address: " << copiedCat.getBrain() << std::endl;
}

void testPolymorphism() {
    std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\nCalling makeSound() polymorphically:" << std::endl;
    j->makeSound();
    i->makeSound();
    
    std::cout << "\nDeleting through base class pointers:" << std::endl;
    delete j; // should not create a leak
    delete i;
}

int main() {
    std::cout << "=== ANIMAL BRAIN EXERCISE ===" << std::endl;
    
    // Test basic functionality first
    testPolymorphism();
    
    // Test deep copy functionality
    testDeepCopy();
    
    std::cout << "\n=== SUBJECT ARRAY TEST ===" << std::endl;
    
    const int ARRAY_SIZE = 4;
    Animal* animals[ARRAY_SIZE]; // Create an array of Animal* (pointers):
    
    // Fill half with dogs, half with cats
    std::cout << "\nCreating array of animals:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i < ARRAY_SIZE / 2) {
            std::cout << "\nCreating Dog " << i << ":" << std::endl;
            animals[i] = new Dog();
        } else {
            std::cout << "\nCreating Cat " << i << ":" << std::endl;
            animals[i] = new Cat();
        }
    }
    
    std::cout << "\n--- Testing polymorphic behavior ---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }


    
    // Delete them through the base class pointer, if animal desctructor is virtual
    std::cout << "\n--- Deleting all animals ---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "\nDeleting Animal " << i << ":" << std::endl;
        delete animals[i];
    }

    std::cout << "\n=== PROGRAM COMPLETED ===" << std::endl;
    return 0;


}