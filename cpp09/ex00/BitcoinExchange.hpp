/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:05:11 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/21 01:34:58 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream> // "file stream"
#include <sstream> // "string stream"
#include <cctype> // for isdigit()
#include <cstdlib> // for std::stoi() and std::stod()
#include <limits>  // for INT_MAX
#include <map>

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"
#define GRAY(text) "\033[90m" << text << "\033[0m"
#define GREEN(text) "\033[32m" << text << "\033[0m"
#define RED(text) "\033[31m" << text << "\033[0m"
#define CYAN(text) "\033[1;96m" << text << "\033[0m"

class BitcoinExchange {

	private:

		bool parseDataBase(const char* file, std::map<std::string, double>& dataMap);
		std::string checkTheDate(std::string const & date);
		bool isNumRepresentation(std::string const & str);
		std::string checkTheValue(std::string const & rate_str, double& rate_num);
		std::string trim(const std::string& str);
		double findRateAccordingToDate(const std::map<std::string, double>& dataBase, const std::string& date);
		void printMap(const std::map<std::string, double>& dataMap) const; //util function for debugging

	public:
		
		BitcoinExchange();											// default constructor
		BitcoinExchange(BitcoinExchange const & to_copy);			// copy constructor
		~BitcoinExchange();											// destructor
		BitcoinExchange& operator=(BitcoinExchange const & src);	// Assignment operator overload
		
		void CalculateExchange(const char* input_file);
		
};