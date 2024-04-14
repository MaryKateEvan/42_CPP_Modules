/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:02:28 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 10:12:55 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
	
	private:
		std::string	_name;
		Weapon*	_weapon;

	public:
		void attack() const;
		void setWeapon(Weapon& to_set);
		HumanB(std::string name); //constructor
		~HumanB(); //destructor
};

#endif //HUMANB_HPP