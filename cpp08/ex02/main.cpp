/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 00:14:08 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/26 00:13:01 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"
#define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"
#define RED(text) "\033[31m" << text << "\033[0m"
#define CYAN(text) "\033[1;96m" << text << "\033[0m"

int main() {
	
	std::cout << CYAN("\n---------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("                   A) SUBJECT'S TEST:     ")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	
	std::cout << UNDERLINE("1. Result using MutantStack:") << std::endl;
	{
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
	}
	std::cout << UNDERLINE("\n2. Result using list:") << std::endl;
	/* modifications from mstack --to--> list:
	stack.push() --becomes--> list.push_back()
	stack.pop() ----> list.pop_back()
	stack.top ----> list.back()
	because the list has two ends but stack only one, the `top`
	*/
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(mstack);
	}

	std::cout << CYAN("\n---------------------------------------------------------") << std::endl;
	std::cout << CYAN(BOLD("                  B) ADDITIONAL TESTS:     ")) << std::endl;
	std::cout << CYAN("---------------------------------------------------------") << std::endl;
	
	std::cout << BOLD_UNDERLINE(CYAN("\n1️⃣  Testing the inherited methods from stack:\n")) << std::endl;
	MutantStack<int> mstack;
	// filling the stack with 10 numbers:
	for (int i = 0; i < 10; ++i)
		mstack.push(i * 42);
	if (mstack.empty() == false)
		std::cout << "mstack has size " << BOLD(mstack.size()) << std::endl;
	mstack.pop();
	mstack.pop();
	std::cout << "After " << UNDERLINE("popping 2 times") << ", mstack has size: " << BOLD(mstack.size()) << std::endl;
	std::cout << "Top element holds the number: " << mstack.top() << std::endl;

	/******************************************************************************************************/
	std::cout << BOLD_UNDERLINE(CYAN("\n2️⃣  Testing the CONST iterators:\n")) << std::endl;
	
	std::cout << "The mstack holds the numbers: ";
	for (MutantStack<int>::const_iterator cit = mstack.cbegin(); cit != mstack.cend(); ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;
	
	std::cout << "Or in " << BOLD("reverse iteration: ");
	for (MutantStack<int>::const_reverse_iterator crit = mstack.crbegin(); crit != mstack.crend(); ++crit)
		std::cout << *crit << " ";
	std::cout << std::endl;

	/******************************************************************************************************/
	std::cout << BOLD_UNDERLINE(CYAN("\n3️⃣  Testing the \"normal\" (non-const) iterators:\n")) << std::endl;
	// Modification of the mstack's elements by division with 2 and then adding 10:
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		*it /= 2;
	std::cout << "Current image of the mstack, after " << UNDERLINE("modifying the elements") << ":" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		*rit += 10;
		std::cout << *rit << std::endl;
	}

	/******************************************************************************************************/
	std::cout << BOLD_UNDERLINE(CYAN("\n4️⃣  Testing the copy constructor && assignment operator:\n")) << std::endl;
	
	MutantStack<int> test1(mstack); //to call copy constructor
	std::cout << "mstack \"test1\" has size " << BOLD(test1.size()) << std::endl; //should have the same size as `mstack` which is currently 8
	test1.pop();
	test1.pop();
	test1.pop(); //popping 3 times, leave the test1 stack with size 5.
	
	MutantStack<int> test2 = test1; //to call assignment operator
	std::cout << "\nmstack \"test2\" has size " << BOLD(test2.size()) << " and holds the numbers:" << std::endl;

	for (MutantStack<int>::const_reverse_iterator crit = test2.crbegin(); crit != test2.crend(); ++crit)
		std::cout << *crit << std::endl;
	std::cout << std::endl;

	return 0;
}