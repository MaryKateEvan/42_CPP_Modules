/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:16:11 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/20 06:15:29 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



int main(int argc, char** argv) {
	
	if (argc < 2) {
		std::cerr << RED("❌ Error!") << std::endl;
		std::cout << UNDERLINE("Correct usage:") << BOLD(" ./PmergeMe int1 int2 int3 ...") << std::endl;
		return 1;
	}
	(void)argv;

	try {
		
		PmergeMe<std::vector> sort_vector;
		PmergeMe<std::deque> sort_deque;

		std::cout << "Time for vector: " << sort_vector.TimeMergeInsertionSort(argc, argv) << std::endl;
		std::cout << "Time for deque: " << sort_deque.TimeMergeInsertionSort(argc, argv) << std::endl;
		
		// if (sort.parseArguments(argc, argv) == false)
		// 	return 1;

		// sort.MergeInsertionSort<std::vector>(argc, argv);
		// sort.MergeInsertionSort<std::deque>(argc, argv);
		// sort.vecData.numbers.push_back
			
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}

	// std::cout << "Straggler is: " << sort.getStraggler() << std::endl;

	return 0;
}
