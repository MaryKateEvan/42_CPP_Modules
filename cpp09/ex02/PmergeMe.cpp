/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:15:53 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/20 05:55:29 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NOTES:
The Merge Insertion Sort algorithm is as follows:
1. Given an unsorted list, group the list into pairs. If the list is odd, the last element is unpaired.
2. Each pair is sorted (using a single comparison each) into what we will call [a b] pairs.
3. The pairs are sorted recursively based on the a of each, and we call the pairs [a1 b1], [a2 b2] etc. 
   If the list was odd, the unpaired element is considered the last b.
4. 
*/

// #include "PmergeMe.hpp"

// PmergeMe::PmergeMe() : straggler(0) {}

// //copy constructor
// PmergeMe::PmergeMe(PmergeMe const & to_copy) : vecData(to_copy.vecData), dqData(to_copy.dqData), straggler(to_copy.straggler) {}
// 	// : vecNums(to_copy.vecNums), vecPairs(to_copy.vecPairs), vecMain(to_copy.vecMain), vecPend() {}

// PmergeMe& PmergeMe::operator=(PmergeMe const & src) {
	
// 	if (this != &src){
// 		// this->vecNums = src.vecNums;
// 		// this->vecPairs = src.vecPairs;
// 		// this->vecMain = src.vecMain;
// 		// this->vecPend = src.vecPend;
// 		// this->dqNums = src.dqNums;
// 		// this->dqPairs = src.dqPairs;
// 		// this->dqMain = src.dqMain;
// 		// this->dqPend = src.dqPend;
// 		this->vecData = src.vecData;
// 		this->dqData = src.dqData;

// 		this->straggler = src.straggler;
// 	}
// 	return *this;
// }

// PmergeMe::~PmergeMe() {}

// int PmergeMe::getStraggler() const {

// 	return this->straggler;
// }

// /* -------------------------- PARSING FUNCTIONS --------------------------- */

// // Function to check if a string is a positive integer
// bool PmergeMe::isPositiveInteger(const std::string& str) {

// 	// if (str.empty() || str[0] == '0' || (str.size() == 1 && str[0] == '-'))
// 	if (str.empty() || str[0] == '0')
// 		return false; //if the string is empty or '0'

// 	// // then we ensure every character is a digit:
// 	// for (char c : str) {
// 	// 	if (!std::isdigit(c))
// 	// 		return false;
// 	// }

// 	for (size_t i = 0; i < str.size(); ++i) {
// 		if (i == 0 && str.size() != 1 && str[i] == '+')
// 			continue;
// 		if (!std::isdigit(str[i]))
// 			return false;
// 	}
	
// 	long long tmp = std::stoll(str);
// 	if (tmp < 1 || tmp > std::numeric_limits<int>::max())
// 		return false;

// 	// If all characters are digits, it's a positive integer
// 	return true;
// }

// // Function to check all arguments
// bool PmergeMe::parseArguments(int argc, char** argv) {
// 	for (int i = 1; i < argc; ++i) {  // Skips argv[0] (program name)
// 		std::string arg = argv[i];
// 		// Check if the argument is a positive integer
// 		if (!isPositiveInteger(arg)) {
// 			std::cerr << RED("Error: invalid input!") << std::endl;
// 			return false;
// 		}
// 	}
// 	return true;
// }

// void PmergeMe::MergeInsertionSort(int argv, char** argv, Type type) {
	
// }


