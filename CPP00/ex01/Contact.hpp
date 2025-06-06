/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:14:44 by hheng             #+#    #+#             */
/*   Updated: 2025/03/12 11:05:06 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact();

    // Setters
    void setFirstName(const std::string &str);
    void setLastName(const std::string &str);
    void setNickname(const std::string &str);
    void setPhoneNumber(const std::string &str);
    void setDarkestSecret(const std::string &str);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    bool hasEmptyField() const;
};

#endif
