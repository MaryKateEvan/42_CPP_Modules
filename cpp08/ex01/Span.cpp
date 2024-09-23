/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:18:54 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/23 21:20:19 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span() : _maxStorage(0) {}

// Parameter constructor
Span::Span(unsigned int N) : _maxStorage(N) {
	this->_vec.reserve(_maxStorage);
}

// Copy constructor
Span::Span(Span const & to_copy) : _maxStorage(to_copy._maxStorage), _vec(to_copy._vec) {}

// Copy assignment Operator overload
Span& Span::operator=(Span const & src) {

	if (this != &src) {
		this->_maxStorage = src._maxStorage;
		this->_vec = src._vec;
	}
	return *this;
}

// Destructor
Span::~Span () {}


void Span::addNumber(int num) {
	
	if (_vec.size() < _maxStorage)
		_vec.push_back(num);
	else
		throw SpanOutOfSpaceException();
}

size_t Span::shortestSpan() const {

	if (_vec.size() <= 1)
		throw NotEnoughNumbersException();
		
	//we create a temporary copy of the vector to sort, so that this method in const
	std::vector<int> sorted_vec = _vec;
	std::sort(sorted_vec.begin(), sorted_vec.end()); 

	//then we use the adjacent_difference to calculate the differences between consecutive elements in the sorted_vec
	std::vector<int> differences(sorted_vec.size());
	std::adjacent_difference(sorted_vec.begin(), sorted_vec.end(), differences.begin()); //this saves the differences in the `differences` vector

	//so then we return the minimum of all the differences (we pass the first element only cause it is just itself, not the difference with the second element)
	return (static_cast<size_t>(*std::min_element(differences.begin() + 1, differences.end())));
}

size_t Span::longestSpan() const {
	
	if (_vec.size() <= 1)
		throw NotEnoughNumbersException();

	// auto, instead of the actual huge type: std::pair<std::vector<int>::iterator, std::vector<int>::iterator>
	auto min_max_pair = std::minmax_element(_vec.begin(), _vec.end());
	return (static_cast<size_t>(*min_max_pair.second - *min_max_pair.first)); // because .second has saved the max and .first has saved the min
}



// // Override of the what method in the two custom exceptions:
const char* Span::SpanOutOfSpaceException::what() const throw() {
	return "span out of space!";
}
const char* Span::NotEnoughNumbersException::what() const throw() {
	return "not enough numbers in the span";
}
// const char* Span::AlreadySignedException::what() const throw() {
// 	return "Span is already signed!";
// }