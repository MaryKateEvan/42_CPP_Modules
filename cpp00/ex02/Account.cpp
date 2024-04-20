/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:12:16 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/21 00:09:30 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Initialization of the private static member variables, which are shared 
// among all different objects of the class:
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Getter for the total number of "Account" Objects created
int	Account::getNbAccounts( void ) {

	return _nbAccounts;
}

// Getter for the total amount of money across all Account objects
int	Account::getTotalAmount( void ) {

	return _totalAmount;
}

// Getter for the total number of deposits made across all Account objects
int	Account::getNbDeposits( void ) {

	return _totalNbDeposits;
}

// Getter for the total number of withdrawals made across all Account objects
int	Account::getNbWithdrawals( void ) {

	return _totalNbWithdrawals;
}

// Getter for the amount of the current "Account" Object
int		Account::checkAmount( void ) const {

	return this->_amount;
}

// The Private Constructor that can only be used from inside the class
Account::Account( void ) {}

/*
*	Public Constructor that initializes the 4 private attributes of the current Account object, 
*	displays a message of syntax "[19920104_091532] index:0;amount:42;created" to show the 
*	initialization of the current Account, and updates the static, general for the class, values
*	"_nbAccounts" and "_totalAmount".
*	@param initial_deposit: the amount that the current Account "opens with".
*/
Account::Account( int initial_deposit ) {

	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;

	_nbAccounts++;
	_totalAmount += this->_amount;
}

/*
*	Destructor for the Account objects that also prints a message of syntax/pattern:
*	"[19920104_091532] index:0;amount:47;closed", corresponding to the current Account object.
*/
Account::~Account( void ) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

/*
*	Makes a deposit into the current "Account" object, modifying accordingly the object's and 
*	class' variables that are related to deposit. Prints a message of type:
*	[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
*	@param deposit: the amount to deposit to the current Account object.
*/
void	Account::makeDeposit( int deposit ) {
	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;

	this->_amount += deposit;
	this->_nbDeposits++;

	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

/*
*	Makes a withdrawal from the current "Account" object, modifying accordingly the object's and 
*	class' variables that are related to withdrawal. Prints a message of type:
*	"[19920104_091532] index:0;p_amount:47;withdrawal:refused" if the existing amount is not enough
*	to withdraw, or "[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1",
*	if the existing amount is enough to withdraw.
*	@param withdrawal: the amount to withdraw from the current Account object.
*	@returns true, if the asked withdraw was possible, or
*			 false, if there was not enough amount to process the asked withdraw.
*/
bool	Account::makeWithdrawal( int withdrawal ) {
	
	if (withdrawal >= this->_amount) {
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	else {
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal;

		this->_amount -= withdrawal;
		this->_nbWithdrawals++;

		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
}

/*
*	Displays the cumulative information of all the objects of the class "Account", printing a message
*	of type: "[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0"
*/
void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

/*
*	Displays all the information of the current "Account" object, printing a message
*	of type: "[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0"
*/
void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/*
*	Prints a timestamp of type: "[YEAR(4)MONTH(2)DAY(2)_HOUR(2)MINUTE(2)SECOND(2)] "
*	Example: [20240421_150516]
*/
void Account::_displayTimestamp() {

	std::time_t now = std::time(NULL);
	std::tm *localTime = std::localtime(&now);

	char buffer[16];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);

	std::cout << "[" << buffer << "] ";
}
