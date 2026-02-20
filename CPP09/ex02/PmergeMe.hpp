#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <ctime>
#include <utility>
#include <cmath>
#include <algorithm>
#include <limits.h>


#define GREEN "\e[0;32m"
#define RED "\e[0;31m"
#define BLUE "\e[0;34m"
#define PINK "\e[1;35m"
#define PURPLE "\e[0;35m"
#define RESET "\e[0m"
#define LARGE_INPUT 32

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void parseInput(int argc, char** argv);
        void printResult(int argc, char** argv);
        void displayPairs(const std::string& label, const std::vector<std::pair<int, int> >& pairs); // // Helper to print pairs with | separator

    private:
        double _vectTime;
        double _dequeTime;
        std::deque<int> _deque;
        std::vector<int> _vector;

        // Vector
        void runVectorSort();
        void createPairs(std::vector< std::pair<int, int> >& pairs, std::vector<int>& data);
        void fordJohnsonSortVector(std::vector<int>& data);
        void JacobInsert(std::vector<int>& mainChain, std::vector<int>& pendChain);

        // Deque
        void runDequeSort();
        void createPairs(std::vector< std::pair<int, int> >& pairs, std::deque<int>& data);
        void fordJohnsonSortDeque(std::deque<int>& data);
        void JacobInsert(std::deque<int>& mainChain, std::deque<int>& pendChain);

        // generic functions for printing and validating result
        template <typename T>
        void displayAll(T first, T last);

        template <typename T>
        void displayTrimmed(T first, T last);

        template <typename T>
        bool checkOrder(T first, T last);
};

// Helper to print a container with a label
template <typename Container>
void printStep(const std::string& label, const Container& cont) {
    std::cout << label << ": ";
    for (typename Container::const_iterator it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
void PmergeMe::displayAll(T first, T last) {
    while (first != last) {
        std::cout << *first << " ";
        ++first;
    }
    std::cout << "\n";
}

template <typename T>
bool PmergeMe::checkOrder(T first, T last) {
    while (first != last) {
        T ahead = first;
        ++ahead;
        if (ahead != last && *first > *ahead) {
            std::cout << *first << " -> " << *ahead << "\n";
            return false;
        }
        ++first;
    }
    return true;
}

template <typename T>
void PmergeMe::displayTrimmed(T first, T last) {
    int count = 0;
    int total = std::distance(first, last);
    T pos = last;

    while (count < 4 && first != last) {
        std::cout << *first << " ";
        ++first;
        ++count;
    }
    std::cout << "[...] ";

    int tailIdx = total - 4;
    pos = last - 4;

    while (tailIdx < total && pos != last) {
        std::cout << *pos << " ";
        ++pos;
        ++tailIdx;
    }
    std::cout << std::endl;
}

#endif 

//./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`