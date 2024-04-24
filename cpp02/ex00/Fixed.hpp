/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:40:01 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/24 02:41:43 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {

	private:

		int _fpnv; //for Fixed-Point Number Value
		static const int fract_bits = 8; //it means that i have 8 bits for the fractional part. So if the int is 32-bit, i would have 24 bits left for the integer part.

	public:

		Fixed();								// default constructor
		Fixed(Fixed const & to_copy);			// copy constructor
		~Fixed();								// destructor

		Fixed & operator=(Fixed const & src);	// Copy assignment operator overload

		int getRawBits(void) const;
		void setRawBits(int const raw);
};



#endif //FIXED_HPP