#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>


static const char* YELLOW = "\033[1;33m"; 
static const char* RED = "\033[1;31m"; 
static const char* RESET = "\033[0m";


int main() {
    std::cout << "=== Testing Intern Class ===" << std::endl;
    
    try {
        //std::srand(static_cast<unsigned int>(std::time(NULL)));
       
        Bureaucrat bureaucrat("John", 5);
        Intern someRandomIntern;
        
    std::cout << std::endl << YELLOW << "1. Testing valid form creation:" << RESET << std::endl;
        
        // Test creating different forms
        AForm* rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            bureaucrat.signForm(*rrf);
            bureaucrat.executeForm(*rrf);
            delete rrf;
        }
        
    std::cout << std::endl << YELLOW << "2. Testing shrubbery form:" << RESET << std::endl;
        AForm* scf = someRandomIntern.makeForm("Shrubbery creation", "garden");
        if (scf) {
            std::cout << *scf << std::endl;
            bureaucrat.signForm(*scf);
            bureaucrat.executeForm(*scf);
            delete scf;
        }
        
    std::cout << std::endl << YELLOW << "3. Testing presidential pardon:" << RESET << std::endl;
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (ppf) {
            std::cout << *ppf << std::endl;
            bureaucrat.signForm(*ppf);
            bureaucrat.executeForm(*ppf);
            delete ppf;
        }
        
    std::cout << std::endl << YELLOW << "4. Testing invalid form name:" << RESET << std::endl;
        AForm* invalid = someRandomIntern.makeForm("invalid form", "target");
        if (invalid) {
            delete invalid;
        }
        
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << RED << e.what() << RESET << std::endl;
    }
    
    return 0;
}
