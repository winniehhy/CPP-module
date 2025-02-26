/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:00:55 by hheng             #+#    #+#             */
/*   Updated: 2025/02/26 11:18:15 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) { return (Account::_nbAccounts); }
int	Account::getTotalAmount( void ) { return (Account::_totalAmount); }
int	Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }
int	Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

Account::Account(void) {}

/**
 * Order of initialization in the initializer list must match the order of declaration in the Account.hpp
 */
Account::Account(int initial_deposit) : _accountIndex(getNbAccounts()), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << getNbAccounts() << ";"
	<< "amount:" << this->_amount << ";" << "created\n";
	_nbAccounts++;
	_totalAmount += initial_deposit;
}
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
	<< "total:" << getTotalAmount() << ";"
	<< "deposits:" << getNbDeposits() << ";"
	<< "withdrawals:" << getNbWithdrawals() << "\n";
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" 
                << "amount:" << checkAmount() << ";" 
                << "closed" << std::endl;
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << checkAmount() << ";"
	<< "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals << "\n";
}

void	Account::_displayTimestamp(void)
{
	std::cout << "[19920104_091532] ";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";"
	<< "p_amount:" << checkAmount() << ";"
	<< "deposit:" << deposit << ";"
	<< "amount:" << checkAmount() + deposit << ";"
	<< "nb_deposits:" << this->_nbDeposits << "\n";
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << checkAmount() << ";" << "withdrawal:" ;
	if (withdrawal > this->_amount)
	{
		std::cout << "refused\n";
        return (false);
	}
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_totalNbWithdrawals++;
    this->_nbWithdrawals++;
    std::cout << withdrawal << ";"
	<< "amount:" << this->_amount << ";"
	<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}