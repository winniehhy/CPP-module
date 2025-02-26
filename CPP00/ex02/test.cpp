// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

/**
 * A vector is a resizable array.
 * Pairs are used to store two heterogeneous objects as a single unit (tuple).
 * Iterators point to elements of data struxtures to access and iterate
 * through them.
 */
int		main( void ) {

	// accounts_t is a vector of Account::t objects
	typedef std::vector<Account::t>							  accounts_t;

	// ints_t is a vector of integers
	typedef std::vector<int>								  ints_t;

	// acc_int_t is a pair of iterators pointing to elements in accounts_t and ints_t
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	// Initial account balances
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };

	// Number of elements in amounts[]
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );

	// A vector of Account::t objects called "accounts" is created.
	// The range constructor of the vector initializes the accounts using the ptrs
	// amounts and amounts + amount_size.
	// The range constructor will create a new Account::t object for each element in the array,
	// using the Account::t constructor which MUST take an integer.
	accounts_t				accounts(amounts, amounts + amounts_size);

	// Point towards beginning and end of the accounts vector
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	// deposits
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	// // withdrawals
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	// // static method of Account class to display general account info (log: line 10)
	Account::displayAccountsInfos();

	// iterates over each account and calls its displayStatus() method (log: lines 12-19)
	// mem_fun_ref() is used to call member functions on elements in a container. Here it
	// calls displayStatus()
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Creates an acc_int_t pair to iterate over accounts and deposits in parallel
	// For each pair of elements (accounts:deposit pair) makeDeposit() is called to
	// add deposit to the account (log: lines 21-28)
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	// // Display post-deposit info (log: line 30)
	Account::displayAccountsInfos();

	// // iterates over each account and calls its displayStatus() method (log: lines 32-39)
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// // Similar as above but calls makeWithdrawl() instead (log: lines 41-48)
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	// // display again
	Account::displayAccountsInfos(); // (log: line 50)
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); // (log: lines 52-59)

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //