/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:36:38 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/17 00:10:20 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template< typename T >
class Array {
	
	private:

		T* _array;
		size_t _size;

	public:
	
		// Orthodox Canonical form elements:
		Array();								// default constructor
		Array(Array const & to_copy);			// copy constructor
		~Array();								// destructor
		Array& operator=(Array const & src);	// Assignment operator overload

		//additional constructor asked form subject:
		Array(unsigned int n);

		T& operator[](size_t index); // [] operator overload to be able to access the elements of the array
	
		class IndexOutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw();  //override of the what() method
		};
		
		size_t size() const;
};

// to inform the compiler on the implementation of the above teplate class:
#include "Array.tpp"

