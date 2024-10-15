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
		
		std::stringstream ss(line);

		if (std::getline(ss, date, ',')) { // gets the date

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

//! to be deleted after. 
// verification for the data.csv reading:
void printMap(const std::map<std::string, double>& dataMap) {
	for (const auto& entry : dataMap) {
		// std::cout << "Date: " << entry.first << ", Exchange rate: " << entry.second << std::endl;
		std::cout << "Date: " << entry.first 
					<< ", Exchange rate: " << std::fixed << std::setprecision(8) 
					<< entry.second << std::endl;
	}
}

void bitcoinExchanger(const char* input_file) {

	std::map<std::string, double> dataBase; //it will save respectively: data, exchange_rate
	
	if (!parseDataBase("data.csv", dataBase))
		return ;
	
	printMap(dataBase);

	std::cout << "\n\n\n and then the input file:\n";
	
	//opens the file from argv[1] and saves it in an input file stream:
	std::ifstream inputFile(input_file);

	if (!inputFile.is_open()) {
		std::cout << RED("❌ Error: ") << "could not open file " << input_file << std::endl;
		return ;
	}

	// Read the file line by line and print it
	std::string line;
	while (std::getline(inputFile, line)) {
		std::cout << line << std::endl;
	}

	// Close the file
	inputFile.close();
}