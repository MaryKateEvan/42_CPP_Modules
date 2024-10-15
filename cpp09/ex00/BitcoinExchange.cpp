/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:04:57 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/15 19:44:58 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iomanip> // For std::fixed and std::setprecision

static bool parseDataBase(const char* file, std::map<std::string, double>& dataMap) {

	std::ifstream dataFile(file);

	if (!dataFile.is_open()) {
		std::cout << RED("❌ Error: ") << "could not open data Base File: " << file << std::endl;
		return false;
	}

	std::string line, date;
	double exchange_rate;

	std::getline(dataFile, line); // skips the header line "date,exchange_rate"

	// loop to read each line and parse it:
	while (std::getline(dataFile, line)) {
		
		std::stringstream ss(line); //new string stream for every line read

		if (std::getline(ss, date, ',')) { // gets the date, by limiting the string until the ',' occurence

			std::string rate_str;
			if (std::getline(ss, rate_str)) { //extracts the exchage_rate as string
				exchange_rate = std::stod(rate_str); // converts the string to double
				dataMap[date] = exchange_rate; //stores the double rate in the dataMap "indexed" by the date
			}
		}
	}
	dataFile.close();
	return true;
}

bool dateIsValid(std::string const & date) {
	for (char ch : date) {
		// Check each character of the string
		if (!(std::isdigit(ch) || ch == '-' || std::isspace(ch))) {
			return false; // Invalid character found
		}
	}
	return true;
}

/**
 * STEPS:
 * 1. Parse the "Data Base" from the data.csv file and store everything in a std::map
 * 2. Open and parse the "input.txt" file.
 * 	  For every line read in the loop:
 * 3. VALIDATE the line:
 * 	  a) check for line formatting: DATE | value
 * 	  b) check for the date to be valid
 * 	  c) check for the value to be valid, only positive floats, and integers accepted (range of integers).
 * 		 (also it shouldn't be alphabetical or any other character rather than digits and . in the floats)
 * 4. Print the corresponding result for the line.
 */
void bitcoinExchanger(const char* input) {

	std::map<std::string, double> dataBase; //it will save respectively: <date, exchange_rate>
	if (!parseDataBase("data.csv", dataBase))
		return ;
	// printMap(dataBase);

	//opens the file from argv[1] and saves it in an input file stream:
	std::ifstream inputFile(input);
	if (!inputFile.is_open()) {
		std::cout << RED("❌ Error: ") << "could not open file " << input << std::endl;
		return ;
	}
	// THE MAIN LOOP:
	// Reads the file line by line, checks if the line is valid, and prints the result for this line
	std::string line;
	while (std::getline(inputFile, line)) {
		
		if (line.empty() || line == "date | value")
			continue ; //it continues reading the next line of the file
		
		std::stringstream ss(line); //new string stream for every line that was read
		std::string date, rate_str;
		
		std::getline(ss, date, '|'); //extracts from the `line` the string until the '|' character
		if (dateIsValid(date) == false) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		else
			std::cout << line << ": in progress ... " << std::endl;
	}

	// Close the file
	inputFile.close();
}


// // Function to verify the result from the `parseDataBase()`
// void printMap(const std::map<std::string, double>& dataMap) {
// 	for (const auto& entry : dataMap) {
// 		std::cout << "Date: " << entry.first 
// 					<< ", Exchange rate: " << std::fixed << std::setprecision(8) 
// 					<< entry.second << std::endl;
// 	}
// }