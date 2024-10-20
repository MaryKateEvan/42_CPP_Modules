/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:16:11 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/20 06:57:58 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void printVector(const std::vector<int>& vec) {
	for (int num : vec)
		std::cout << num << " ";
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	
	if (argc < 2) {
		std::cerr << RED("❌ Error!") << std::endl;
		std::cout << UNDERLINE("Correct usage:") << BOLD(" ./PmergeMe int1 int2 int3 ...") << std::endl;
		return 1;
	}

	try {
		
		PmergeMe<std::vector> sort_vector;
		PmergeMe<std::deque> sort_deque;

		double vector_time = sort_vector.TimeMergeInsertionSort(argc, argv);
		double deque_time = sort_deque.TimeMergeInsertionSort(argc, argv);

		std::cout << BOLD(YELLOW("⏳ Before: "));
		printVector(sort_vector.getInput());
		std::cout << BOLD(GREEN("✅ After: "));
		printVector(sort_vector.getMainSeq());

		std::cout << CYAN("Time for vector: ") << vector_time << std::endl;
		std::cout << CYAN("Time for deque: ") << deque_time << std::endl;
		
		
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}

	return 0;
}
