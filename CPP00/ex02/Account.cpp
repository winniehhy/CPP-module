/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:00:55 by hheng             #+#    #+#             */
/*   Updated: 2025/03/13 10:51:15 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// static member
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//constructor
/*
_accountIndex(_nbAccounts): Assigns the current count as the account index.
_amount(initial_deposit): Sets the account balance using the given deposit.
_nbDeposits(0) & _nbWithdrawals(0): Initialize per-account counters.

Body
_nbAccounts++;: Increases the total number of accounts.
_totalAmount += initial_deposit;: Adds the initial deposit to the global total amount.
_displayTimestamp();: Calls the method that prints the current timestamp.
*/
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit),
      _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";created" << std::endl;
}

// destructor
/*
When an account object is destroyed (typically 
when the vector is cleared or goes out of scope), 
the destructor logs a closure message ( print close message)
*/
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";p_amount:" << _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit 
              << ";amount:" << _amount 
              << ";nb_deposits:" << _nbDeposits 
              << std::endl;
}

// if not sufficient = withdrawal : refused
// else dedect withdrawal from amoutn & total amount
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";p_amount:" << _amount;
    if (_amount < withdrawal) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal 
              << ";amount:" << _amount 
              << ";nb_withdrawals:" << _nbWithdrawals 
              << std::endl;
    return true;
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits 
              << ";withdrawals:" << _nbWithdrawals 
              << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals 
              << std::endl;
}

//based on current date time
// if time = 0 , then convert to local time
void Account::_displayTimestamp() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "[" 
              << (1900 + now->tm_year)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1) // to start 1 = january
              << std::setw(2) << std::setfill('0') << now->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "] ";
    std::cout << std::setfill(' ');
}
