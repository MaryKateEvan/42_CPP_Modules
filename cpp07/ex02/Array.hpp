/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:36:38 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/19 20:02:23 by mevangel         ###   ########.fr       */
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
		Array<T>& operator=(Array<T> const & src);	// Assignment operator overload
		~Array();									// destructor

		//additional constructor asked from subject:
		Array(unsigned int n);

		T& operator[](unsigned int index) const; // [] operator overload to be able to access the elements of the array
	
		// class IndexOutOfBoundsException : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw();  //override of the what() method
		// };
		
		unsigned int size() const;
};

// to inform the compiler on the implementation of the above teplate class:
// #include "Array.tpp"

// default constructor
template< typename T >
Array<T>::Array() : _array(NULL), _size(0) {}

// the requested parameter constructor
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
	
	if (this != &src) {
		// Only if sizes differ, i need to reallocate memory:
		if (this->_size != src._size) {
			delete[] _array; //free the current memory
			_size = src._size; //update the current size with the source's size
			_array = new T[_size]; //allocate new memory for the new size
		}
		//and then we copy the elements from the source array to the current array:
		for (unsigned int i = 0; i < this->_size; ++i) {
			this->_array[i] = src._array[i];
		}
	}
	return (*this);
}

// destructor
template< typename T >
Array<T>::~Array() {
	delete[] this->_array;
}

// // EXCEPTION:
// template< typename T >
// const char* Array<T>::IndexOutOfBoundsException::what() const throw() {
// 	return "index is out of bounds!";
// }

// the getter:
template< typename T >
unsigned int Array<T>::size() const {
	return this->_size;
}

// template< typename T >
// T& Array<T>::operator[](unsigned int index) const {
	
// 	if (index >= this->_size)
// 		throw IndexOutOfBoundsException();
// 	return (_array[index]);
// }

// the alternative that i don't need my own exception:
template< typename T >
T& Array<T>::operator[](unsigned int index) const {
	
	if (index >= this->_size)
		throw std::out_of_range("index out of bounds");
	return (this->_array[index]);
}