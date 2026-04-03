/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <cmath>   // for log, floor, pow

extern int count_comparisons;
bool verbose = false;

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void run(std::string string_compute)
{
	std::cout << std::endl;
	PmergeMe pme;
	pme.check_save_input(string_compute);
	pme.order_numbers();
	return;
}

void SpecificTestsVerbose()
{
	std::cout << "\033[32m[Specific Tests PmergeMe]\033[0m" << std::endl;

	try
	{
		run("0 1 2 3 4 5");
		run("5 2 1 3 4 0");
		run("0 1 2 3 4 5 6");
		run("5 2 1 3 4 0 6");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

}

void MassiveTestsPmergeMe()
{
	std::cout << "\033[32m[Massive Tests PmergeMe]\033[0m" << std::endl;

	std::ostringstream input;
	input << "0";
	std::ostringstream input_reverse;
	input_reverse << "0";
	std::ostringstream input_reverse_temp;


	for (size_t i = 0; i < 3000; i++)
	{
		input << " " << (i + 1);
		input_reverse_temp << (i + 1) << " " << input_reverse.str();
		input_reverse.str(input_reverse_temp.str());
		input_reverse_temp.str("");
		try
		{
			run(input.str());
			run(input_reverse.str());
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << " for input: " << input.str() << '\n';
		}

	}

}


int runTests()
{
	printSeparator("CPP09 - EX02");

	MassiveTestsPmergeMe();

	printSeparator("ALL TESTS COMPLETED!");

	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./PmergeMe 'number sequence to be ordered'" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}
int runTestsVerbose()
{
	printSeparator("CPP09 - EX02");
	verbose = true;
	SpecificTestsVerbose();

	printSeparator("ALL TESTS COMPLETED!");

	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./PmergeMe 'number sequence to be ordered'" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}

int main(int ac, char** av)
{
	std::string input;

	if (ac < 2)
	{
		std::cerr << "\033[33mWrong input\033[0m" << std::endl;
		std::cerr << "\033[33mUsage: ./PmergeMe 'number sequence to be ordered'" << std::endl;
		std::cerr << "  For example: ./PmergeMe 3 5 9 7 4\033[0m" << std::endl;
		return 1;
	}
	else
	{
		for (int i = 1; i < ac - 1; i++)
			input += std::string(av[i]) + " ";
		input += std::string(av[ac - 1]);
	}

	if (av[1][0] == 't')
		return(runTests());
	else if (av[1][0] == 'v')
		return(runTestsVerbose());
	else if (av[1][0] == '-' && av[1][1] == 'v')
	{
		verbose = true;
		input.erase(0,3);
		std::cout << "input: " << input << std::endl;
		try { run(input); }
		catch(const std::exception& e) {
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	else
	{
		try { run(input); }
		catch(const std::exception& e) {
			std::cerr << "Error: " << e.what() << '\n';
		}
	}

	return 0;
}
