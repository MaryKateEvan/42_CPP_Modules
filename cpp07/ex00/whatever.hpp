/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:46:19 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/16 20:52:28 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template< typename Type>
void swap(Type & a, Type & b) {

	Type tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template< typename Type>
Type const & min(Type const & a, Type const & b) {
	return (a < b ? a : b);
}

template< typename Type>
Type const & max(Type const & a, Type const & b) {
	return (a > b ? a : b);
}
