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

#include "RPN.hpp"
#include <sstream>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
} 

void run(std::string file_name)
{
	RPN be;

}

void basicTestsRPN()
{
	printSeparator("basicTestsRPN");
	RPN x("John", 150);           // Default constructor
	RPN y(x);        // Copy constructor (not assignment!)
	RPN z = x;       // Also copy constructor! (confusing syntax)
	RPN w("Peter", 1);
	w = x;             // Copy assignment operator
}

int runTests()
{
	printSeparator("CPP09 - EX01");

	basicTestsRPN();

	printSeparator("ALL TESTS COMPLETED!");

	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./RPN 'Reverse Polish Calculation in \"\"'" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}


int main(int ac, char** av)
{

	if (ac != 2)
	{
		std::cerr << "\033[33mWrong input\033[0m" << std::endl;
		std::cerr << "\033[33mUsage: ./RPN 'Reverse Polish Calculation in \"\"'" << std::endl;
		std::cerr << "  For example: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"\033[0m" << std::endl;

		return 1;
	}
	if (av[1][0] == 't')
		return(runTests());
	else
		run(av[1]);

	return 0;
}