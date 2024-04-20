/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 04:11:32 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/20 22:54:39 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip> //for the std::setw
# include <cstdlib> //for the exit

# define UNDERLINE(text) "\033[4m" << text << "\033[0m"
# define IN_GREEN(text) "\033[32m" << text << "\033[0m"

class Contact {

	private:
	
		short 		index;
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
	
		Contact();
		~Contact();
		void setContactDetails(short idx);
		void displayLineForSearch() const ;
		void displayAllInfo() const ;
};

#endif //CONTACT_HPP
