/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:16:11 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/20 17:01:49 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	
	if (argc < 2) {
		std::cerr << RED("❌ Error!") << std::endl;
		std::cout << UNDERLINE("Correct usage:") << BOLD(" ./PmergeMe int1 int2 int3 ...") << std::endl;
		return 1;
	}

	try {
		
		PmergeMe<std::vector> sort_vector;
		PmergeMe<std::deque> sort_deque;

		double vector_time = sort_vector.countTimeWhileSorting(argc, argv);
		double deque_time = sort_deque.countTimeWhileSorting(argc, argv);

		// OUTPUT that the SUBJECT wants:
		std::cout << BOLD(YELLOW("⏳ Before: "));
		sort_vector.printContainerNums(sort_vector.getInput());
		
		std::cout << BOLD(GREEN("✅ After: "));
		sort_vector.printContainerNums(sort_vector.getMainSeq());

		std::cout << CYAN("Time for vector: ") << vector_time << "ms" << std::endl;
		std::cout << CYAN("Time for deque: ") << deque_time << "ms" << std::endl;

		// MY ADDITIONAL CHECKS:
		bool check1 = sort_vector.isSorted(sort_vector.getMainSeq());
		bool check2 = sort_deque.isSorted(sort_deque.getMainSeq());
		if (check1 && check2)
			std::cout << GREEN("\nBoth containers are sorted!\n") << std::endl;
		else
			std::cout << RED("Something is not sorted!\n") << std::endl;
		std::cout << "Amount of numbers " << UNDERLINE("initially") << ", from the input: " << sort_vector.getInputSize() << std::endl;
		std::cout << "Amount of numbers " << UNDERLINE("eventually") << ", in the sorted \"main_seq\" container: " << sort_vector.getMainSeqSize() << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Error: " << UNDERLINE(e.what())) << std::endl;
	}

	return 0;
}
