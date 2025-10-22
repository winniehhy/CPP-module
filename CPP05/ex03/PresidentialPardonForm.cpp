#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon", 25, 5), _target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm " << _target << " constructor called" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm " << _target << " destructor called" << std::endl;
}

// Execute method
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    std::cout << executor.getName() << " executed " << getName() << std::endl;
}
