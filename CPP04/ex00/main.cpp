#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testPolymorphism() {
    
    const Animal* meta = new Animal();
    const Dog* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout  << meta->getType() << std::endl;
    std::cout  << j->getType() << std::endl;
    std::cout  << i->getType() << std::endl;
    
   // std::cout << "\n🔹 Testing makeSound() " << std::endl;
   // std::cout << "Generic animal sound: ";
    meta->makeSound();
    //std::cout << "Dog sound: ";
    j->makeSound();
    //std::cout << "Cat sound: ";
    i->makeSound();
 
    std::cout << "\n🔹 Cleaning up (destructor calls):" << std::endl;
    delete meta;
    delete j;
    delete i;
}

void testWrongPolymorphism() {
    
    std::cout << "\n🔹 Creating wrong animals using base class pointers:" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "\n🔹 Testing getType():" << std::endl;
    std::cout << "wrongCat->getType(): " << wrongCat->getType() << std::endl;
    std::cout << "wrongMeta->getType(): " << wrongMeta->getType() << std::endl;
    
    std::cout << "\n🔹 Testing makeSound() - Should call base class version (WRONG!):" << std::endl;
    wrongCat->makeSound(); // will output WrongAnimal sound, not WrongCat!
    wrongMeta->makeSound();
    
    std::cout << "\n🔹 Cleaning up wrong animals:" << std::endl;
    delete wrongMeta;
    delete wrongCat;
}



int main() {
    
    // Test 1: Basic polymorphism (required test)
    testPolymorphism();
    
    // Test 2: Wrong behavior demonstration
    testWrongPolymorphism();
    
    
    
    // std::cout << "✅ All tests finished successfully!" << std::endl;
    
    return 0;
}