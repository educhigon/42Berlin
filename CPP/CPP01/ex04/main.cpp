/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/02 18:33:37 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av) {
// three parameters in the following order: a filename and two strings, s1 and s2

	if (ac != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::string text;
	std::string string;
	try {
			std::ifstream file(filename.c_str());
			if (!file.is_open()) {
					throw std::runtime_error("Could not open file");
			}

			std::getline(file, string);
			while(file.eof() == false)
			{
				text += string;
				text += "\n";
				std::getline(file, string);
			}
			file.close();
	} catch (const std::exception& e) {
			std::cout << "File error: " << e.what() << std::endl;
	}

	if (s1.length() != 0)
	{
		int pos = text.find(s1, 0);
		while(pos != -1)
		{
			text = text.erase(pos, s1.length());
			text = text.insert(pos, s2);
			pos = text.find(s1, pos + s2.length());
		}
	}
	std::ofstream outfile((filename+".replace").c_str());
	outfile << text;
	outfile.close();

	return 0;
}
