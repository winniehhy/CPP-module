/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:00:59 by hheng             #+#    #+#             */
/*   Updated: 2025/03/14 10:18:04 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//constructor
PhoneBook::PhoneBook() : totalContacts(0) {}

// Helper method to check if string contains only digits
bool PhoneBook::isDigitsOnly(const std::string &str) const {
    if (str.empty())
        return false;
    
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Helper method to check if string contains only letters and spaces
bool PhoneBook::isLettersOnly(const std::string &str) const {
    if (str.empty())
        return false;
    
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isalpha(str[i]) && !std::isspace(str[i])) {
            return false;
        }
    }
    return true;
}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    // First name validation - letters only
    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        if (!isLettersOnly(input)) {
            std::cout << "Error: First name must contain only letters." << std::endl;
        }
    } while (!isLettersOnly(input));
    newContact.setFirstName(input);

    // Last name validation - letters only
    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        if (!isLettersOnly(input)) {
            std::cout << "Error: Last name must contain only letters." << std::endl;
        }
    } while (!isLettersOnly(input));
    newContact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    newContact.setNickname(input);

    // Phone number validation - digits only
    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        if (!isDigitsOnly(input)) {
            std::cout << "Error: Phone number must contain only digits." << std::endl;
        }
    } while (!isDigitsOnly(input));
    newContact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    if (newContact.hasEmptyField()) {
        std::cout << "Error: All fields must be filled." << std::endl;
        return;
    }

    // Replace the oldest contact if there are already 8 contacts.
    int index = totalContacts % 8;
    contacts[index] = newContact;
    totalContacts++;
    std::cout << "Contact added successfully." << std::endl;
}

//format field : is a member function  of PhoneBook
// truancate string length > 10 with '.'
//return type :: function Name :: parameter
std::string PhoneBook::formatField(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void PhoneBook::searchContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    int count = (totalContacts < 8) ? totalContacts : 8;
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    int count = (totalContacts < 8) ? totalContacts : 8;
    if (index < 0 || index >= count) {
        std::cout << "Error: Index out of range." << std::endl;
        return;
    }
    const Contact &c = contacts[index];
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

