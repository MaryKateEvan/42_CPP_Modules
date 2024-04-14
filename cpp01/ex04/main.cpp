/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:56:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 11:50:11 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

static std::string replace_s1_with_s2(char* argv[], std::string& content) {

	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	std::string result;

	size_t pos = content.find(s1); // to find the first occurence of s1.
	size_t s1_len = s1.length();
	
	result = content.substr(0, pos) + s2;
	while (pos != std::string::npos) { // =while the pos is not equal with the index of the last character of the string
		pos += content.find(s1, pos + s2.length());
	// 	result
		
	// 	content = content.substr(0, pos) + s2 + content.substr(pos + s1_len);
	}
}

int main(int argc, char* argv[]) {

	// Error handling for wrong number of arguments:
	if (argc != 4) {
		std::cerr << "Expected 3 Arguments: filestream s1 s2" << std::endl;
		return 0;
	}

	std::string input_file = argv[1];
	
	std::ifstream in_stream(input_file);
	//in case the file doesn't exist:
	if (!in_stream) {
		std::cerr << "Error: file couldn't open or doesn't exist" << std::endl;
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


	content = replace_s1_with_s2(argv, content);

	std::string output_file = input_file += ".replace";
	std::ofstream out_stream(output_file);
	if (!out_stream) {
		std::cerr << "Error: couldn't create the " << output_file << " file." << std::endl;
		return 1; 
	}
	
	// And now we write the "content" to the output_file:
	out_stream << content;
	
	out_stream.close();

	//? The example of the intra video:
	// std::ifstream ifs("numbers.txt"); //like the fd in c
	// unsigned int	dst;
	// unsigned int	dst2;

	// //read from the input filestream:
	// ifs >> dst >> dst2;

	// std::cout << dst << " " << dst2 << std::endl;
	// ifs.close(); //i need to close the filestream at the end
	

	// std::ofstream ofs("test.out");

	// ofs << "i like ponies" << std::endl;
	// ofs.close();
	
	return (0);
}