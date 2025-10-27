#include "Bureaucrat.hpp"
#include "Form.hpp"


static const char* RED = "\033[1;31m"; 
static const char* RESET = "\033[0m";

int main() {
    std::cout << "=== Testing Form and Bureaucrat Classes ===" << std::endl;
    

    std::cout << "\n1. Testing Form creation and << operator:" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
        
        Bureaucrat john("John", 40);
        std::cout << john << std::endl;
        
        // Test successful signing
        john.signForm(taxForm);
        std::cout << taxForm << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << RED << e.what() << RESET << std::endl;
    }
    

    std::cout << "\n2. Testing Form constructor exceptions:" << std::endl;
    try {
        Form invalidForm1("Invalid", 0, 50);  // Grade too high
        
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << RED << e.what() << RESET << std::endl;
    }
    
    try {
        Form invalidForm2("Invalid", 50, 151);  // Grade too low
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << RED << e.what() << RESET << std::endl;
    }
    
  
    std::cout << "\n3. Testing signing failure:" << std::endl;
    try {
        Form importantForm("Important Form", 20, 5);
        Bureaucrat lowGradeBureaucrat("Bob", 50);
        
        std::cout << importantForm << std::endl;
        std::cout << lowGradeBureaucrat << std::endl;
        
        lowGradeBureaucrat.signForm(importantForm);
        std::cout << importantForm << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << RED << e.what() << RESET << std::endl;
    }
    
    return 0;
}