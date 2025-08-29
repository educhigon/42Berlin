/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:34:59 by edugonza          #+#    #+#             */
/*   Updated: 2025/08/29 18:19:13 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	//Instance variables
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	// if (initial_deposit > 0)
	// 	_nbDeposits = 1;
	// else
	// 	_nbDeposits = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	//Class variables
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	// if (initial_deposit > 0)
	// 	_totalNbDeposits += 1;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	return;
}
Account::Account( void )
{
	//Instance variables
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	//Class variables
	_nbAccounts += 1;
	return;
}
Account::~Account( void )
{
	//Instance variables

	//Class variables
	_nbAccounts -= 1;
	_totalAmount -= _amount;
	// _totalNbWithdrawals += 1;;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	return;
}

int Account::getNbAccounts( void )
{
	return	Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return	Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return	Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return	Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";";

	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	std::cout << "amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;

	return;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";";
		_amount -= withdrawal;
		_nbWithdrawals += 1;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		std::cout << "amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
}

int	Account::checkAmount( void ) const
{
	return	_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
	return;
}

void	Account::_displayTimestamp( void )
{
	// Get current timestamp
	time_t now = time(0);
	tm *ltm = localtime(&now);
	// Convert to string
  std::cout << "[" << 1900 + ltm->tm_year;
	if(ltm->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << ltm->tm_mon + 1 << ltm->tm_mday << "_" << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";

}
