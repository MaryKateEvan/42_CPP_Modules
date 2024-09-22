/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:07:06 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/23 00:55:05 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm> //for the std::find

template< typename T >
typename T::iterator easyfind(T & intContainer, int intToSearch) {
	
	typename T::iterator search = std::find(intContainer.begin(), intContainer.end(), intToSearch);
	
	if (search == intContainer.end())
		throw std::out_of_range("element not found");
	else
		return search;
} 