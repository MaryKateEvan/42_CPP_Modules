/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:00:41 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/12 10:46:39 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

// #include "Zombie.cpp"
// #include "newZombie.cpp"
// #include "randomChump.cpp"

class Zombie {

	private:
		std::string _name;

	public:
		Zombie( std::string name ); //constructor
		~Zombie( void ); //destructor
		void announce( void ) const;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif //ZOMBIE_HPP