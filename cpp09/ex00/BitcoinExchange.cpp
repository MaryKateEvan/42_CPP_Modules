/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marykate <marykate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:40:53 by marykate          #+#    #+#             */
/*   Updated: 2024/10/15 15:53:58 by marykate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// default constructor
BitcoinExchange::BitcoinExchange() {}

// Copy constructor
BitcoinExchange::BitcoinExchange(BitcoinExchange const & to_copy) {
	
	//no attributes to be copied, so nothing to be done here
	(void)to_copy;
}

// Destructor
BitcoinExchange::~BitcoinExchange () {}

// Copy assignment Operator overload
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & src) {

	// no attributes to be assigned
	(void)src;
	return *this;
}