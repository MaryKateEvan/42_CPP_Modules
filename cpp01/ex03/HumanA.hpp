/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:22:41 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/13 13:23:04 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA {
	
	private:
		Weapon&	_Weapon;
		
	public:
		std::string	name;
		void attack() const;
		HumanA(Weapon& weapon);
};

#endif //HUMANA_HPP