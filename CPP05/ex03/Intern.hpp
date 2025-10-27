#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern {
private:
    struct FormData {
        std::string name;
        AForm* (*createFunc)(const std::string&);
    };
    
    static FormData formCreators[3];

public:
    // OCF
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    
    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    // Helper function to create forms
    static AForm* createShrubberyForm(const std::string& target);
    static AForm* createRobotomyForm(const std::string& target);
    static AForm* createPresidentialForm(const std::string& target);
};

#endif
