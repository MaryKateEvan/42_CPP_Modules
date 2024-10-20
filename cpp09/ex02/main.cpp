/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:16:11 by mevangel          #+#    #+#             */
/*   Updated: 2024/10/20 08:28:05 by mevangel         ###   ########.fr       */
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

		std::cout << BOLD(YELLOW("⏳ Before: "));
		sort_vector.printContainerNums(sort_vector.getInput());
		std::cout << BOLD(GREEN("✅ After: "));
		sort_vector.printContainerNums(sort_vector.getMainSeq());

		std::cout << CYAN("Time for vector: ") << vector_time << std::endl;
		std::cout << CYAN("Time for deque: ") << deque_time << std::endl;
		
		
	}
	catch (const std::exception& e) {
		std::cout << RED("❗ Exception found: " << UNDERLINE(e.what())) << std::endl;
	}

	return 0;
}
