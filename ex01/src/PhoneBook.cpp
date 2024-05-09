/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:43:34 by ychng             #+#    #+#             */
/*   Updated: 2024/05/10 00:29:07by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact()
{
	Contact newContact(true);

	contacts[numOfContacts] = newContact;
	numOfContacts++;
}

std::string PhoneBook::truncateWithPeriod(const std::string& str, int width)
{
	std::string truncatedStr;

	if (str.length() > 10)	
	{
		truncatedStr = str.substr(0, width - 1);
		truncatedStr += '.';
	}
	else
		truncatedStr = str;
	return (truncatedStr);
}


// Control the output format
void PhoneBook::searchContact() const
{
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "\n";
}

PhoneBook::PhoneBook()
{
	numOfContacts = 0;
}
