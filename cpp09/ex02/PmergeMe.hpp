/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:15:43 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/20 07:09:17 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <chrono>  // for std::chrono::seconds

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
#define YELLOW(text) "\033[33m" << text << "\033[0m"


template <template <typename...> class Container>
class PmergeMe {
	
	private:
		// Defines the attributes based on the container type
		Container<int> input; //the initial unsorted sequence
		Container<std::pair<int, int>> pairs;
		Container<int> main_seq; //the `main` sequence (S) of the vector
		Container<int> pend_seq; //the pending sequence of the smaller numbers
		int straggler;

	public:

		/* ---------------------------- CANONICAL FORM ---------------------------------*/
		
		//default constructor
		PmergeMe() : straggler(0) {}
		
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
				if (!isPositiveInteger(arg))
					throw InvalidInputException();
			}
			return true;
		}

		double TimeMergeInsertionSort(int argc, char** argv) {
			
			// // STEP 1: we parse the arguments and save them in container `input` if they're valid integers:
			parseArguments(argc, argv);
			
			// clock_t start_time = clock();
			// std::this_thread::sleep_for(std::chrono::seconds(4));
			// clock_t end_time = clock();

			// double sorting_time = (end_time - start_time) * 1000.0 / CLOCKS_PER_SEC; // converts from clock ticks to seconds ( the `/ CLOCKS_PER_SEC`), and then from seconds to milliseconds by multiplying with 1000
			
			// return sorting_time;

			auto start_time = std::chrono::high_resolution_clock::now();
			// ... sorting part ...


			
			auto end_time = std::chrono::high_resolution_clock::now();

			// Calculate the duration in milliseconds
			std::chrono::duration<double, std::milli> sorting_time = end_time - start_time;
			
			return sorting_time.count(); // returns the duration in milliseconds
		}

		/* ------------------------------- GETTERS -------------------------------------*/
		const Container<int>& getInput() const {
			return this->input;
		}
		const Container<int>& getMainSeq() const {
			return this->main_seq;
		}
		const Container<int>& getPendSeq() const {
			return this->pend_seq;
		}
		
		/* -------------------------------- UTILS --------------------------------------*/
		void printContainerNums(const Container<int>& container) {
			for (int num : container)
				std::cout << num << " ";
			std::cout << std::endl;
		}
};