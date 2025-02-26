/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:00:59 by hheng             #+#    #+#             */
/*   Updated: 2025/02/26 11:16:22 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
/**
 * The constructor is a special method that is invoked automatically at the
 * time an object of a class is created.
 *
 * It is used to initialize the data members of new objects generally, e.g.,
 * numOfContacts is initialized to 0 here.
 */
PhoneBook::PhoneBook(void)
{
	numOfContacts = 0;
}

void	PhoneBook::addContacts(void)
{
	int		index;
	Contact	*curr;

	index = this->numOfContacts % 8;
	curr = &this->contacts[index];
	curr->addInfo();
	this->numOfContacts++;
}

void	PhoneBook::searchContacts()
{
	Contact	contact;
	int		max_iter;
	std::string	index;

	if (this->numOfContacts == 0)
	{
		std::cout << "No contact has been added\n";
		return ;
	}
	std::cout << "     Index|    F_name|    L_name|  Nickname\n";
	max_iter = this->numOfContacts;
	if (max_iter > 8)
		max_iter = 8;
	for (int i = 0; i < max_iter; i++)
	{
		contact.printBriefInfo(this->contacts[i], i + 1);
	}
	while (true)
	{
		std::cout << "Enter the index of an entry to display contact information\n";
		if (!std::getline(std::cin, index))
			std::exit(1);
		if (index.empty())
			return ;
		if (atoi(index.c_str()) <= max_iter && atoi(index.c_str()) > 0)
		{
			this->contacts->printContactInfo(contacts[atoi(index.c_str()) - 1]);
			break ;
		}
		else
			std::cout << "Index is invalid!\n";
	}
}