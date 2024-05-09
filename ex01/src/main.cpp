/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:19:25 by ychng             #+#    #+#             */
/*   Updated: 2024/05/09 23:38:00 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string choice;

	do
	{
		std::cout << "Enter: ";
		std::getline(std::cin, choice);
		if (choice == "ADD")
			phonebook.addContact();
		else if (choice == "SEARCH")
			phonebook.searchContact();
		
	} while (choice != "EXIT");
}