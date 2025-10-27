#include "Bureaucrat.hpp"

static const char* RED = "\033[1;31m"; // red
static const char* RESET = "\033[0m";

int main() {
    std::cout << "=== Testing Bureaucrat Class ===" << std::endl;
    
 
    std::cout << "\n1. Testing normal creation and << operator:" << std::endl;
    try {
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;
        
        
        john.incrementGrade();
        std::cout << john << std::endl;
        
        john.decrementGrade();
        std::cout << john << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
    }
    
    
    std::cout << "\n2. Testing constructor exceptions:" << std::endl;
    try {
        Bureaucrat invalid1("Invalid", 0);  // Too high
    } catch (const std::exception& e) {
        std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
    }
    
    try {
        Bureaucrat invalid2("Invalid", 151);  // Too low
    } catch (const std::exception& e) {
        std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
    }
    
 
    std::cout << "\n3. Testing grade modification exceptions:" << std::endl;
    try {
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        alice.incrementGrade(); 
    } catch (const std::exception& e) {
        std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
    }
    
    try {
        Bureaucrat bob("Bob", 150);
        std::cout << bob << std::endl;
        bob.decrementGrade();  
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    
    
    return 0;
}