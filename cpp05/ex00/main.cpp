/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:00:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/07/31 10:21:19 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	
	Bureaucrat a;
	Bureaucrat b("Mary Kate", 10);
	Bureaucrat c = b;
	
	std::cout << a << b << c ;

	return 0;
}
