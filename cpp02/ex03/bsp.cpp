/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:54:51 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/26 23:34:00 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	// Coordinates of the point to check:
	Fixed pointX = point.getX();
	Fixed pointY = point.getY();

	// Coordinates of the three vertexes of the triange:
	Fixed aX = a.getX();
	Fixed aY = a.getY();
	Fixed bX = b.getX();
	Fixed bY = b.getY();
	Fixed cX = c.getX();
	Fixed cY = c.getY();

	Fixed zero(0);
	Fixed one(1);

	// the barycentric coordinates formula:
	Fixed denominator = (bY - cY) * (aX - cX) + (cX - bX) * (aY - cY);
	Fixed num1 = ((bY - cY) * (pointX - cX) + (cX - bX) * (pointY - cY)) / denominator;
	Fixed num2 = ((cY - aY) * (pointX - cX) + (aX - cX) * (pointY - cY)) / denominator;
	Fixed num3 = one - num1 - num2;

	return ((zero < num1 && num1 < one) && (zero < num2 && num2 < one) && (zero < num3 && num3 < one));
	// if i wanted the vertexes and edges to return also true, it would have to be everywhere in
	// the return statement "or equal to". like <=, >= etc...
}