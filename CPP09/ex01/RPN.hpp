#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN {
    private:
        std::stack<double> numbers;
        
        bool isOperator(const std::string& token) const;
        bool isValidNumber(const std::string& token) const;
        double applyOperator(double left, double right, char op);
        void processToken(const std::string& token);

    public:
        RPN();
        RPN(const RPN& src);
        RPN& operator=(const RPN& rhs);
        ~RPN();

        double evaluate(const std::string& input);

        class BadInput : public std::exception {
            public:
                const char* what() const throw();
        };

        class NoResult : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif