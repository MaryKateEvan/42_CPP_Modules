/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:22:41 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 10:07:55 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA {
	
	private:
		std::string	_name;
		Weapon&	_weapon;

	public:
		void attack() const;
		HumanA(std::string name, Weapon& weapon); // Constructor
		~HumanA(); //destructor
};

#endif //HUMANA_HPP