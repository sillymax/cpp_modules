/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:33:35 by ychng             #+#    #+#             */
/*   Updated: 2024/05/09 00:53:54 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

static void printUpperChars(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
		std::cout << static_cast<char>(toupper(str[i]));
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			printUpperChars(argv[i]);
	}
	std::cout << "\n";
	return (0);
}
