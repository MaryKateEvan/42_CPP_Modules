/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:46:19 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/06 23:03:40 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

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

#endif //WHATEVER_HPP