/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:15:33 by hheng             #+#    #+#             */
/*   Updated: 2025/03/03 12:29:45 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
private:
    Contact contacts[8];
    int totalContacts;
    
    // Helper function to format strings
    std::string formatField(const std::string &str) const;
public:
    PhoneBook();

    // Adds a new contact. Replaces the oldest if more than 8 contacts.
    void addContact();
    // Displays a list of contacts.
    void searchContacts() const;
    // Displays detailed information of a contact.
    void displayContact(int index) const;
};

#endif // PHONEBOOK_HPP

