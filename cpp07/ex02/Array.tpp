/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:20:12 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/17 00:30:23 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// default constructor
template< typename T >
Array<T>::Array() : _array(NULL), _size(0) {}

// copy constructor
template< typename T >
Array<T>::Array(Array<T> const & to_copy) {

}

template< typename T >
Array<T>& Array<T>::operator=(Array<T> const & src) {
	
}

// destructor
template< typename T >
Array<T>::~Array() {}



// the getter:
size_t Array<T>::size() const {
	return this->_size;
}