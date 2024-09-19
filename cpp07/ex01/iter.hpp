/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 03:45:36 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/19 18:10:32 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

/**
 * @brief: template function that applies the passed `function` in all the
 * elements of the passed `array`
 * @param array of typename A : the address of an array of elements
 * @param len: the number of elements in that array
 * @param function: the function to be called on every element of the array
 */
template< typename A, typename ft >
void iter(A& array, size_t len, ft function) {
	for (size_t i = 0; i < len; ++i)
		function(array[i]);
}


