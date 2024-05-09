/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:36:50 by ychng             #+#    #+#             */
/*   Updated: 2024/05/10 01:21:21 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	void addContact();
	void searchContact() const;
private:
	Contact contacts[8];
	short	numOfContacts;
	std::string truncateText(const std::string& text, size_t width) const;
	void printTruncatedText(const std::string& text, size_t width) const;
	void printContacts() const;
	void displayContactEntry() const;
};

#endif // PHONEBOOK_HPP