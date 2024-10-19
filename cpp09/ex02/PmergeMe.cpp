/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:15:53 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/19 19:56:01 by mevangel         ###   ########.fr       */
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

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : straggler(0) {}

//copy constructor
PmergeMe::PmergeMe(PmergeMe const & to_copy) : vecData(to_copy.vecData), dqData(to_copy.dqData), straggler(to_copy.straggler) {}
	// : vecNums(to_copy.vecNums), vecPairs(to_copy.vecPairs), vecMain(to_copy.vecMain), vecPend() {}

PmergeMe& PmergeMe::operator=(PmergeMe const & src) {
	
	if (this != &src){
		// this->vecNums = src.vecNums;
		// this->vecPairs = src.vecPairs;
		// this->vecMain = src.vecMain;
		// this->vecPend = src.vecPend;
		// this->dqNums = src.dqNums;
		// this->dqPairs = src.dqPairs;
		// this->dqMain = src.dqMain;
		// this->dqPend = src.dqPend;
		this->vecData = src.vecData;
		this->dqData = src.dqData;

		this->straggler = src.straggler;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::getStraggler() const {

	return this->straggler;
}
