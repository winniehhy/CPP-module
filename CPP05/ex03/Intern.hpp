#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern {
private:
    // Structure to hold form creation data
    struct FormData {
        std::string name;
        AForm* (*createFunc)(const std::string&);
    };
    
    // Static array of form creation functions
    static FormData formCreators[3];

public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // Main functionality
    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    // Helper function to create forms
    static AForm* createShrubberyForm(const std::string& target);
    static AForm* createRobotomyForm(const std::string& target);
    static AForm* createPresidentialForm(const std::string& target);
};

#endif
