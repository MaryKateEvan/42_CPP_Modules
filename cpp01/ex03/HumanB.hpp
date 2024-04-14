/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:02:28 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 09:07:24 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
	
	private:
		Weapon*	_weapon;
		std::string	_name;

	public:
		void attack() const;
		// The constructor doesn't take the Weapon in HumanB:
		HumanB(std::string name);
		~HumanB();
};

#endif //HUMANB_HPP