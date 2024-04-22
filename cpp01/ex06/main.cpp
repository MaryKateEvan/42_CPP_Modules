/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:13:50 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/22 02:03:56 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Expected syntax: " << argv[0] << " threshold_level" << std::endl;
		return 0;
	}
	
	Harl Harl_obj;

	Harl_obj.complain(argv[1]);

	return 0;
}