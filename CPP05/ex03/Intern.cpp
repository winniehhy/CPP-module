#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Initialize static array of form creators
Intern::FormData Intern::formCreators[3] = {
    {"shrubbery creation", Intern::createShrubberyForm},
    {"robotomy request", Intern::createRobotomyForm},
    {"presidential pardon", Intern::createPresidentialForm}
};

// Default constructor
Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other; // Suppress unused parameter warning
}

// Copy assignment operator
Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other; // Suppress unused parameter warning
    return *this;
}

// Destructor
Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

// Main makeForm function using array of function pointers
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    // Convert form name to lowercase for case-insensitive comparison
    std::string lowerFormName = formName;
    for (size_t i = 0; i < lowerFormName.length(); i++) {
        if (lowerFormName[i] >= 'A' && lowerFormName[i] <= 'Z') {
            lowerFormName[i] = lowerFormName[i] - 'A' + 'a';
        }
    }
    
    // Use array of function pointers instead of if/else chain
    for (int i = 0; i < 3; i++) {
        if (lowerFormName == formCreators[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i].createFunc(target);
        }
    }
    
    std::cout << "Error: Form name '" << formName << "' doesn't exist!" << std::endl;
    return NULL;
}

// Helper functions to create specific forms
AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}
