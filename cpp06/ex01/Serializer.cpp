/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:06:46 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 18:39:53 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// default constructor
Serializer::Serializer() {}

// Copy constructor
Serializer::Serializer(Serializer const & to_copy) {
	
	//no attributes to be copied, so nothing to be done here
	(void)to_copy;
}

// Destructor
Serializer::~Serializer () {}

// Copy assignment Operator overload
Serializer& Serializer::operator=(Serializer const & src) {

	// no attributes to be assigned
	(void)src;
	return *this;
}

// Converts the pointer `ptr` to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr) {
	
	return reinterpret_cast<uintptr_t>(ptr);
}

// Converts the unsgined integer raw back to a pointer to Data
Data* Serializer::deserialize(uintptr_t raw) {
	
	return reinterpret_cast<Data *>(raw);
}
