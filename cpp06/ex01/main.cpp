/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:06:30 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 19:11:21 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#define IN_GREEN(text) "\033[32m" << text << "\033[0m"
#define IN_RED(text) "\033[31m" << text << "\033[0m"
#define BOLD(text) "\033[1m" << text << "\033[0m"
#define UNDERLINE(text) "\033[4m" << text << "\033[0m"

int main() {
	
	Data info_initially = Data("Mary Kate", 23);
	
	std::cout << UNDERLINE("\nOriginal data are:") << std::endl;
	std::cout << "Name: " << info_initially.name << std::endl;
	std::cout << "Age: " << info_initially.age << std::endl;
	
	// Serialization of the pointer to my info:
	uintptr_t info_int_pointer = Serializer::serialize(&info_initially);

	//deserialize the above pointer back to data* pointer
	Data* deserialisedInfo = Serializer::deserialize(info_int_pointer);

	if (deserialisedInfo == &info_initially) {
		std::cout << IN_GREEN("\nSerialization and Deserialization were succesful.\n") << std::endl;
		std::cout << UNDERLINE("Data after the deserialization:") << std::endl;
		std::cout << "Name: " << deserialisedInfo->name << std::endl;
		std::cout << "Age: " << deserialisedInfo->age << std::endl << std::endl;
	}
	else
		std::cout << IN_RED("Serialization and Deserialization did not work.") << std::endl;

	return 0;
}
