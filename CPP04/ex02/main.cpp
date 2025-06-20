#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testAbstractClass() {
    std::cout << "\n=== TESTING ABSTRACT CLASS ===" << std::endl;
    
    // This would cause a compilation error:
    //AAnimal animal; // ERROR: Cannot instantiate abstract class

     // But  CAN create derived class objects:
    // Dog dog;
    // Cat cat;

    // // ✅ Call makeSound() directly on derived objects:
    // std::cout << "Dog says: ";
    // dog.makeSound();   
    
    // std::cout << "Cat says: ";
    // cat.makeSound();       

    std::cout << "✓ AAnimal cannot be instantiated directly (abstract class)" << std::endl;
    std::cout << "✓ But we can use AAnimal* pointers for polymorphism" << std::endl;
}

void testDeepCopy() {
    std::cout << "\n=== TESTING DEEP COPY ===" << std::endl;
    
    // Test Dog deep copy
    std::cout << "\n--- Testing Dog Deep Copy ---" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Original dog idea");
    
    Dog copiedDog = originalDog; // Copy constructor
    copiedDog.getBrain()->setIdea(0, "Copied dog idea");
    
    std::cout << "Original dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Brain addresses different? " << (originalDog.getBrain() != copiedDog.getBrain() ? "YES" : "NO") << std::endl;
    
    // Test Cat deep copy
    std::cout << "\n--- Testing Cat Deep Copy ---" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Original cat idea");
    
    Cat copiedCat;
    copiedCat = originalCat; // Assignment operator
    copiedCat.getBrain()->setIdea(0, "Copied cat idea");
    
    std::cout << "Original cat idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied cat idea: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Brain addresses different? " << (originalCat.getBrain() != copiedCat.getBrain() ? "YES" : "NO") << std::endl;
}

void testPolymorphism() {
    std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
    
    const AAnimal* j = new Dog(); //Dog is an instance that created from AAnimal
    const AAnimal* i = new Cat();
    
    std::cout << "\nCalling makeSound() polymorphically:" << std::endl;
    j->makeSound(); // Calls Dog::makeSound() - pure virtual forces implementation
    i->makeSound(); // Calls Cat::makeSound() - pure virtual forces implementation
    
    std::cout << "\nDeleting through base class pointers:" << std::endl;
    delete j; // should not create a leak
    delete i;
}

int main() {
    std::cout << "=== ABSTRACT ANIMAL BRAIN EXERCISE ===" << std::endl;
    
    // Test that AAnimal is abstract
    testAbstractClass();
    
    // Test basic functionality first
    testPolymorphism();
    
    // Test deep copy functionality
    testDeepCopy();
    
    std::cout << "\n=== MAIN ARRAY TEST ===" << std::endl;
    
    const int ARRAY_SIZE = 10;
    AAnimal* animals[ARRAY_SIZE];
    
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
        std::cout << "AAnimal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound(); // Each MUST implement makeSound() due to pure virtual
    }
    
    std::cout << "\n--- Deleting all animals ---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "\nDeleting AAnimal " << i << ":" << std::endl;
        delete animals[i];
    }
    
    std::cout << "\n=== ADDITIONAL TESTS ===" << std::endl;
    
    // Test with different array sizes
    std::cout << "\n--- Testing with smaller array ---" << std::endl;
    AAnimal* smallArray[4];
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            smallArray[i] = new Dog();
        } else {
            smallArray[i] = new Cat();
        }
    }
    
    for (int i = 0; i < 4; i++) {
        delete smallArray[i];
    }
    
    std::cout << "\n=== PROGRAM COMPLETED ===" << std::endl;
    return 0;
}

/*
Construction Order:
AAnimal base class constructor
Dog/Cat derived class constructor
Brain member construction

Destruction Order (reverse):
Dog/Cat destructor
Brain destructor
AAnimal base class destructor

*/