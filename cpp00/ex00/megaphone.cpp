/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 05:28:47 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/20 20:44:33 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; argv[i]; i++) {
		for (int j = 0; argv[i][j]; j++) {
			std::cout << (char)std::toupper((int)argv[i][j]);
		}
	}
	std::cout << std::endl;
	
	return 0;
}
