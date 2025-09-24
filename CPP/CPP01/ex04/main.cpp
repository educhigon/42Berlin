/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 13:02:32 by edugonza         ###   ########.fr       */
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
			std::cout << "\033[33m" << "File error: " << e.what() << "\033[0m" << std::endl;
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
			std::cout << "\033[33m" << "File error: " << e.what() << "\033[0m" << std::endl;
			return 1;
	}

	return 0;
}

void tester(std::string filename, std::string s1, std::string s2, std::string expected)
{
	std::string string_test;
	std::string text_test;
	if(replacer(filename, s1, s2))
		return;

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
		std::cout << "\033[32m" << "Test passed for s1: '" << s1 << "' and s2: '" << s2 << "'" << "'" << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[31m" << "Test failed for s1: '" << s1 << "' and s2: '" << s2 << "'" << std::endl;
		std::cout << "Expected: '" << expected << "'" << std::endl;
		std::cout << "Got:      '" << text_test << "'" << "\033[0m" << std::endl;
	}
	return;
}


int main(int ac, char **av) {

	if (ac == 2 && av[1][0] == '-' && av[1][1] == 't')
	{
    std::cout << "=== CPP01 EX04 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

    // Create test files for our tests
    std::cout << "Setting up test files..." << std::endl;

    // Test file 1: Basic replacement
    std::ofstream test1("test1.txt");
    test1 << "Hello world! This is a test.\nHello again, world!\nGoodbye world.";
    test1.close();

    // Test file 2: Multiple occurrences
    std::ofstream test2("test2.txt");
    test2 << "apple apple banana apple\napple pie and apple juice\napple";
    test2.close();

    // Test file 3: Edge cases
    std::ofstream test3("test3.txt");
    test3 << "aaa aaa aaa\naaaa aaaa\na a a";
    test3.close();

    // Test file 4: Empty file
    std::ofstream test4("test4.txt");
    test4.close();

    // Test file 5: Special characters
    std::ofstream test5("test5.txt");
    test5 << "C++ is great! C++11, C++14, C++17\nI love C++ programming.\nC++: the best language.";
    test5.close();

    // Test file 6: Remove word
    std::ofstream test6("test6.txt");
    test6 << "Hello world! This is a test.\nHello again, world!\nGoodbye world";
    test6.close();

		std::cout << "Test files created." << std::endl << std::endl;

		// Test 1: Basic string replacement
    std::cout << "Test 1: Basic string replacement" << std::endl;
    std::cout << "Running: processFile(\"test1.txt\", \"world\", \"universe\")" << std::endl;
    tester("test1.txt", "world", "universe", "Hello universe! This is a test.\nHello again, universe!\nGoodbye universe.");
    std::cout << std::endl;

    // Test 2: Multiple occurrences
    std::cout << "Test 2: Multiple occurrences replacement" << std::endl;
    std::cout << "Original content:" << std::endl;
    std::cout << "Running: processFile(\"test2.txt\", \"apple\", \"orange\")" << std::endl;
    tester("test2.txt", "apple", "orange", "orange orange banana orange\norange pie and orange juice\norange");
    std::cout << std::endl;

    // Test 3: Overlapping patterns
    std::cout << "Test 3: Overlapping patterns" << std::endl;
    std::cout << "Original content:" << std::endl;
    std::cout << "Running: processFile(\"test3.txt\", \"aa\", \"XX\")" << std::endl;
    tester("test3.txt", "aa", "XX", "XXa XXa XXa\nXXXX XXXX\na a a");
    std::cout << std::endl;

    // Test 4: Empty file
    std::cout << "Test 4: Empty file handling" << std::endl;
    std::cout << "Running: processFile(\"test4.txt\", \"nothing\", \"something\")" << std::endl;
    tester("test4.txt", "nothing", "something", "");
    std::cout << std::endl;

    // Test 5: Special characters
    std::cout << "Test 5: Special characters" << std::endl;
    std::cout << "Running: processFile(\"test5.txt\", \"C++\", \"Rust\")" << std::endl;
    tester("test5.txt", "C++", "Rust", "Rust is great! Rust11, Rust14, Rust17\nI love Rust programming.\nRust: the best language.");
    std::cout << std::endl;

    // Test 6: String not found
    std::cout << "Test 6: String not found" << std::endl;
    std::cout << "Running: processFile(\"test1.txt\", \"xyz\", \"abc\")" << std::endl;
    tester("test1.txt", "xyz", "abc", "Hello world! This is a test.\nHello again, world!\nGoodbye world.");
    std::cout << std::endl;

    // Test 7: Replace with empty string
    std::cout << "Test 7: Replace with empty string" << std::endl;
    std::cout << "Running: processFile(\"test6.txt\", \"world\", \"\")" << std::endl;
		tester("test6.txt", "world", "", "Hello ! This is a test.\nHello again, !\nGoodbye ");
    std::cout << std::endl;

    // Test 8: Replace empty string (edge case)
    std::cout << "Test 8: Replace empty string (should not modify)" << std::endl;
    std::cout << "Running: processFile(\"test1.txt\", \"\", \"something\")" << std::endl;
    tester("test1.txt", "", "something", "Hello world! This is a test.\nHello again, world!\nGoodbye world.");
    std::cout << std::endl;

    // Test 9: Non-existent file
    std::cout << "Test 9: Non-existent file handling" << std::endl;
    std::cout << "Running: processFile(\"nonexistent.txt\", \"test\", \"result\")" << std::endl;
    tester("nonexistent.txt", "test", "result", "");
    std::cout << "Should handle error gracefully." << std::endl << std::endl;

		// Test 10
		std::cout << "Test 10: Brute tests" << std::endl;

    // Test file 3: Edge cases
    std::ofstream test10("test10.txt");
    test10 << "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n";
		test10.close();
    std::ofstream test11("test11.txt");
    test11 << "";
		test11.close();
    std::ofstream test12("test12.txt");
    test12 << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		test12.close();

		std::cout << "\n===>  non existent text" << std::endl;
		tester("test10.txt", "aaaaaa", "xx", "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n");
		std::cout << "\n===>  find and replace" << std::endl;
		tester("test10.txt", "aaaa", "xx", "xx\nbbbb\ncccc\ndddd\neeee\n\nxxbbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n");
    tester("test10.txt", "aaa", "xx", "xxa\nbbbb\ncccc\ndddd\neeee\n\nxxabbbbccccddddeeee\nxxbbbcccdddeee\naabbccddee\nabcde\n");
    tester("test10.txt", "aa", "xx", "xxxx\nbbbb\ncccc\ndddd\neeee\n\nxxxxbbbbccccddddeeee\nxxabbbcccdddeee\nxxbbccddee\nabcde\n");
		tester("test10.txt", "a", "xx", "xxxxxxxx\nbbbb\ncccc\ndddd\neeee\n\nxxxxxxxxbbbbccccddddeeee\nxxxxxxbbbcccdddeee\nxxxxbbccddee\nxxbcde\n");
		std::cout << "\n===>  empty s1" << std::endl;
		tester("test10.txt", "", "xx", "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n");
		std::cout << "\n===>  replace new lines" << std::endl;
		tester("test10.txt", "\n", "xx", "aaaaxxbbbbxxccccxxddddxxeeeexxxxaaaabbbbccccddddeeeexxaaabbbcccdddeeexxaabbccddeexxabcdexx");
		std::cout << "\n===>  empty s2" << std::endl;
		tester("test10.txt", "a", "", "\nbbbb\ncccc\ndddd\neeee\n\nbbbbccccddddeeee\nbbbcccdddeee\nbbccddee\nbcde\n");
		std::cout << "\n===>  s1 == s2" << std::endl;
		tester("test10.txt", "a", "a", "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n");
		std::cout << "\n===>  s1 bigger than text" << std::endl;
		tester("test10.txt", "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\naaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n", "xx", "aaaa\nbbbb\ncccc\ndddd\neeee\n\naaaabbbbccccddddeeee\naaabbbcccdddeee\naabbccddee\nabcde\n");
		std::cout << "\n===>  empty file" << std::endl;
		tester("test11.txt", "a", "xx", "");
		std::cout << "\n===>  only bl - no match" << std::endl;
		tester("test12.txt", "a", "xx", "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		std::cout << "\n===>  only bl - match" << std::endl;
		tester("test12.txt", "\n", "xx", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

		// std::cout << "\n\n ----- Cleaning up files -----" << std::endl;
		// system("rm -f test.txt.replace bl.txt.replace empty.txt.replace");


    // Cleanup
    std::cout << "\n\nCleaning up test files..." << std::endl;
    std::remove("test1.txt");
    std::remove("test1.txt.replace");
    std::remove("test2.txt");
    std::remove("test2.txt.replace");
    std::remove("test3.txt");
    std::remove("test3.txt.replace");
    std::remove("test4.txt");
    std::remove("test4.txt.replace");
    std::remove("test5.txt");
    std::remove("test5.txt.replace");
    std::remove("test6.txt");
    std::remove("test6.txt.replace");
    std::remove("test10.txt");
    std::remove("test10.txt.replace");
    std::remove("test11.txt");
    std::remove("test11.txt.replace");
    std::remove("test12.txt");
    std::remove("test12.txt.replace");

    // std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
    // std::cout << "Key test cases covered:" << std::endl;
    // std::cout << "1. Basic string replacement" << std::endl;
    // std::cout << "2. Multiple occurrences" << std::endl;
    // std::cout << "3. Overlapping patterns" << std::endl;
    // std::cout << "4. Empty files" << std::endl;
    // std::cout << "5. Special characters" << std::endl;
    // std::cout << "6. String not found" << std::endl;
    // std::cout << "7. Replace with empty string" << std::endl;
    // std::cout << "8. Empty search string" << std::endl;
    // std::cout << "9. Error handling for non-existent files" << std::endl;


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
