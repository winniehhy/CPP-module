#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 1)
    {
        std::cerr << "Usage: ./PmergeMe <positive numbers>\n"; 
        return 1;
    }
    try {
        PmergeMe sorter;
        sorter.parseInput(argc, argv);
        sorter.printResult(argc, argv);
              
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << "\n";
    }
    return 0;
}