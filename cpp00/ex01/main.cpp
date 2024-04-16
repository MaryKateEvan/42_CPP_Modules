/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 06:31:09 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/16 17:52:56 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	greet_and_inform_user() {

	char* user_name_cstr = getenv("USER");
	
	if (user_name_cstr) {
		std::string user_name(user_name_cstr);
		std::cout << "Hi there " << user_name << "! \U0001F44B" << std::endl;
	}
	else
		std::cout << "Hi there! \U0001F44B" << std::endl;
	sleep(1);
	std::cout << std::endl;

	std::cout << "You can create here a " << BOLD("Phone Book") << " of maximum 8 contacts!" << std::endl;
	sleep(3);
	std::cout << std::endl;
	
	std::cout << "The available commands are:" << std::endl;
	std::cout << ADD << ": adds a new contact in the PhoneBook." << std::endl;
	std::cout << SEARCH << ": displays a specific contact you choose." << std::endl;
	std::cout << EXIT << ": terminates this program and your contacts are lost forever!" << std::endl;
	sleep(7);
	std::cout << std::endl;
}

//the version that woks on the mac:
// static void	greet_and_inform_user() {

// 	std::string	user_name = getenv("USER");
	
// 	if (user_name.c_str())
// 		std::cout << "Hi there " << user_name << "! \U0001F44B" << std::endl;
// 	else
// 		std::cout << "Hi there! \U0001F44B" << std::endl;
// 	// std::this_thread::sleep_for(std::chrono::seconds(1));
// 	std::cout << std::endl;

// 	std::cout << "You can create here a " << BOLD("Phone Book") << " of maximum 8 contacts!" << std::endl;
// 	// std::this_thread::sleep_for(std::chrono::seconds(3));
// 	std::cout << std::endl;
	
// 	std::cout << "The available commands are:" << std::endl;
// 	std::cout << ADD << ": adds a new contact in the PhoneBook." << std::endl;
// 	std::cout << SEARCH << ": displays a specific contact you choose." << std::endl;
// 	std::cout << EXIT << ": terminates this program and your contacts are lost forever!" << std::endl;
// 	// std::this_thread::sleep_for(std::chrono::seconds(7));
// 	std::cout << std::endl;
// }

int main() {

	greet_and_inform_user();
	
	PhoneBook phone_book;
	std::string	command;

	while (true) {

		std::cout << "[Command to execute]: ";
		if (!std::getline(std::cin, command) && std::cin.eof())
			exit(2); // if End-of-file encountered (Ctrl+D), break out of the loop.

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