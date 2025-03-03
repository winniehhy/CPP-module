/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:00:55 by hheng             #+#    #+#             */
/*   Updated: 2025/03/03 12:47:40 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// INITIALIZE STATIC MEMBERS
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// PUBLIC METHODS

// Constructor: takes an initial deposit, assigns an account index, and logs creation.
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

// Destructor: logs account closure.
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";closed" << std::endl;
    // Note: Some implementations update static totals here,
    // but often they remain unchanged for logging purposes.
}

// makeDeposit: increases the account amount and updates statistics.
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

// makeWithdrawal: attempts to subtract the withdrawal from the account.
// If insufficient funds, logs "withdrawal:refused" and returns false.
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

// checkAmount: returns the current amount (not used in the test but commonly required).
int Account::checkAmount() const {
    return _amount;
}

// displayStatus: logs the current status of this account.
void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits 
              << ";withdrawals:" << _nbWithdrawals 
              << std::endl;
}

// displayAccountsInfos: logs overall information about all accounts.
void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals 
              << std::endl;
}

// PRIVATE STATIC METHOD

// _displayTimestamp: prints a timestamp in the format [YYYYMMDD_HHMMSS]
// (The exact format might differ from the log file, but timestamps are not checked.)
void Account::_displayTimestamp() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "[" 
              << (1900 + now->tm_year)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "] ";
    std::cout << std::setfill(' ');
}
