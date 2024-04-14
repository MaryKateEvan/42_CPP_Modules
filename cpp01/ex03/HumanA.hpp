/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:22:41 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 09:15:18 by mevangel         ###   ########.fr       */
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
		// The constructor takes the Weapon in HumanA:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
};

#endif //HUMANA_HPP