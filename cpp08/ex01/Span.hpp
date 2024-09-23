/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:18:57 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/23 23:27:05 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <numeric> //for the std::adjacent_difference
#include <climits>

#define BOLD(text) "\033[1m" << text << "\033[0m"

class Span {

	private:
	
		Span();						// default constructor
		unsigned int _maxStorage;	// the maximum capacity of the _vec
		std::vector<int> _vec;		// the array to store all the integers

	public:

		Span(Span const & to_copy);			// copy constructor
		Span& operator=(Span const & src);	// Assignment operator overload
		~Span();							// destructor

		// Parameter constructor
		Span(unsigned int N);

		// requested member functions:
		void addNumber(int num);
		size_t shortestSpan() const;
		size_t longestSpan() const;

		// helper functions:
		void printNumbers() const;
		size_t getSize() const;

		// custom exception classes, as subclasses of the Span
		class SpanOutOfSpaceException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};
		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};

		// template function to allow Span to add multiple numbers, like from another container, to the current vector.
		template<typename InputIterator>
		void addNumsFromRange(InputIterator begin, InputIterator end) {
			if (std::distance(begin, end) + _vec.size() > _maxStorage)
				throw SpanOutOfSpaceException();
			_vec.insert(_vec.end(), begin, end);
		}
};
