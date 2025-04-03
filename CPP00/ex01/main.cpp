/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:16:49 by hheng             #+#    #+#             */
/*   Updated: 2025/03/14 19:07:43 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
getline : read characters from input until it reached the delimiter
*/

int main() {
    PhoneBook phoneBook;// Create a PhoneBook object to manage contacts
    std::string command; //store user command

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
            
            // Check if input is valid (contains only digits)
            bool isValid = !indexStr.empty();
            for (size_t i = 0; i < indexStr.length(); i++) {
                if (!std::isdigit(indexStr[i])) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                // Convert string to integer manually
                int index = 0;
                for (size_t i = 0; i < indexStr.length(); i++) {
                    index = index * 10 + (indexStr[i] - '0');
                }
                phoneBook.displayContact(index);
            } else {
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