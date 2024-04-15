/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 04:11:32 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/15 21:51:17 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
// #include "PhoneBook.cpp"
// #include "Contact.cpp"
// #include "PhoneBook.hpp"

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
		void displayLineForSearch(void) const ;
		void displayAllInfo( void ) const ;
};

#endif //CONTACT_HPP

//std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret