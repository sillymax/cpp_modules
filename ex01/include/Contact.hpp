/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:37:32 by ychng             #+#    #+#             */
/*   Updated: 2024/05/09 23:52:37 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <limits>

class Contact
{
public:
	Contact();
	explicit Contact(bool addContact);
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

#endif // CONTACT_HPP