/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:14:04 by hheng             #+#    #+#             */
/*   Updated: 2025/03/03 12:29:28 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

// Setters
void Contact::setFirstName(const std::string &str) { firstName = str; }
void Contact::setLastName(const std::string &str) { lastName = str; }
void Contact::setNickname(const std::string &str) { nickname = str; }
void Contact::setPhoneNumber(const std::string &str) { phoneNumber = str; }
void Contact::setDarkestSecret(const std::string &str) { darkestSecret = str; }

// Getters
std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

// Check if any field is empty
bool Contact::hasEmptyField() const {
    return (firstName.empty() || lastName.empty() || nickname.empty() ||
            phoneNumber.empty() || darkestSecret.empty());
}
