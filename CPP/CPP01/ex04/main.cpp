/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/03 11:22:33 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

int replacer(std::string filename, std::string s1, std::string s2)
{
	std::string text;
	std::string string;

	try {
			std::ifstream file(filename.c_str());
			if (!file.is_open()) {
					throw std::runtime_error("Could not open IN file");
			}

			std::getline(file, string);
			while(file.eof() == false)
			{
				text += string + "\n";
				std::getline(file, string);
			}
			text += string;
			file.close();
	} catch (const std::exception& e) {
			std::cout << "File error: " << e.what() << std::endl;
			return 1;
	}

	if (s1.length() != 0)
	{
		size_t pos = text.find(s1, 0);
		while(pos != std::string::npos)
		{
			text = text.erase(pos, s1.length());
			text = text.insert(pos, s2);
			pos = text.find(s1, pos + s2.length());
		}
	}

	try
	{
		std::ofstream outfile((filename+".replace").c_str());
		if (!outfile.is_open()) {
				throw std::runtime_error("Could not open OUT file");
		}
		outfile << text;
		outfile.close();
	}
	catch (const std::exception& e) {
			std::cout << "File error: " << e.what() << std::endl;
			return 1;
	}

	return 0;
}

void tester(std::string filename, std::string s1, std::string s2, std::string expected)
{
	std::string string_test;
	std::string text_test;
	replacer(filename, s1, s2);

	std::ifstream outfile((filename+".replace").c_str());
	if (!outfile.is_open()) {
			throw std::runtime_error("Could not open OUT file");
	}
	std::getline(outfile, string_test);
	while(outfile.eof() == false)
	{
		text_test += string_test + "\n";
		std::getline(outfile, string_test);
	}
	text_test += string_test;
	outfile.close();
	if (text_test == expected)
	{
		std::cout << "Test passed for s1: '" << s1 << "' and s2: '" << s2 << "'" << std::endl;
	}
	else
	{
		std::cout << "Test failed for s1: '" << s1 << "' and s2: '" << s2 << "'" << std::endl;
		std::cout << "Expected: '" << expected << "'" << std::endl;
		std::cout << "Got:      '" << text_test << "'" << std::endl;
	}
	return;
}


int main(int ac, char **av) {

	if (ac == 2 && av[1][0] == '-' && av[1][1] == 't')
	{
		std::cout << "Running tests" << std::endl;
		std::cout << "\n===>  non existent text" << std::endl;
		tester("text.txt", "aaaaaa", "xx", "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n");
		std::cout << "\n===>  find and replace" << std::endl;
		tester("text.txt", "aaaa", "xx", "xx\nbbbb\ncccc\ndddd\neeee\n\nxxbbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n");
    tester("text.txt", "aaa", "xx", "xxa\nbbbb\ncccc\ndddd\neeee\n\nxxabbbbccccddddeeee\nxxbbbcccdddeee\naabbccddee\nabcde\n");
    tester("text.txt", "aa", "xx", "xxxx\nbbbb\ncccc\ndddd\neeee\n\nxxxxbbbbccccddddeeee\nxxabbbcccdddeee\nxxbbccddee\nabcde\n");
		tester("text.txt", "a", "xx", "xxxxxxxx\nbbbb\ncccc\ndddd\neeee\n\nxxxxxxxxbbbbccccddddeeee\nxxxxxxbbbcccdddeee\nxxxxbbccddee\nxxbcde\n");
		std::cout << "\n===>  empty s1" << std::endl;
		tester("text.txt", "", "xx", "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n");
		std::cout << "\n===>  replace new lines" << std::endl;
		tester("text.txt", "\n", "xx", "aaaaxxbbbbxxccccxxddddxxeeeexxxxaaaabbbbccccddddeeeexxaaabbbcccdddeeexxaabbccddeexxabcdexx");
		std::cout << "\n===>  empty s2" << std::endl;
		tester("text.txt", "a", "", "\nbbbb\ncccc\ndddd\neeee\n\nbbbbccccddddeeee\nbbbcccdddeee\nbbccddee\nbcde\n");
		std::cout << "\n===>  s1 == s2" << std::endl;
		tester("text.txt", "a", "a", "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n");
		std::cout << "\n===>  s1 bigger than text" << std::endl;
		tester("text.txt", "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\naaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n", "xx", "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n");
		std::cout << "\n===>  empty file" << std::endl;
		tester("empty.txt", "a", "xx", "");
		std::cout << "\n===>  only bl - no match" << std::endl;
		tester("bl.txt", "a", "xx", "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		std::cout << "\n===>  only bl - match" << std::endl;
		tester("bl.txt", "\n", "xx", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

		std::cout << "\n\n ----- Cleaning up files -----" << std::endl;
		system("rm -f test.txt.replace bl.txt.replace empty.txt.replace");
		return 0;
	}

	if (ac != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	replacer(filename, s1, s2);
	return 0;

}
