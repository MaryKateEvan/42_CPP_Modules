/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 00:14:08 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/24 01:04:52 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <cstdlib>  // for rand()

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define RED(text) "\033[31m" << text << "\033[0m"
#define CYAN(text) "\033[1;96m" << text << "\033[0m"

int main() {
	
	std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("             TEST 1️⃣ : Creation of Array objects     ")) << std::endl;
	std::cout << CYAN("------------------------------------------------------------") << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);


	// std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("      TEST 2️⃣ : Assignment operator & Copy constructor     ")) << std::endl;
	// std::cout << CYAN("------------------------------------------------------------") << std::endl;
	


	// std::cout << CYAN("\n------------------------------------------------------------") << std::endl;
	// std::cout << CYAN(BOLD("         TEST 3️⃣ : Trying to access out of range:          ")) << std::endl;
	// std::cout << CYAN("------------------------------------------------------------") << std::endl;


	
	return 0;
}