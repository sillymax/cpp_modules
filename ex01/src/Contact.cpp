/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:43:25 by ychng             #+#    #+#             */
/*   Updated: 2024/05/10 01:57:51 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool Contact::containsNumbers(const std::string& str) const
{
	for (size_t i = 0; i < str.length(); i++)
		if (std::isdigit(str[i]))
			return (true);
	return (false);
}

void Contact::setName(std::string& name, const std::string& prompt)
{
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, name);
		if (std::cin.eof())
		{
			std::cout << "Why did you EOF? :<\n";
			exit(0);
		}
		if (name.empty())	
			std::cout << "Do you not have a name? Please try again.\n";
		else if (containsNumbers(name))	
			std::cout << "Why do you have numbers in your name? Please try again.\n";
		else
			break ;
	}
}

void Contact::setFirstName(void)
{
	std::string prompt = "Enter first name: ";
	setName(firstName, prompt);
}

void Contact::setLastName(void)
{
	std::string prompt = "Enter last name: ";
	setName(lastName, prompt);
}

void Contact::setNickName(void)
{
	std::string prompt = "Enter nickname: ";
	setName(nickName, prompt);
}

bool Contact::isValidPhoneNumber(void) const
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

void Contact::setPhoneNumber(void)
{
	while (true)
	{
		std::cout << "Enter phone number (10 digits): ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
		{
			std::cout << "Why did you EOF? :<\n";
			exit(0);
		}
		if (isValidPhoneNumber())
			break ;
	}
}

void Contact::setDarkestSecret(void)
{
	while (true)
	{ 
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
		{
			std::cout << "Why did you EOF? :<\n";
			exit(0);
		}
		if (darkestSecret.empty())
			std::cout << "Liar, you definitely have one! Please try again.\n";
		else
			break ;
	}
}

std::string Contact::getFirstName() const
{
	return (firstName);
}

std::string Contact::getLastName() const
{
	return (lastName);
}

std::string Contact::getNickName() const
{
	return (nickName);
}

std::string Contact::getPhoneNumber() const
{
	return (phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (darkestSecret);
}

// default keyword not available in c++98
Contact::Contact()
{}

Contact::Contact(bool addContact)
{
	if (addContact)
	{ 
		setFirstName();
		setLastName();
		setNickName();
		setPhoneNumber();
		setDarkestSecret();
	}
}