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

void run(std::string string_compute)
{
	RPN* rpn;
	try { rpn = check_save_input(string_compute); }
	catch(const std::exception& e) {
		std::cerr << "\033[31m" << e.what() << "\033[0m" << '\n';
		return;
	}

	try {	std::cout << rpn->evaluate() << std::endl; }
	catch(const std::exception& e) {
		std::cerr << "\033[31m" << e.what() << "\033[0m" << '\n';
		delete rpn;
		return;
	}
	delete rpn;
}

void basicOrthodoxTestsRPN()
{
	printSeparator("basicOrthodoxTestsRPN");
	std::deque<char> items;
	items.push_back('1');
	items.push_back('1');
	items.push_back('+');
	RPN x(items);           // Default constructor
	RPN y(x);        // Copy constructor (not assignment!)
	RPN z = x;       // Also copy constructor! (confusing syntax)
	std::deque<char> items2;
	items2.push_back('2');
	items2.push_back('2');
	items2.push_back('+');
	RPN w(items2);           // Parameterized constructor
	w = x;             // Copy assignment operator
}

void SubjectTestsRPN()
{
	printSeparator("SubjectTestsRPN");

	std::cout << "\nRunning test: ./RPM \"8 9 * 9 - 9 - 9 - 4 - 1 +\" ==> " <<std::endl;
	run("8 9 * 9 - 9 - 9 - 4 - 1 +");
	std::cout << "\nRunning test: ./RPM \"7 7 * 7 -\" ==> " <<std::endl;
	run("7 7 * 7 -");
	std::cout << "\nRunning test: ./RPM \"1 2 * 2 / 2 * 2 4 - +\" ==> " <<std::endl;
	run("1 2 * 2 / 2 * 2 4 - +");
	std::cout << "\nRunning test: ./RPM \"(1 + 1)\" ==> " <<std::endl;
	run("(1 + 1)");
}

void basicValidTestsRPN()
{
	printSeparator("basicValidTestsRPN");
	// Valid — simple operations
	std::cout << "\nRunning test: ./RPM \"1 1 +\" ==> " <<std::endl;
	run("1 1 +");
	std::cout << "\nRunning test: ./RPM \"9 9 *\" ==> " <<std::endl;
	run("9 9 *");
	std::cout << "\nRunning test: ./RPM \"8 4 /\" ==> " <<std::endl;
	run("8 4 /");
	std::cout << "\nRunning test: ./RPM \"5 3 -\" ==> " <<std::endl;
	run("5 3 -");

}

void basicFailedTestsRPN()
{
	printSeparator("basicFailedTestsRPN");
	// Error — not enough operands
	std::cout << "\nRunning test: ./RPM \"+\" ==> " <<std::endl;
	run("+");
	std::cout << "\nRunning test: ./RPM \"5\" ==> " <<std::endl;
	run("5");

	std::cout << "\nRunning test: ./RPM \"1 +\" ==> " <<std::endl;
	run("1 +");
	std::cout << "\nRunning test: ./RPM \"* 1 2\" ==> " <<std::endl;
	run("* 1 2");
	std::cout << "\nRunning test: ./RPM \"   \" ==> " <<std::endl;
	run("   ");

}

void ValidTestsRPN()
{
	printSeparator("ValidTestsRPN");
	// Valid — all numbers up front
	std::cout << "\nRunning test: ./RPM \"1 2 3 4 5 * + * +\" ==> " <<std::endl;
	run("1 2 3 4 5 * + * +");
	std::cout << "\nRunning test: ./RPM \"3 4 5 * + 2 * 1 +\" ==> " <<std::endl;
	run("3 4 5 * + 2 * 1 +");
	std::cout << "\nRunning test: ./RPM \"5 4 * 3 + 2 * 1 +\" ==> " <<std::endl;
	run("5 4 * 3 + 2 * 1 +");

}

void structureFailedRPN()
{
	printSeparator("structureFailedRPN");

	// Error — too many operands (stack has more than 1 at the end)
  std::cout << "\nRunning test: ./RPM \"1 2 3 +\" ==> " <<std::endl;
	run("1 2 3 +");

	// Error — division by zero
  std::cout << "\nRunning test: ./RPM \"5 0 /\" ==> " <<std::endl;
	run("5 0 /");

	// Error — invalid characters
  std::cout << "\nRunning test: ./RPM \"1 2 a +\" ==> " <<std::endl;
	run("1 2 a +");
  std::cout << "\nRunning test: ./RPM \"1 2 ++ +\" ==> " <<std::endl;
	run("1 2 ++ +");
  std::cout << "\nRunning test: ./RPM \"1 2 10 +\" ==> " <<std::endl;
	run("1 2 10 +");

}

int runTests()
{
	printSeparator("CPP09 - EX01");

	SubjectTestsRPN();
	basicValidTestsRPN();
	basicFailedTestsRPN();
	ValidTestsRPN();
	structureFailedRPN();

	printSeparator("ALL TESTS COMPLETED!");

	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./RPN 'Reverse Polish Calculation in \"\"'" << std::endl;
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
