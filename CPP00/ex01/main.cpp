/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:16:49 by hheng             #+#    #+#             */
/*   Updated: 2025/03/03 12:32:30 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
            std::cout << "\nEnter index to display details: ";
            std::string indexStr;
            std::getline(std::cin, indexStr);
            try {
                std::stringstream ss(indexStr);
                int index;
                ss >> index;
                if (ss.fail() || !ss.eof()) {
                    throw std::invalid_argument("Invalid input");
                }
                phoneBook.displayContact(index);
            } catch (const std::exception &e) {
                std::cout << "Invalid index input." << std::endl;
            }
        } else if (command == "EXIT") {
            std::cout << "Exiting the program." << std::endl;
            break;
        } else {
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}