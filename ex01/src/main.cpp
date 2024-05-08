/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:19:25 by ychng             #+#    #+#             */
/*   Updated: 2024/05/09 04:22:54 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string choice;

	do
	{
		std::cout << "Enter: ";
		std::getline(std::cin, choice);
		if (choice == "ADD")
		{
			PhoneBook phonebook;
		}
		else if (choice == "SEARCH")
		{
			
		}
		
	} while (choice != "EXIT");
}