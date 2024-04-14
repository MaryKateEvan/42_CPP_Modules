/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:13:50 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 15:34:11 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {

	Harl Harl_obj;

	// 1. Valid levels:
	Harl_obj.complain("debug");
	Harl_obj.complain("INFO");
	Harl_obj.complain("warning");
	Harl_obj.complain("ERROR");
	std::cout << std::endl;

	// 2. Invalid levels:
	Harl_obj.complain("hahaha");
	Harl_obj.complain("unacceptable");
	
	return (0);
}