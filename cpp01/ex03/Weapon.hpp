/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:04:06 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 08:45:45 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {

	private:
		std::string _type;

	public:
		std::string const & getType() const;
		void setType(std::string new_one);
		Weapon(std::string new_type);
		~Weapon(); //? do i actually need a destructor?
};

#endif //WEAPON_HPP