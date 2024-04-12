/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 06:31:09 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/12 07:43:21 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
//for the initial printing to user:
#include <cstdlib>
#include <thread>
#include <chrono>
//for the std::getline
#include <string>

void	greet_and_inform_user(std::string user) {
	
	std::cout << "Hi there " << user << "! \U0001F44B" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << std::endl;

	std::cout << "You can create here a " << BOLD("Phone Book") << " of maximum 8 contacts!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << std::endl;
	
	std::cout << "The available commands are:" << std::endl;
	std::cout << GREEN << "ADD" << RESET << ": adds a new contact in the PhoneBook." << std::endl;
	std::cout << BLUE << "SEARCH" << RESET << ": displays a specific contact you choose." << std::endl;
	std::cout << RED << "EXIT" << RESET << ": terminates this program and your contacts are lost forever!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(7));
	std::cout << std::endl;

	// std::cout << "Enjoy your Phone Book! \U0001F609" << std::endl;
	// std::this_thread::sleep_for(std::chrono::seconds(2));
	// std::cout << std::endl;
}

int main() {

	PhoneBook phone_book; //the instance of my PhoneBook class

	std::string	user_name = getenv("USER");
	std::string	command;

	greet_and_inform_user(user_name);
	
	
	
	while (1) {

		std::cout << "[Command to execute]: ";
		std::getline(std::cin, command);
		// std::cout << std::endl;
		
		if (command == "ADD")
			phone_book.add();
		else if (command == "SEARCH")
			phone_book.search();
		else if (command == "EXIT")
			break ;
		else {
			std::cout << "You can only use " << ADD << " or " << SEARCH << " or " << EXIT << "." << std::endl;
			std::cout << std::endl;
		}
	}
	return 0;
}