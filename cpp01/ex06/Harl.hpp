/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:13:55 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 15:10:53 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		void complain( std::string level );
};

#endif //HARL_HPP