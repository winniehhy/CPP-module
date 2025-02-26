/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:15:33 by hheng             #+#    #+#             */
/*   Updated: 2025/02/26 11:16:39 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

#include "Contact.hpp"

/**
 * ENCAPSULATION AND DATA HIDING
 * 
 * "private" and "public" are access specifiers that determine the accessibility
 * of members (variables and functions) of a class from outside the class.
 * 
 * Public members of a class can be accessed directly from outside the class.
 * They are available to any function/code that has access to the object of the
 * class.
 * 
 * Private members can only be accessed or modified through member functions
 * that are public or friend functions (functions that are given special access
 * to private members).
 */
class PhoneBook
{
	private:
		Contact contacts[8];
		int		numOfContacts;

	public:
		PhoneBook(void);
		void	addContacts(void);
		void	searchContacts(void);
};

#endif