/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:40:01 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/24 01:50:24 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {

	private:


	public:

		Fixed();								// constructor
		Fixed(Fixed const & to_copy);			// copy constructor
		~Fixed();								// destructor
		
		Fixed & operator=(Fixed const & src);	// Copy assignment operator
};



#endif //FIXED_HPP