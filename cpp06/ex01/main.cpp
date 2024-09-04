/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:06:30 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 18:55:46 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#define IN_GREEN(text) "\033[32m" << text << "\033[0m"
#define IN_RED(text) "\033[31m" << text << "\033[0m"

int main() {
	
	Data* info_initially = new Data("Mary Kate", 23);
	
	// Serialization of the pointer to my info:
	uintptr_t info_int_pointer = Serializer::serialize(info_initially);

	//deserialize the above pointer back to data* pointer
	Data* deserialisedInfo = Serializer::deserialize(info_int_pointer);

	if (info_initially == deserialisedInfo) {
		std::cout << IN_GREEN("Serialization and Deserialization were succesful.") << std::endl;
		std::cout << "The \"deserialisedInfo\" holds the data: " << std::endl;
		std::cout << "Name: " << deserialisedInfo->name << std::endl;
		std::cout << "Age: " << deserialisedInfo->age << std::endl;
	}
	else
		std::cout << IN_RED("Serialization and Deserialization did not work.") << std::endl;
	
	delete info_initially;

	return 0;
}
