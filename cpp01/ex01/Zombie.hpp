/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:00:41 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/12 12:41:15 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <new>

class Zombie {

	private:
		std::string _name;

	public:
		void setName( std::string name);
		//no constructor, so the default one will be used
		void announce( void ) const;
		~Zombie( void ); //destructor
};

Zombie*	zombieHorde( int N, std::string name );

#endif //ZOMBIE_HPP