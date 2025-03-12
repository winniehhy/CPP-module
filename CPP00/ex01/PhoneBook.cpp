/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:00:59 by hheng             #+#    #+#             */
/*   Updated: 2025/03/12 10:22:54 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContacts(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    newContact.setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
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

