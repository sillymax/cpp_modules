/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 02:28:21 by ychng             #+#    #+#             */
/*   Updated: 2024/05/10 04:01:59 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	// Get the current time
	std::time_t currentTime;
	std::time(&currentTime);

	// Convert the current time to a tm structure
	std::tm *timeInfo = std::localtime(&currentTime);

	// Format the timestamp
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeInfo);

	// Display the formatted timestamp
	std::cout << buffer << ' ';
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';'
			  << "total:" << getTotalAmount() << ';'
			  << "deposits:" << getNbDeposits() << ';'
			  << "withdrawals:" << getNbWithdrawals() << '\n';
}

void Account::makeDeposit(int deposits)
{
	_totalAmount += deposits;
	_totalNbDeposits++;

	int previous_amount = _amount;

	_amount += deposits;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "p_amount:" << previous_amount << ';'
			  << "deposit:" << deposits << ';'
			  << "amount:" << _amount << ';'
			  << "nb_deposits:" << _nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal)
{
	int previous_amount = _amount;

	_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ';'
				  << "p_amount:" << previous_amount << ';'
			 	  << "withdrawal:" << "refused\n";
		return (false);
	}

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	_amount -= withdrawal;
	_nbWithdrawals++;

	std::cout << "index:" << _accountIndex << ';'
			  << "p_amount:" << previous_amount << ';'
			  << "withdrawal:" << withdrawal << ';'
			  << "amount:" << _amount << ';'
			  << "nb_withdrawals:" << _nbWithdrawals << '\n';
	return (true);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ';'
			  << "deposits:" << _nbDeposits << ';'
			  << "withdrawals:" << _nbWithdrawals << '\n';
}

Account::Account(int initial_deposit)
{

	_nbAccounts++;
	_totalAmount += initial_deposit;

	static int index;

	_accountIndex = index;
	index++;

	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ';'
			  << "created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ';'
			  << "closed\n";
}
