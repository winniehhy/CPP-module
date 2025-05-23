/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:15:33 by hheng             #+#    #+#             */
/*   Updated: 2025/03/14 19:16:05 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int totalContacts;
    std::string formatField(const std::string &str) const;
    bool isDigitsOnly(const std::string &str) const;
    bool isLettersOnly(const std::string &str) const;
public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
    void displayContact(int index) const;
};

#endif

