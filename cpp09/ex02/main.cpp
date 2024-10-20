/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:16:11 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/20 10:33:22 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	
	if (argc < 2) {
		std::cerr << RED("❌ Error!") << std::endl;
		std::cout << UNDERLINE("Correct usage:") << BOLD(" ./PmergeMe int1 int2 int3 ...") << std::endl;
		return 1;
	}

	std::cout << "i gave " << argc - 1 << " numbers.\n" << std::endl;

	try {
		
		PmergeMe<std::vector> sort_vector;
		PmergeMe<std::deque> sort_deque;

		double vector_time = sort_vector.countTimeWhileSorting(argc, argv);
		double deque_time = sort_deque.countTimeWhileSorting(argc, argv);

		std::cout << BOLD(YELLOW("⏳ Before: "));
		sort_vector.printContainerNums(sort_vector.getInput());
		std::cout << BOLD(GREEN("✅ After: "));
		sort_vector.printContainerNums(sort_vector.getMainSeq());

		std::cout << CYAN("Time for vector: ") << vector_time << "ms" << std::endl;
		std::cout << CYAN("Time for deque: ") << deque_time << "ms" << std::endl;
		
		
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Error: " << UNDERLINE(e.what())) << std::endl;
	}

	return 0;
}
