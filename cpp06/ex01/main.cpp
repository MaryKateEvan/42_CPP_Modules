/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:06:30 by mevangel          #+#    #+#             */
/*   Updated: 2024/09/04 18:19:32 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint> // For uintptr_t

int main() {
	
	int x = 42;
	int* ptr = &x;

	// Convert pointer to uintptr_t
	uintptr_t ptr_as_int = reinterpret_cast<uintptr_t>(ptr);

	// Output the integer value of the pointer
	std::cout << "Pointer as integer: " << ptr_as_int << std::endl;

	// Convert the integer back to a pointer
	int* ptr_again = reinterpret_cast<int*>(ptr_as_int);

	// Output the value pointed to by the pointer
	std::cout << "Value pointed to: " << *ptr_again << std::endl;

	return 0;
}
