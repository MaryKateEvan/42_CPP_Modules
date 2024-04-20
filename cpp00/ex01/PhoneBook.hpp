/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 05:47:06 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/20 22:53:39 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstdlib> //for the getenv, exit and atoi
# include <unistd.h> //for the sleep

# include "Contact.hpp"

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define BOLD_UNDERLINE(text) "\033[1;4m" << text << "\033[0m"

# define ADD "\033[32m" << "ADD" << "\033[0m" //in green
# define SEARCH "\033[34m" << "SEARCH" << "\033[0m" //in blue
# define EXIT "\033[31m" << "EXIT" << "\033[0m" //in red

class PhoneBook {
	
	private:

		Contact contacts[8];
		short idx_to_add;
		short sum_contacts;

	public:
	
		PhoneBook();
		~PhoneBook();
		void add();
		void search() const;
};

#endif // PHONEBOOK_HPP