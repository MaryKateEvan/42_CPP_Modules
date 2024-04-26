/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:02:47 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/26 23:49:29 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define IN_GREEN(text) "\033[32m" << text << "\033[0m"
#define IN_RED(text) "\033[31m" << text << "\033[0m"

int main() {

	// The vertexes of the triangle:
	Point A(0.0f ,0.0f);
	Point B(6.0f, 0.0f);
	Point C(0.0f, 8.0f);

	// A. Points that should return TRUE:
	// -----------------------------------
	// i) obviously inside:
	Point t1(2.0f, 4.0f);
	Point t2(1.0f, 6.0f);
	Point t3(4.0f, 2.0f);
	// ii) close to the vertexes:
	Point t4(0.1f, 0.1f);
	Point t5(5.9f, 0.1f);
	Point t6(0.05f, 7.9f);

	// B. Points that should return FALSE:
	// -----------------------------------
	// i) obviously outside:
	Point f1(-2.0f, 4.0f);
	Point f2(7.0f, 2.0f);
	Point f3(2.0f, 8.0f);
	// ii) close to the vertexes:
	Point f4(-0.1f, 0.1f);
	Point f5(6.1f, -0.1f);
	Point f6(8.2f, 0.1f);

	//! Change here the fourth argument with the point you want to check:
	bool result = bsp(A, B, C, f1);

	// /* The three vertexes, as the fourth argument, should also return false: */
	// bool result = bsp(A, B, C, A);
	// bool result = bsp(A, B, C, B);
	// bool result = bsp(A, B, C, C);

	if (result == true)
		std::cout << IN_GREEN("\nThe point you provided is inside the triangle!\n") << std::endl;
	else
		std::cout << IN_RED("\nThe point you provided is NOT inside the triangle!\n") << std::endl;

	return 0;
}
