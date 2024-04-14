/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:56:20 by mevangel          #+#    #+#             */
/*   Updated: 2024/04/14 13:06:31 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

static std::string replace_s1_with_s2(char* argv[], std::string content) {

	std::string s1 = argv[2]; //to be changed
	std::string s2 = argv[3]; //the new value
	
	std::string ret;

	// size_t s1_len = s1.length();
	size_t s1_idx = content.find(s1, 0); // to find the first occurence of s1.
	size_t start_idx = 0;
	
	while (start_idx != std::string::npos) { // =while the start_idx is not equal with the index of the last character of the string
		ret += (content.substr(start_idx, s1_idx - start_idx) + s2);
		start_idx = s1_idx + s1.length();
		s1_idx = content.find(s1, start_idx);
		
	// 	content = content.substr(0, pos) + s2 + content.substr(pos + s1_len);
	}
	return (ret);
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