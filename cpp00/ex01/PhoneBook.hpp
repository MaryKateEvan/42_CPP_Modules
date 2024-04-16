/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 05:47:06 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/16 13:59:45 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"
// # include "PhoneBook.cpp"

// Text color
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Background color
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define ITALIC(text) "\033[3m" << text << "\033[0m"

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