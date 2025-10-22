#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Intern Class ===" << std::endl;
    
    try {
        // Create bureaucrat and intern
        Bureaucrat bureaucrat("John", 5);
        Intern someRandomIntern;
        
        std::cout << "\n1. Testing valid form creation:" << std::endl;
        
        // Test creating different forms
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            bureaucrat.signForm(*rrf);
            bureaucrat.executeForm(*rrf);
            delete rrf;
        }
        
        std::cout << "\n2. Testing shrubbery form:" << std::endl;
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
        if (scf) {
            std::cout << *scf << std::endl;
            bureaucrat.signForm(*scf);
            bureaucrat.executeForm(*scf);
            delete scf;
        }
        
        std::cout << "\n3. Testing presidential pardon:" << std::endl;
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (ppf) {
            std::cout << *ppf << std::endl;
            bureaucrat.signForm(*ppf);
            bureaucrat.executeForm(*ppf);
            delete ppf;
        }
        
        std::cout << "\n4. Testing invalid form name:" << std::endl;
        AForm* invalid = someRandomIntern.makeForm("invalid form", "target");
        if (invalid) {
            delete invalid;
        }
        
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    return 0;
}
