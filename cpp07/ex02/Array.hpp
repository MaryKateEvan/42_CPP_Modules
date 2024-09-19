/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:36:38 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/19 18:59:03 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

template< typename T >
class Array {
	
	private:

		T* _array;
		unsigned int _size;

	public:
	
		// Orthodox Canonical form elements:
		Array();									// default constructor
		Array(Array<T> const & to_copy);			// copy constructor
		~Array();									// destructor
		Array<T>& operator=(Array<T> const & src);	// Assignment operator overload

		//additional constructor asked from subject:
		Array(unsigned int n);

		T& operator[](unsigned int index); // [] operator overload to be able to access the elements of the array
	
		class IndexOutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw();  //override of the what() method
		};
		
		unsigned int size() const;
};

// to inform the compiler on the implementation of the above teplate class:
// #include "Array.tpp"

// default constructor
template< typename T >
Array<T>::Array() : _array(NULL), _size(0) {}

// the requested constructor
template< typename T >
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

// copy constructor
template< typename T >
Array<T>::Array(Array<T> const & to_copy) : _array(new T[to_copy._size]), _size(to_copy._size) {
	
	for (unsigned int i = 0; i < to_copy._size; ++i) {
		this->_array[i] = to_copy._array[i];
	}
}

template< typename T >
Array<T>& Array<T>::operator=(Array<T> const & src) {
	
}

// destructor
template< typename T >
Array<T>::~Array() {}

// EXCEPTION:
template< typename T >
const char* Array<T>::IndexOutOfBounds::what() const throw() {
	return "index is out of bounds!";
}

// the getter:
template< typename T >
unsigned int Array<T>::size() const {
	return this->_size;
}

