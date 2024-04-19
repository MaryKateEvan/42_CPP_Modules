/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 04:11:32 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/19 23:45:59 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip> //for the std::setw
# include <cstdlib> //for the exit and atoi

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
		std::string receiveInputFor(std::string wanted_info, std::string type) const ;
		bool InputIsValid(std::string input, std::string type) const ;
		void displayLineForSearch() const ;
		void displayAllInfo() const ;
		std::string cut_string(std::string str) const ;
};

#endif //CONTACT_HPP

//std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret