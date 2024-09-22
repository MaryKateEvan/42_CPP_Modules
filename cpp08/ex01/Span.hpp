/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:18:57 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/23 01:57:09 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <vector>

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

		//member functions:
		void addNumber(int& num);
		size_t shortestSpan() const;
		size_t longestSpan() const;

		// custom exception classes, as subclasses of the Span
		class SpanOutOfSpaceException : public std::exception {
			public:
				virtual const char* what() const throw(); //override of the what() method
		};
		// class GradeTooLowException : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw(); //override of the what() method
		// };
		// class AlreadySignedException : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw(); //override of the what() method
		// };
};

// Insertion operator overload
std::ostream & operator<<(std::ostream & out, Span const & b);
