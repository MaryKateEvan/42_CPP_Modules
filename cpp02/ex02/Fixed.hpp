/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:40:01 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/24 22:21:26 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath> //for the roundf

class Fixed {

	private:

		int _fpnv; //for "Fixed-Point Number Value"
		static const int _fractBits = 8;

	public:

		Fixed();								// default constructor
		Fixed(Fixed const & to_copy);			// copy constructor
		Fixed(const int num);
		Fixed(const float float_num);
		~Fixed();								// destructor

		Fixed & operator=(Fixed const & src);	// Copy assignment operator overload

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(Fixed const & b);
		bool operator<(Fixed const & b);
		bool operator>=(Fixed const & b);
		bool operator<=(Fixed const & b);
		bool operator==(Fixed const & b);
		bool operator!=(Fixed const & b);
};

std::ostream & operator<<(std::ostream & out, Fixed const & i);

#endif //FIXED_HPP
