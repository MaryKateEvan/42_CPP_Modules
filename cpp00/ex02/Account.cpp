/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:12:16 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/20 16:40:30 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// First, definition and initialization of the private static member variables, 
// which are shared among all different objects of the class:
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// So that then the getters can be called:

// Getter for the total number of "Account" Objects created:
int	Account::getNbAccounts( void ) {

	return _nbAccounts;
}

// Getter for the total amount of money across all Account objects.
int	Account::getTotalAmount( void ) {

	return _totalAmount;
}

// Getter for the total number of deposits made across all Account objects.
int	Account::getNbDeposits( void ) {

	return _totalNbDeposits;
}

// Getter for the total number of withdrawals made across all Account objects.
int	Account::getNbWithdrawals( void ) {

	return _totalNbWithdrawals;
}

// The Private Constructor that can only be used from inside the class:
Account::Account( void ) {

	// prints the creation message: [19920104_091532] index:0;amount:42;created
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

// The Public constructor that's called first, and needs an int argument:
Account::Account( int initial_deposit ) {

	// First we initialize the 4 attributes of the current "Account" object:
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// and then we call the second, private constructor to print the message that
	// the account was created, with its corresponding index and initial amount.
	Account();
	
	// and then we modify accordingly the static, shared among the objects, variables:
	_nbAccounts++; // we increase it to be used in the construction of the next object:
	_totalAmount += this->_amount;
}

//Destructor:
Account::~Account( void ) {

	// prints the closing message: [19920104_091532] index:0;amount:47;closed
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}


// Displays information about all Account objects, such as the number 
// of accounts, total amount, etc.
void	Account::displayAccountsInfos( void ) {

	
}



// Allows making a deposit into the account. Increases the 
// account balance (amount) by the specified deposit amount.
void	Account::makeDeposit( int deposit ) {
	
	this->_amount += deposit;
}


// Allows making a withdrawal from the account. Checks if the account has 
// sufficient balance (amount) to cover the withdrawal. If yes, it subtracts 
// the withdrawal amount and returns true, otherwise returns false.
bool	Account::makeWithdrawal( int withdrawal ) {
	
	if (withdrawal > 0)
		return true;
	else
		return false;
}

// Returns the current balance (amount) of the account object.
int		Account::checkAmount( void ) const {

	return this->_amount;
}

// Displays the status of the account, including its index, balance, 
//number of deposits, and number of withdrawals.
void	Account::displayStatus( void ) const {

	
}

void Account::_displayTimestamp() {

	std::time_t now = std::time(NULL);
	std::tm *localTime = std::localtime(&now);

	// Format the timestamp
	std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "]: ";
}