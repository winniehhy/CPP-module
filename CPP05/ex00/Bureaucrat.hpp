#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
   // default constructor
    Bureaucrat();
    
    // Parameterized constructor
    Bureaucrat(const std::string& name, int grade);
    
    // Copy constructor
    Bureaucrat(const Bureaucrat& other);
    
    // Copy assignment operator
    Bureaucrat& operator=(const Bureaucrat& other);
    
    // Destructor
    ~Bureaucrat();

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Grade modification functions
    void incrementGrade();
    void decrementGrade();

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

private:
    void validateGrade(int grade) const;
};


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif 