#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << RED << "Error: could not open file." << RESET << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange;
        exchange.evaluateInputFile(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}