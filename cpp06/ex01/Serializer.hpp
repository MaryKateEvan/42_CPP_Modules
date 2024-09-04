/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:06:41 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 18:27:49 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <cstdint> // For uintptr_t

# include "Data.hpp"

struct Serializer {
	
	private:

		Serializer(); //private default constructor cause we don't want the Class to be instanciablee
	
	public:

		Serializer(Serializer const & to_copy);			// copy constructor
		~Serializer();									// destructor
		Serializer& operator=(Serializer const & src);	// Assignment operator overload
		
		//the methods asked form the subject:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif //SERIALIZER_HPP