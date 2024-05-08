/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:46:44 by ychng             #+#    #+#             */
/*   Updated: 2024/05/09 04:18:55by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool PhoneBook::containsNumbers(const std::string& str) const
{
	for (size_t i = 0; i < str.length(); i++)
		if (std::isdigit(str[i]))
			return (true);
	return (false);
}

void PhoneBook::setName(std::string& name, const std::string& prompt)
{
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, name);
		if (name.empty())	
			std::cout << "Do you not have a name? Please try again.\n";
		else if (containsNumbers(name))	
			std::cout << "Why do you have numbers in your name? Please try again.\n";
		else
			break ;
	}
}

void PhoneBook::setFirstName(void)
{
	std::string prompt = "Enter first name: ";
	setName(firstName, prompt);
}

void PhoneBook::setLastName(void)
{
	std::string prompt = "Enter last name: ";
	setName(lastName, prompt);
}

void PhoneBook::setNickName(void)
{
	std::string prompt = "Enter nick name: ";
	setName(nickName, prompt);
}

bool PhoneBook::isValidPhoneNumber(void) const
{
	int len = phoneNumber.length();
	if (len != 10)
	{
		std::cout << "10 digits! Please try again.\n";
		return (false);
	}
	for (int i = 0; i < len; i++)
		if (!std::isdigit(phoneNumber[i]))
		{
			std::cout << "Why are the alphabets in your phone numeber? Please try again.\n";
			return (false);
		}
	return (true);
}

void PhoneBook::setPhoneNumber(void)
{
	while (true)
	{
		std::cout << "Enter phone number (10 digits): ";
		std::getline(std::cin, phoneNumber);
		if (isValidPhoneNumber())
			break ;
	}
}

void PhoneBook::setDarkestSecret(void)
{
	while (true)
	{ 
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
		if (darkestSecret.empty())
			std::cout << "Liar, you definitely have one! Please try again.\n";
		else
			break ;
	}
}


PhoneBook::PhoneBook()
{
	setFirstName();
	setLastName();
	setNickName();
	setPhoneNumber();
	setDarkestSecret();
}