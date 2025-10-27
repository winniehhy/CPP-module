#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


static const char* ORANGE = "\033[38;5;208m"; 
static const char* RESET = "\033[0m";

// Initialize static array of form creators
Intern::FormData Intern::formCreators[3] = {
    {"shrubbery creation", Intern::createShrubberyForm},
    {"robotomy request", Intern::createRobotomyForm},
    {"presidential pardon", Intern::createPresidentialForm}
};


Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}


Intern::Intern(const Intern& other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}


Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other; 
    return *this;
}


Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

// write forms in lower case
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string lowerFormName = formName;
    for (size_t i = 0; i < lowerFormName.length(); i++) {
        if (lowerFormName[i] >= 'A' && lowerFormName[i] <= 'Z') {
            lowerFormName[i] = lowerFormName[i] - 'A' + 'a';
        }
    }
    
    //loop to check the three form types
    for (int i = 0; i < 3; i++) {
        if (lowerFormName == formCreators[i].name) {
            std::cout << ORANGE << "Intern creates " << formName << RESET << std::endl;
            return formCreators[i].createFunc(target);
        }
    }
    
    std::cout << ORANGE << "Error: Form name '" << formName << "' doesn't exist!" << RESET << std::endl;
    return NULL;
}


AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}
