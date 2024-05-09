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

std::string PhoneBook::truncateText(const std::string& text, size_t width) const
{
	return ((text.length() > 10) ? text.substr(0, width - 1) + '.' : text);
}

void PhoneBook::printTruncatedText(const std::string& text, size_t width) const
{
	std::string truncatedText = truncateText(text, width);
	std::cout << '|' << std::setw(width) << truncatedText;
}

void PhoneBook::printContacts() const
{
	size_t width = 10;

	std::cout << std::setw(10) << "Index";
	printTruncatedText("Fist Name", width);
	printTruncatedText("Last Name", width);
	printTruncatedText("Nickname", width);
	std::cout << "\n";

	for (short i = 0; i < numOfContacts; i++)
	{
		std::cout << std::setw(10) << i;
		printTruncatedText(contacts[i].getFirstName(), width);
		printTruncatedText(contacts[i].getLastName(), width);
		printTruncatedText(contacts[i].getNickName(), width);
		std::cout << "\n";
	}
}

void PhoneBook::displayContactEntry() const
{
	short index;

	while (true)
	{ 
		std::cout << "Enter the index of the entry to display (or -1 to exit): ";
		std::cin >> index;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.fail())
		{
			std::cout << "Only numbers! Please try again.\n";
			std::cin.clear();
			continue ;
		}
		if (index == -1)
			break ;
		if (index < numOfContacts && index >= 0)	
		{
			std::cout << "First Name: " << contacts[index].getFirstName() << "\n"
					<< "Last Name: " << contacts[index].getLastName() << "\n"
					<< "Nickname: " << contacts[index].getNickName() << "\n"
					<< "Phone Number: " << contacts[index].getPhoneNumber() << "\n"
					<< "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
		}
		else
			std::cout << "Look carefully, you'll figured it out. Please try again.\n";
	}
}

// Control the output format
void PhoneBook::searchContact() const
{
	printContacts();
	displayContactEntry();
}

PhoneBook::PhoneBook()
{
	numOfContacts = 0;
}
