/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:12:16 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/20 13:57:24 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

//Constructor:
Account::Account( int initial_deposit ) {

	this->_amount = initial_deposit; //?first assumption. not sure. i need to verify.
}

//Destructor:
Account::~Account( void ) {}

// First, definition and initialization of the private static member variables, 
// which are shared among all different objects of the class:
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// So that then the getters can be called:

// Returns the total number of "Account" Objects created:
int	Account::getNbAccounts( void ) {

	return _nbAccounts;
}

// Returns the total amount of money across all Account objects.
int	Account::getTotalAmount( void ) {

	return _totalAmount;
}

// Returns the total number of deposits made across all Account objects.
int	Account::getNbDeposits( void ) {

	return _totalNbDeposits;
}

// Returns the total number of withdrawals made across all Account objects.
int	Account::getNbWithdrawals( void ) {

	return _totalNbWithdrawals;
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

	std::time_t now = std::time(nullptr);
	std::tm *localTime = std::localtime(&now);

	// Format the timestamp
	std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "]: ";
}