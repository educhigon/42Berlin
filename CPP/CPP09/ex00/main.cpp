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

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <cstring>

#include <ctime>
#include <iomanip>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}
void basicTestsBitcoinExchange()
{
	// printSeparator("basicTestsBitcoinExchange");
	// BitcoinExchange x("John", 150);           // Default constructor
	// BitcoinExchange y(x);        // Copy constructor (not assignment!)
	// BitcoinExchange z = x;       // Also copy constructor! (confusing syntax)
	// BitcoinExchange w("Peter", 1);
	// w = x;             // Copy assignment operator
}


int runTests()
{
	printSeparator("CPP09 - EX00");

	basicTestsBitcoinExchange();

	printSeparator("ALL TESTS COMPLETED!");

	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./btc <input_file.txt>" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}

int main(int ac, char** av)
{

	if (ac != 2)
	{
		std::cerr << "\033[33mWrong input\033[0m" << std::endl;
		std::cerr << "\033[33mUsage: ./btc <input_file.txt>\033[0m" << std::endl;
		return 1;
	}
	if (av[1][0] == 't')
		return(runTests());

	BitcoinExchange be;
	try { be.load_exchange("./data.csv"); }
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}

	try { be.check_prices(av[1]); }
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;
}
