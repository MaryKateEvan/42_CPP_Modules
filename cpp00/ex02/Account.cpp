/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:12:16 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/20 13:04:39 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

//? The public part of the class first:

//Constructor:
Account::Account( int initial_deposit ) {}

//Destructor:
Account::~Account( void ) {}

// First, definition and initialization of the private static member variables, 
// which are shared among all different objects of the class:
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// So that then the getters can be called:

int	Account::getNbAccounts( void ) {
	
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {

	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {

	return _totalNbWithdrawals;
}


static void	displayAccountsInfos( void ) {

	
}