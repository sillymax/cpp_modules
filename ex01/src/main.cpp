/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:19:25 by ychng             #+#    #+#             */
/*   Updated: 2024/05/10 01:58:49 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string choice;

	do
	{
		std::cout << "Enter (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, choice);
		if (std::cin.eof())
		{
			std::cout << "Why did you EOF? :<\n";
			exit(0);
		}
		if (choice == "ADD")
			phonebook.addContact();
		else if (choice == "SEARCH")
			phonebook.searchContact();
		else
			std::cout << "Idiot! >:(\n";
		
	} while (choice != "EXIT");
	return (0);
}