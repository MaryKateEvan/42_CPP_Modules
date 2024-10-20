/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:04:57 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/21 01:49:45 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// default constructor
BitcoinExchange::BitcoinExchange() {}

// Copy constructor
BitcoinExchange::BitcoinExchange(BitcoinExchange const & to_copy) {
	(void)to_copy;
}

// Copy assignment Operator overload
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & src) {
	(void)src;
	return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange () {}

/* -------------------------- THE PRIVATE METHODS NEEDED FROM THE MAIN CALCULATOR ---------------------------*/

bool BitcoinExchange::parseDataBase(const char* file, std::map<std::string, double>& dataMap) {

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

std::string BitcoinExchange::checkTheDate(std::string const & date) {

	int i = 0;
	int len = date.size();

	// Step 1: Skip/accept leading whitespaces if there are any
	while (i < len && std::isspace(date[i]))
		++i;

	// Step 2: Check for a valid 4-digit year
	if (i + 4 > len || !std::isdigit(date[i]) || !std::isdigit(date[i+1]) || !std::isdigit(date[i+2]) || !std::isdigit(date[i+3]))
		return "Date not in the format: YYYY-MM-DD";
	int year = std::stoi(date.substr(i, 4)); // Extracts the year
	i += 4;
	if (i >= len || date[i] != '-')
		return "Date not in the format: YYYY-MM-DD";
	++i; //to pass the dash

	// Step 3: check for a valid 2-digit month
	if (i + 2 > len || !std::isdigit(date[i]) || !std::isdigit(date[i+1]))
		return "Date not in the format: YYYY-MM-DD";
	int month = std::stoi(date.substr(i, 2)); // Extracts the month
	if (month < 1 || month > 12)
		return "Invalid month";
	i += 2;
	if (i >= len || date[i] != '-')
		return "Date not in the format: YYYY-MM-DD";
	++i; //to pass the dash

	// Step 4: check for a valid 2-digit day
	if (i + 2 > len || !std::isdigit(date[i]) || !std::isdigit(date[i+1]))
		return "Date not in the format: YYYY-MM-DD";
	int day = std::stoi(date.substr(i, 2)); // Extracts the month
	i += 2;
	if (day < 1 || day > 31)
		return "Invalid day"; // Invalid day
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return "Invalid Date: this month has only 30 days"; // Invalid day for months with 30 days
	//checks also for the leap years:
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return "Not a leap year!"; // Invalid day for February
	}

	// some additional checks:
	if ((year < 2009) || (year == 2009 && month == 1 && day == 1))
		return "Date before the first entry in the data base";
	if (year > 2024)
		return "We can not predict the future";

	// Step 5: Skips trailing whitespaces
	while (i < len && std::isspace(date[i]))
		++i;

	// If there are any other, random, characters left, it's shouldnt be a valid date
	if (i != len)
		return "Invalid characters present";
	
	// If none of the above were met, it should be a valid Date:
	return "Ok!";
}

// examples it rejects: ++352, +-352, --352, +352-, -3252+235, .352, 0..352, 35.235.23
bool BitcoinExchange::isNumRepresentation(std::string const & str) {
	
	bool foundDot = false;
	bool foundSign = false;
	bool foundNum = false;
	
	if (str[0] == '.' || str == "-0")
		return false;
	for (size_t i = 0; i < str.size(); ++i) {
		if (str[i] == '.' && foundDot == false)
			foundDot = true;
		else if (str[i] == '.' && foundDot) //for cases like 0..53
			return false;
		else if ((str[i] == '-' || str[i] == '+') && !foundSign)
			foundSign = true;
		else if ((str[i] == '-' || str[i] == '+') && foundSign)
			return false;
		else if (std::isdigit(str[i]) && foundNum == false)
			foundNum = true;
		else if (std::isdigit(str[i]) == false)
			return false;
	}
	if (foundNum == false) //for cases like "-" or "+"
		return false;
		
	return true;
}

std::string BitcoinExchange::checkTheValue(std::string const & rate_str, double& rate_num) {
	// Trim whitespaces
	size_t start = rate_str.find_first_not_of(" \t");
	if (start == std::string::npos) //like if rate_str is "    "
		return "value is missing";
	size_t end = rate_str.find_last_not_of(" \t");
	std::string rate = rate_str.substr(start, end - start + 1);
	// Check the number in between if its empty
	if (rate.empty())
		return "value is missing";
	//remove the last character if the value has float representation:
	if (rate.back() == 'f' || rate.back() == 'F')
		rate.pop_back();
	if (rate.empty()) // in case rate_str was like: "    F	  "
		return "value is missing";
	if (isNumRepresentation(rate) == false)
		return "not a valid number";
	// if we reach here it means we have a valid number to be converted to double
	rate_num = std::stod(rate);
	if (rate_num < 0)
		return "not a positive number";
	else if (rate_num > std::numeric_limits<int>::max())
		return "too large a number";

	return "Ok!";
}

// Trims leading and trailing spaces and tabs form the date and value
std::string BitcoinExchange::trim(const std::string& str) {
	size_t start = 0;
	// we find the first non-whitespace character from the left
	while (start < str.size() && std::isspace(str[start]))
		start++;

	size_t end = str.size() - 1;
	//  and then the first non-whitespace character from the right
	while (end > start && std::isspace(str[end]))
		end--;

	// Then we return the substring, with the leading and trailing spaces removed
	return str.substr(start, end - start + 1);
}

double BitcoinExchange::findRateAccordingToDate(const std::map<std::string, double>& dataBase, const std::string& date) {
	// we find the first entry which is "BIGGER THAN" (string compare in our case) the target date. (in the map they are sorted by the dates):
	std::map<std::string, double>::const_iterator it = dataBase.lower_bound(date);

	// If the exact date is found in the data base, we return its rate:
	if (it != dataBase.end() && it->first == date)
		return it->second;

	// else we return the rate of the previous entry (above) in the data base:
	if (it != dataBase.begin())
		--it;
	return it->second;
}

// Function to verify the result from the `parseDataBase()`
void BitcoinExchange::printMap(const std::map<std::string, double>& dataMap) const {
	for (const auto& entry : dataMap) {
		std::cout << "Date: " << entry.first 
					<< ", Exchange rate: " << entry.second << std::endl;
	}
}

/* --------------------------------- THE MAIN, PUBLIC, CALCULATION FUNCTION ---------------------------------*/

/**
 * STEPS:
 * 1. Parse the "Data Base" from the data.csv file and store everything in a std::map
 * 2. Open and parse the "input.txt" file.
 * For every line read in the loop:
 * 3. VALIDATE the line:
 * 	  a) check for line formatting: DATE | value
 * 	  b) check for the date to be valid
 * 	  c) check for the value to be valid, only positive floats, and integers accepted (range of integers).
 * 		 (also it shouldn't be alphabetical or any other character rather than digits and . in the floats)
 * 4. Retrieve the exchange_rate from the DataBase according to the parsed "date" of the line
 * 5. Calculate and print the asked value for that line
 */
void BitcoinExchange::CalculateExchange(const char* input) {

	std::map<std::string, double> dataBase; //it will save respectively: <date, exchange_rate>
	if (!parseDataBase("data.csv", dataBase))
		return ;

	//opens the file from argv[1] and saves it in an input file stream:
	std::ifstream inputFile(input);
	if (!inputFile.is_open()) {
		std::cout << RED("❌ Error: " << "could not open file \"" << input << "\"") << std::endl;
		return ;
	}
	// THE MAIN LOOP:
	// Reads the file line by line, checks if the line is valid, and prints the result for this line
	std::string line;
	while (std::getline(inputFile, line)) {
		
		if (line.empty() || line == "date | value")
			continue ; //it continues reading the next line of the file
		
		std::stringstream ss(line); //new string stream for every line that was read
		std::string date, value_str;
		
		std::getline(ss, date, '|'); //extracts from the `line` the string until the '|' character
		std::string check_result = checkTheDate(date);
		if (check_result != "Ok!") {
			std::cout << RED("Error: bad input => ") << RED(date) << std::endl;
			//alternatively, to see also the date that has the problem:
			// std::cout << RED("Error: bad input => ") << RED(date) << GRAY(" [" << check_result << "]") << std::endl;
			continue ;
		}
		std::getline(ss, value_str); //extracts the remaining string of the line, after the pipe till the end of the line
		if (value_str.empty()){
			std::cout << RED("Error: value is missing.") << std::endl;
			continue ;
		}
		double value_num;
		std::string check_value = checkTheValue(value_str, value_num);
		if (check_value != "Ok!") {
			std::cout << RED("Error: " << check_value << ".") << std::endl;
			//alternatively, to see also the value that has the problem:
			// std::cout << RED("Error: " << check_value << ".") << GRAY(" [" << value_str << " ]") << std::endl;
			continue ;
		}
		// so if we reach here, we have both a valid date and a vlid value
		double exchange_rate = findRateAccordingToDate(dataBase, trim(date));
		// the output as the pdf wants it:
		std::cout << GREEN(trim(date) << " => " << trim(value_str) << " = " << BOLD((value_num * exchange_rate))) << std::endl;
		// the output that makes more sense:
		// std::cout << trim(date) << " => " << trim(value_str) << " * " << exchange_rate << " = " << (value_num * exchange_rate) << std::endl;
	}

	// Close the file
	inputFile.close();
}

