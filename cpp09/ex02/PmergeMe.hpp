/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:15:43 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/19 19:58:51 by mevangel         ###   ########.fr       */
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
struct Data {
	Container<int> numbers;
	Container<std::pair<int, int>> pairs;
	Container<int> main_seq; //the `main` sequence (S) of the vector
	Container<int> pend_seq; //the pending sequence of the smaller numbers
};

template <template <typename...> class Container>
struct Data {
	Container<int> numbers;
	Container<std::pair<int, int>> pairs;
	Container<int> main_seq; //the `main` sequence (S) of the vector
	Container<int> pend_seq; //the pending sequence of the smaller numbers
};

class PmergeMe {

	private:
		
		// // data for the Vector:
		// std::vector<int> vecNums;
		// std::vector< std::pair<int, int> > vecPairs;
		// std::vector<int> vecMain; //the `main` sequence (S) of the vector
		// std::vector<int> vecPend; //the pending sequence of the smaller numbers
		
		// // data for the deque:
		// std::deque<int> dqNums;
		// std::deque< std::pair<int, int> > dqPairs;
		// std::deque<int> dqMain; //the `main` sequence (S) of the deque
		// std::deque<int> dqPend; //the pending sequence of the smaller numbers
		
		//instead of all the above:
		Data<std::vector> vecData;
		Data<std::deque> dqData;

		int straggler;

	public:

		PmergeMe();										// default constructor
		PmergeMe(PmergeMe const & to_copy);				// copy constructor
		PmergeMe& operator=(PmergeMe const & src);		// assignement operator overload
		~PmergeMe();									// destructor

		int getStraggler() const;

};