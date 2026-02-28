#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectTime(0), _dequeTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectTime(other._vectTime), 
    _dequeTime(other._dequeTime), _deque(other._deque), _vector(other._vector) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectTime = other._vectTime;
        _dequeTime = other._dequeTime;
        _deque = other._deque;
        _vector = other._vector;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::displayPairs(const std::string& label, const std::vector<std::pair<int, int> >& pairs) {
    std::cout << label << ": ";
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << pairs[i].first << " " << pairs[i].second;
        if (i + 1 < pairs.size())
            std::cout << " | ";
    }
    std::cout << std::endl;
}

void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]); // convert each argument to string
        std::istringstream iss(arg);
        char *endPtr; // point to the first character after the number.
        long parsed = std::strtol(argv[i], &endPtr, 10); // convert the string to a long integer.

        if (*endPtr != '\0' || parsed > INT_MAX || parsed < 0)
            throw std::runtime_error("Error: Invalid input => " + arg);

        _vector.push_back(parsed);
        _deque.push_back(parsed);
    }
}

void PmergeMe::printResult(int argc, char** argv) {
    std::cout << "Before: ";
    if (argc < LARGE_INPUT)
        displayAll(argv + 1, argv + argc);
    else
        displayTrimmed(argv + 1, argv + argc);

    std::cout << BLUE << "[Vector]" << RESET << " After: ";
    // printStep("Initial vector", _vector);
    runVectorSort();
    
    if (checkOrder(_vector.begin(), _vector.end())) {
        std::cout << GREEN;
    } else {
        std::cout << RED;
    }
    
    if (argc < LARGE_INPUT)
        displayAll(_vector.begin(), _vector.end());
    else
        displayTrimmed(_vector.begin(), _vector.end());
    std::cout << RESET;

    std::cout << PURPLE << "[Deque]" << RESET << " After: ";
    //printStep("Initial deque", _deque);
    runDequeSort();
        
    if (checkOrder(_deque.begin(), _deque.end())) {
        std::cout << GREEN;
    } else {
        std::cout << RED;
    }
    
    if (argc < LARGE_INPUT)
        displayAll(_deque.begin(), _deque.end());
    else
        displayTrimmed(_deque.begin(), _deque.end());

        
    std::cout << "Time to process a range of   " << _vector.size() << " elements with " << BLUE << "std::vector" << RESET << " : " << std::fixed << std::setprecision(5) << (_vectTime / 1000000.0) << " s\n";
    std::cout << "Time to process a range of   " << _deque.size() << " elements with " << PURPLE << "std::deque" << RESET << " : " << std::fixed << std::setprecision(5) << (_dequeTime / 1000000.0) << " s\n";
}
