/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:54:46 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/27 00:06:26 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>

# include "Fixed.hpp"

class Point {

	private:

		Fixed const _x;
		Fixed const _y;

	public:

		// Canonical Form elements:
		Point();								// default constructor
		Point(Point const & to_copy);			// copy constructor
		~Point();								// destructor
		Point & operator=(Point const & src);	// Copy assignment operator overload

		// Additional constructor, required by the subject:
		Point(const float x, const float y);

		// Getters for the x and y:
		const Fixed getX() const;
		const Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif //POINT_HPP