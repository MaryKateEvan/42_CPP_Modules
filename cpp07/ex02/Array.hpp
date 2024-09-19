/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:36:38 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/19 21:47:43 by mevangel         ###   ########.fr       */
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

		// [] operator overload to be able to access the elements of the array
		T& operator[](unsigned int index) const;
		
		//getter for the private attribute _size
		unsigned int size() const;
};

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

// the getter:
template< typename T >
unsigned int Array<T>::size() const {
	return this->_size;
}

// the alternative that i don't need my own exception:
template< typename T >
T& Array<T>::operator[](unsigned int index) const {
	
	if (index >= this->_size)
		throw std::out_of_range("index out of bounds");
	return (this->_array[index]);
}
