/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 00:42:17 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/24 00:59:07 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>

/**
 * @brief Template Class that inherits from std::stack to reuse its functionality,
 * while adding the necessary/missing iterators. Std::stack uses internally another
 * container (usually std::deque), so we can expose the iterators of the underlying 
 * container (deque), which we access using the protected member `c`. 
 * to expose its iterators.
 * @note the class inherits the constructors and assignment operator overload of the
 * std::stack, so they don't have to be redefined here.
 */
template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	
	public:
		
		MutantStack() : std::stack<T, Container>() {} //default constructor
		MutantStack(MutantStack const & to_copy) : std::stack<T, Container>(to_copy) {} //copy constructor
		MutantStack& operator=(MutantStack const & src) {
			if (this != &src)
				std::stack<T, Container>::operator=(src);
				return *this;
		}
		~MutantStack() {}

		//Member functions to expose the iterators of deque:
		typename Container::iterator begin() {
			return this->c.begin();
		}
		typename Container::iterator end() {
			return this->c.end();
		}
		



};