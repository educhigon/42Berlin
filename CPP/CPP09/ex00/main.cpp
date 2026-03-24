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
// #include <string>
// #include <cstring>
#include <fstream>
// #include <cstdio>
// #include <ctime>
// #include <iomanip>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void run(std::string file_name)
{
	BitcoinExchange be;
	try { be.load_exchange("./data.csv"); }
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return;
	}

	try { be.check_prices(file_name); }
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return;
	}

}

void basicTestsBitcoinExchange()
{
	std::string file_name = "TEST_FILE.txt";
	std::ofstream file(file_name.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error creating file\n";
		return;
	}

	printSeparator("Subject Tests");
	file << "date | value\n";
	file << "2011-01-03 | 3\n";
	file << "2011-01-03 | 2\n";
	file << "2011-01-03 | 1\n";
	file << "2011-01-03 | 1.2\n";
	file << "2011-01-09 | 1\n";
	file << "2012-01-11 | -1\n";
	file << "2001-42-42 \n";
	file << "2012-01-11 | 1\n";
	file << "2012-01-11 | 2147483648\n";
	file.close();
	run(file_name);
	file.open(file_name.c_str(), std::ios::out | std::ios::trunc);

	printSeparator("Valid cases");
	file << "date | value\n";
	file << "2011-01-03 | 3\n";
	file << "2011-01-03 | 2\n";
	file << "2012-01-11 | 1000\n";
	file << "2009-01-02 | 1.5\n";
	file << "2021-12-31 | 2\n";
	file << "2013-06-15 | 0\n";
	file.close();
	run(file_name);
	file.open(file_name.c_str(), std::ios::out | std::ios::trunc);

	printSeparator("Error — bad value");
	file << "date | value\n";
	file << "2011-01-03 | -1\n"; //        ← negative
	file << "2011-01-03 | 1001\n"; //      ← exceeds 1000
	file << "2011-01-03 | 0.5abc\n"; //    ← non-numeric
	file.close();
	run(file_name);
	file.open(file_name.c_str(), std::ios::out | std::ios::trunc);

	printSeparator("Error — bad date");
	file << "2001-42-42 | 1\n"; //         ← invalid month/day
	file << "2011-13-01 | 1\n"; //         ← month 13
	file << "2011-00-01 | 1\n"; //         ← month 0
	file << "2011-01-32 | 1\n"; //         ← day 32
	file << "NOT_A_DATE | 1\n"; //         ← completely wrong format
	file << "2011/01/03 | 1\n"; //         ← wrong separator in date
	file.close();
	run(file_name);
	file.open(file_name.c_str(), std::ios::out | std::ios::trunc);

	printSeparator("Edge cases — date not in database");
	std::cout << "\033[35mDefine expected behavior for upper and lower limit\033[m" << std::endl;
	file << "2009-01-01 | 1\n"; //         ← before first entry in data.csv
	file << "2009-01-02 | 1\n"; //         ← the first entry in data.csv
	file << "2014-06-03 | 1\n"; //         ← date exists in db (exact match)
	file << "2014-06-04 | 1\n"; //         ← date doesn't exist, should use closest lower
	file << "2099-01-01 | 1\n"; //         ← far future, should use last entry in db
	file.close();
	run(file_name);
	file.open(file_name.c_str(), std::ios::out | std::ios::trunc);

	printSeparator("Edge cases — format");
	file << "\n"; //                       ← empty line
	file << "2011-01-03|3\n"; //           ← missing spaces around pipe
	file << "2011-01-03 | 3 | 4\n"; //     ← extra pipe
	file.close();
	run(file_name);

	std::remove(file_name.c_str());
	return;
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
	else
		run(av[1]);

	return 0;
}
