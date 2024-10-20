/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:15:43 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/20 05:55:06 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once

// #include <iostream>
// #include <string>
// #include <sstream> // "string stream"
// #include <stdexcept>
// #include <ctime>
// #include <limits>  // for INT_MAX
// #include <algorithm>
// #include <utility> // for std::pair

// #include <cctype> // for isdigit()
// #include <cstdlib> // for std::stoi() and std::stod()

// //the containers used in this exercise:
// #include <vector>
// #include <deque>

// #define BOLD(text) "\033[1m" << text << "\033[0m"
// #define UNDERLINE(text) "\033[4m" << text << "\033[0m"
// #define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"
// #define GRAY(text) "\033[90m" << text << "\033[0m"
// #define GREEN(text) "\033[32m" << text << "\033[0m"
// #define RED(text) "\033[31m" << text << "\033[0m"
// #define CYAN(text) "\033[1;96m" << text << "\033[0m"

// // template <template <typename...> class Container>
// // struct Data {
// // 	Container<int> numbers; //the initial unsorted sequence
// // 	Container<std::pair<int, int>> pairs;
// // 	Container<int> main_seq; //the `main` sequence (S) of the vector
// // 	Container<int> pend_seq; //the pending sequence of the smaller numbers
// // 	int straggler;
// // 	clock_t start_time;
// // 	clock_t end_time;
// // };

// // enum Type {
// // 	DEQUE,
// // 	VECTOR
// // };

// // class PmergeMe {

// // 	private:
		
// // 		// // data for the Vector:
// // 		// std::vector<int> vecNums;
// // 		// std::vector< std::pair<int, int> > vecPairs;
// // 		// std::vector<int> vecMain; //the `main` sequence (S) of the vector
// // 		// std::vector<int> vecPend; //the pending sequence of the smaller numbers
		
// // 		// // // data for the deque:
// // 		// std::deque<int> dqNums;
// // 		// std::deque< std::pair<int, int> > dqPairs;
// // 		// std::deque<int> dqMain; //the `main` sequence (S) of the deque
// // 		// std::deque<int> dqPend; //the pending sequence of the smaller numbers
		
// // 		//instead of all the above:
// // 		// Data<std::vector> vecData;
// // 		// Data<std::deque> dqData;

// // 		// int straggler;

// // 		// bool isPositiveInteger(const std::string& str);

// // 	public:

// // 		PmergeMe();										// default constructor
// // 		PmergeMe(PmergeMe const & to_copy);				// copy constructor
// // 		PmergeMe& operator=(PmergeMe const & src);		// assignement operator overload
// // 		~PmergeMe();									// destructor

// // 		bool parseArguments(int argc, char** argv);

// // 		int getStraggler() const;

// // 		// Function to check if a string is a positive integer
// // 		template <template <typename...> class Container>
// // 		bool checkNumber(const std::string& str, Data<Container> data) {
// // 			if (str.empty() || str[0] == '0')
// // 				return false; //if the string is empty or '0'
// // 			for (size_t i = 0; i < str.size(); ++i) {
// // 				if (i == 0 && str.size() != 1 && str[i] == '+')
// // 					continue;
// // 				if (!std::isdigit(str[i]))
// // 					return false;
// // 			}
// // 			long long tmp = std::stoll(str);
// // 			if (tmp < 1 || tmp > std::numeric_limits<int>::max())
// // 				return false;
			
// // 			data.numbers.push_back(static_cast<int>(tmp));
// // 			// If all characters are digits, it's a positive integer
// // 			return true;
// // 		}


// // 		// Function to check all arguments
// // 		// template<typename Container>
// // 		template <template <typename...> class Container>
// // 		bool parseInitArguments(int argc, char** argv, Data<Container> data) {
// // 			for (int i = 1; i < argc; ++i) {  // Skips argv[0] (program name)
// // 				std::string arg = argv[i];
// // 				// Check if the argument is a positive integer
// // 				if (!checkNumber(arg, data)) {
// // 					std::cerr << RED("Error: invalid input!") << std::endl;
// // 					return false;
// // 				}
// // 				// data.numbers.push_back()
// // 			}
// // 			return true;
// // 		}


// // 		template <template <typename...> class Container>
// // 		void MergeInsertionSort(int argc, char** argv) {
// // 			Data<Container> data;
// // 			parseInitArguments(argc, argv, data);
// // 		}

// // };

// template <template <typename...> class Container>
// class PmergeMe {
	
// 	private:
// 		// Defines the attributes based on the container type
// 		Container<int> numbers; //the initial unsorted sequence
// 		Container<std::pair<int, int>> pairs;
// 		Container<int> main_seq; //the `main` sequence (S) of the vector
// 		Container<int> pend_seq; //the pending sequence of the smaller numbers
// 		int straggler;
// 		clock_t start_time;
// 		clock_t end_time;

// 	public:

// 		/* ---------------------------- CANONICAL FORM ---------------------------------*/
		
// 		//default constructor
// 		PmergeMe() : straggler(0), start_time(0), end_time(0) {}
		
// 		// copy constructor
// 		PmergeMe(PmergeMe const & to_copy) : numbers(to_copy.numbers),
// 			pairs(to_copy.pairs), main_seq(to_copy.main_seq), pend_seq(to_copy.pend_seq) {}
		
// 		// assignement operator overload
// 		PmergeMe& operator=(PmergeMe const & src) {
// 			if (this != &src) {
// 				this->numbers = src.numbers;
// 				this->pairs = src.pairs;
// 				this->main_seq = src.main_seq;
// 				this->pend_seq = src.pend_seq;
// 				this->straggler = src.straggler;
// 				this->start_time = src.start_time;
// 				this->end_time = src.end_time;
// 			}
// 			return *this;
// 		}

// 		// destructor
// 		~PmergeMe() {}

// 		// // Example method to print the size of each container
// 		// void printSizes() const {
// 		// 	std::cout << "nums size: " << numbers.size() << std::endl;
// 		// 	std::cout << "pairs size: " << pairs.size() << std::endl;
// 		// 	std::cout << "main_seq size: " << main_seq.size() << std::endl;
// 		// 	std::cout << "pend_seq size: " << pend_seq.size() << std::endl;
// 		// }

// 		/* ------------------------ PARSING THE ARGUMENTS ------------------------------*/




// };

#pragma once

#include <iostream>
#include <string>
#include <sstream> // "string stream"
#include <stdexcept>
#include <ctime>
#include <limits>  // for INT_MAX
#include <algorithm>
#include <utility> // for std::pair

#include <cctype> // for isdigit()
#include <cstdlib> // for std::stoi() and std::stod()

//the containers used in this exercise:
#include <vector>
#include <deque>

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"
#define GRAY(text) "\033[90m" << text << "\033[0m"
#define GREEN(text) "\033[32m" << text << "\033[0m"
#define RED(text) "\033[31m" << text << "\033[0m"
#define CYAN(text) "\033[1;96m" << text << "\033[0m"

template <template <typename...> class Container>
class PmergeMe {
	
	private:
		// Defines the attributes based on the container type
		Container<int> input; //the initial unsorted sequence
		Container<std::pair<int, int>> pairs;
		Container<int> main_seq; //the `main` sequence (S) of the vector
		Container<int> pend_seq; //the pending sequence of the smaller numbers
		int straggler;
		clock_t start_time;
		clock_t end_time;

	public:

		/* ---------------------------- CANONICAL FORM ---------------------------------*/
		
		//default constructor
		PmergeMe() : straggler(0), start_time(0), end_time(0) {}
		
		// copy constructor
		PmergeMe(PmergeMe const & to_copy) : input(to_copy.input),
			pairs(to_copy.pairs), main_seq(to_copy.main_seq), pend_seq(to_copy.pend_seq) {}
		
		// assignement operator overload
		PmergeMe& operator=(PmergeMe const & src) {
			if (this != &src) {
				this->input = src.input;
				this->pairs = src.pairs;
				this->main_seq = src.main_seq;
				this->pend_seq = src.pend_seq;
				this->straggler = src.straggler;
				this->start_time = src.start_time;
				this->end_time = src.end_time;
			}
			return *this;
		}

		// destructor
		~PmergeMe() {}

		/* -------------------------- CUSTOM EXCEPTIONS --------------------------------*/

		class InvalidInputException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "invalid input";
				}
		};

		/* ------------------------ PARSING THE ARGUMENTS ------------------------------*/

		// Function to check if a string is a positive integer
		bool isPositiveInteger(const std::string& str) {

			if (str.empty() || str[0] == '0')
				return false; //if the string is empty or '0..'
			for (size_t i = 0; i < str.size(); ++i) {
				if (i == 0 && str.size() != 1 && str[i] == '+')
					continue;
				if (!std::isdigit(str[i]))
					return false;
			}
			
			long long tmp = std::stoll(str);
			if (tmp < 1 || tmp > std::numeric_limits<int>::max())
				return false;

			// If all characters are digits, it's a positive integer, and we can save it:
			input.push_back(std::stoi(str));
			return true;
		}

		// Function to check all arguments
		bool parseArguments(int argc, char** argv) {
			for (int i = 1; i < argc; ++i) {  // Skips argv[0] (program name)
				std::string arg = argv[i];
				// Check if the argument is a positive integer
				if (!isPositiveInteger(arg))
					throw InvalidInputException();
			}
			return true;
		}

		void mergeInsertionSort(int argc, char** argv) {
			// 1. we parse the arguments and save them in `input` if they're valid integers:
			parseArguments(argc, argv);
			
		}

};