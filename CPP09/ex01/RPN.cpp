#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& src) : numbers(src.numbers) {}

RPN& RPN::operator=(const RPN& rhs) {
    if (this != &rhs)
        numbers = rhs.numbers;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isValidNumber(const std::string& token) const {
    if (token.length() != 1)
        return false;
    return (token[0] >= '0' && token[0] <= '9');
}

double RPN::applyOperator(double left, double right, char op) {
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            if (right == 0)
                throw std::runtime_error("Error: Cannot divisible by 0");
            return left / right;
        default:
            throw BadInput();
    }
}

const char* RPN::BadInput::what() const throw() {
    return "Error: Invalid input. Must between 0-9 and operators +, -, *, /";
}

const char* RPN::NoResult::what() const throw() {
    return "Error: No result.";
}

void RPN::processToken(const std::string& token) {
    if (isValidNumber(token)) {
        numbers.push(token[0] - '0');
    }
    else if (isOperator(token)) {
        if (numbers.size() < 2)
            throw std::runtime_error("Error: Not enough operands");
        
        double right = numbers.top();
        numbers.pop();
        double left = numbers.top();
        numbers.pop();
        
        double result = applyOperator(left, right, token[0]);
        numbers.push(result);
    }
    else {
        throw BadInput();
    }
}

double RPN::evaluate(const std::string& input) {
    std::istringstream stream(input); // Creates a stream to read the input word by word
    std::string token;

    /*
    Reads each token separated by spaces
    Iteration 1: token = "3"
    Iteration 2: token = "4"
    Iteration 3: token = "+"
    Iteration 4: token = "2"
    Iteration 5: token = "*"

    Processes each token:
    After "3": Stack = [3]
    After "4": Stack = [3, 4]
    After "+": Stack = [7] (because 3+4=7)
    After "2": Stack = [7, 2]
    After "*": Stack = [14] (because 7*2=14)
    */
    
    while (stream >> token) {
        processToken(token);
    }
    
    if (numbers.size() != 1)
        throw NoResult();
    
    return numbers.top();
}