/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:06:52 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/02 16:12:56 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main() {
	
	ScalarConverter::convert("w"); // Valid character
	ScalarConverter::convert("1"); // Valid character
	ScalarConverter::convert("\n"); // Non-displayable character
	ScalarConverter::convert("ab"); // Invalid: more than one character
	ScalarConverter::convert("");   // Invalid: empty string

	return 0;
}