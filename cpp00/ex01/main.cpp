/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 06:31:09 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/15 22:41:16 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
//for the initial printing to user:
#include <cstdlib>
#include <thread>
#include <chrono>


void	greet_and_inform_user(void) {

	std::string	user_name = getenv("USER");
	
	std::cout << "Hi there " << user_name << "! \U0001F44B" << std::endl;
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

	greet_and_inform_user();
	
	PhoneBook phone_book; //the instance of my PhoneBook class
	std::string	command;

	while (1) {

		std::cout << "[Command to execute]: ";
		if (!std::getline(std::cin, command) && std::cin.eof())
			std::exit(2); // if End-of-file encountered (Ctrl+D), break out of the loop.

		if (command == "ADD") {
			phone_book.add();
			std::cout << std::endl;
		}
		else if (command == "SEARCH") {
			phone_book.search();
			std::cout << std::endl;
		}
		else if (command == "EXIT")
			break ;
		else {
			std::cout << "You can only use " << ADD << " or " << SEARCH << " or " << EXIT << "." << std::endl;
			std::cout << std::endl;
		}
	}
	return EXIT_SUCCESS;
}