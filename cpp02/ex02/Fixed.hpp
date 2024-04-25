/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:40:01 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/25 02:54:27 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath> //for the roundf

class Fixed {

	private:

		int _fixedPointValue;
		static const int _fractBits = 8;

	public:

		Fixed();								// default constructor
		Fixed(Fixed const & to_copy);			// copy constructor
		Fixed(const int num);
		Fixed(const float float_num);
		~Fixed();								// destructor

		Fixed & operator=(Fixed const & src);	// Copy assignment operator overload

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;

		// Comparison operators overload:
		bool operator>(Fixed const & b);
		bool operator<(Fixed const & b);
		bool operator>=(Fixed const & b);
		bool operator<=(Fixed const & b);
		bool operator==(Fixed const & b);
		bool operator!=(Fixed const & b);

		// Arithmetic operators overload:
		Fixed operator+(Fixed const & y);
		Fixed operator-(Fixed const & y);
		Fixed operator*(Fixed const & y);
		Fixed operator/(Fixed const & y);

		// Increment/Decrement operators overload:
		Fixed & operator++();	// Pre-increment
		Fixed & operator--();	// Pre-decrement
		Fixed operator++(int);	// Post-increment
		Fixed operator--(int);	// Post-decrement
};

std::ostream & operator<<(std::ostream & out, Fixed const & i);

#endif //FIXED_HPP