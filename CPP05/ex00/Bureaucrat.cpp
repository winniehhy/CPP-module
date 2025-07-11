#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    validateGrade(grade);
    _grade = grade;
    std::cout << "Bureaucrat " << _name << " constructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other) {
        // Note: _name is const, so we can't assign to it
        // In a real scenario, you might need to handle this differently
        // or make name non-const if assignment needs to change the name
        _grade = other._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << _name << " destructor called" << std::endl;
}

// Getters
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Grade validation
void Bureaucrat::validateGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Increment grade (lower number = higher grade)
void Bureaucrat::incrementGrade() {
    validateGrade(_grade - 1);
    _grade--;
    std::cout << _name << " has been promoted to grade " << _grade << std::endl;
}

// Decrement grade (higher number = lower grade)
void Bureaucrat::decrementGrade() {
    validateGrade(_grade + 1);
    _grade++;
    std::cout << _name << " has been demoted to grade " << _grade << std::endl;
}

// Exception implementations
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Stream insertion operator (non-member function)
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}