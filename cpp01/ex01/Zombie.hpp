/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:00:41 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/22 00:13:18 by mevangel         ###   ########.fr       */
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
	
		Zombie();
		~Zombie();
		void setName(std::string name);
		void announce(void) const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif //ZOMBIE_HPP