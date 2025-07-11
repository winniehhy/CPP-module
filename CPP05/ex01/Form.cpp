#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Form default constructor called" << std::endl;
}

// Parameterized constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
    std::cout << "Form " << _name << " constructor called" << std::endl;
}

// Copy constructor
Form::Form(const Form& other) 
    : _name(other._name), _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Form copy constructor called" << std::endl;
}

// Copy assignment operator
Form& Form::operator=(const Form& other) {
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other) {
        // Note: const members cannot be assigned
        _isSigned = other._isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {
    std::cout << "Form " << _name << " destructor called" << std::endl;
}

// Getters
const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// Grade validation
void Form::validateGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

// beSigned function
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeToSign) {
        _isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

// Exception implementations
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() 
       << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}