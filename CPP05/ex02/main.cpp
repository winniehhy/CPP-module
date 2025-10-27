#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static const char* RED = "\033[1;31m"; //red
static const char* YELLOW = "\033[1;33m"; // yellow
static const char* RESET = "\033[0m";

int main() {
    std::cout << "=== Testing AForm and Concrete Forms ===" << std::endl;
    
    try {
        // Create bureaucrats
        Bureaucrat highGrade("Alice", 5);
        Bureaucrat lowGrade("Bob", 140);
        
    std::cout << std::endl << YELLOW << "1. Testing ShrubberyCreationForm:" << RESET << std::endl;
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;
        
        // Test signing and execution
        highGrade.signForm(shrubbery);
        highGrade.executeForm(shrubbery);
        std::cout << shrubbery << std::endl;
        
    std::cout << std::endl << YELLOW << "2. Testing RobotomyRequestForm:" << RESET << std::endl;
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;
        
        highGrade.signForm(robotomy);
        highGrade.executeForm(robotomy);
        std::cout << robotomy << std::endl;
        
    std::cout << std::endl << YELLOW << "3. Testing PresidentialPardonForm:" << RESET << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        
        highGrade.signForm(pardon);
        highGrade.executeForm(pardon);
        std::cout << pardon << std::endl;
        
    std::cout << std::endl << YELLOW << "4. Testing execution failure (low grade):" << RESET << std::endl;
        lowGrade.executeForm(shrubbery);
        
    std::cout << std::endl << YELLOW << "5. Testing execution failure (unsigned form):" << RESET << std::endl;
        ShrubberyCreationForm unsignedForm("office");
        lowGrade.executeForm(unsignedForm);
        
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << RED << e.what() << RESET << std::endl;
    }
    
    return 0;
}