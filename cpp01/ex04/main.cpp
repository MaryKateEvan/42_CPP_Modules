/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:56:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/22 01:35:38 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define ERROR "\033[31m" << "ERROR: " << "\033[0m"
#define BOLD(text) "\033[1m" << text << "\033[0m"

static std::string replace_s1_with_s2(char **argv, std::string content) {

	std::string s1 = argv[2]; //the str to be changed
	if (s1.empty() == true)
		return content;

	std::string s2 = argv[3]; //the new str, to change the occurences of s1 with
	std::string ret;

	size_t s1_idx = content.find(s1, 0); // finds the first occurence of s1.
	size_t start_idx = 0;
	
	//if the s1 is not found inside content, the find() will return the size_t npos
	while (s1_idx != std::string::npos) { // :while s1_idx is not equal with the index of the last character of the string

		ret += (content.substr(start_idx, s1_idx - start_idx) + s2);
		start_idx = s1_idx + s1.length();
		s1_idx = content.find(s1, start_idx);
	}
	ret += content.substr(start_idx); //to add the remainings of content after the last occurence of s1

	return ret;
}

int main(int argc, char **argv) {

	// Error handling for wrong number of arguments:
	if (argc != 4) {
		std::cerr << ERROR << "Expected syntax: " << BOLD("./replace filestream s1 s2") << std::endl;
		return 0;
	}

	// For the input file:
	std::string input_file = argv[1];
	std::ifstream in_stream(input_file.c_str());
	if (!in_stream) {
		std::cerr << ERROR << "file can not open or doesn't exist" << std::endl;
		return 1; 
	}

	// In order to read all the file and save it to "content" variable:
	std::string content;
	std::string line;
	while (std::getline(in_stream, line)) {
		content += line;
		if (!in_stream.eof()) {
			content += '\n';
		}
	}
	in_stream.close();

	// the main replace function:
	content = replace_s1_with_s2(argv, content);

	// Copy the modified content to the output.file:
	std::string output_file = input_file += ".replace";
	std::ofstream out_stream(output_file.c_str());
	if (!out_stream) {
		std::cerr << "Error: couldn't create the " << output_file << " file." << std::endl;
		return 1; 
	}
	
	// Write the "content" to the output_file and close the ofstream:
	out_stream << content;
	out_stream.close();

	return 0;
}