// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <iomanip>
#include <ctime>

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ); 
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void ); // print overall bank info

	Account( int initial_deposit ); //constructor
	~Account( void ); //destructor

	void	makeDeposit( int deposit ); //to update an account’s balance while also updating the overall static counters.
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const; // print individual account status


private:

	static int	_nbAccounts; // Counts how many accounts have been created.
	static int	_totalAmount; // The sum of all accounts’ balances
	static int	_totalNbDeposits; //  Track the total number of deposits
	static int	_totalNbWithdrawals; // track total number of  withdrawals across all accounts

	static void	_displayTimestamp( void ); //print current timestamp in the log

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
