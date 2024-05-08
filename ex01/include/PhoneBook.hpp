/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:37:32 by ychng             #+#    #+#             */
/*   Updated: 2024/05/09 04:14:51 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <limits>

class PhoneBook
{
public:
	explicit PhoneBook();
	void setFirstName();
	void setLastName();
	void setNickName();
	void setPhoneNumber();
	void setDarkestSecret();
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;	
	bool containsNumbers(const std::string& str) const;
	void setName(std::string& name, const std::string& prompt);
	bool isValidPhoneNumber() const;
};

#endif // PHONEBOOK_HPP