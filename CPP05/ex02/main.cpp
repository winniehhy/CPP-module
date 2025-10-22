#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing AForm and Concrete Forms ===" << std::endl;
    
    try {
        // Create bureaucrats
        Bureaucrat highGrade("Alice", 5);
        Bureaucrat lowGrade("Bob", 150);
        
        std::cout << "\n1. Testing ShrubberyCreationForm:" << std::endl;
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;
        
        // Test signing and execution
        highGrade.signForm(shrubbery);
        highGrade.executeForm(shrubbery);
        
        std::cout << "\n2. Testing RobotomyRequestForm:" << std::endl;
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;
        
        highGrade.signForm(robotomy);
        highGrade.executeForm(robotomy);
        
        std::cout << "\n3. Testing PresidentialPardonForm:" << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        
        highGrade.signForm(pardon);
        highGrade.executeForm(pardon);
        
        std::cout << "\n4. Testing execution failure (low grade):" << std::endl;
        lowGrade.executeForm(shrubbery);
        
        std::cout << "\n5. Testing execution failure (unsigned form):" << std::endl;
        ShrubberyCreationForm unsignedForm("office");
        lowGrade.executeForm(unsignedForm);
        
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    return 0;
}