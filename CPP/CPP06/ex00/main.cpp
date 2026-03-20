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

#include "ScalarConverter.hpp"
#include <sstream>
#include <cstring>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}
void basicTestsScalarConverter(std::string str)
{
	std::cout << "./Converter " << str << std::endl;
	ScalarConverter::convert(str);
	std::cout << std::endl;
}


void testSubject()
{
	printSeparator("testSubject");

/*

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

*/

	basicTestsScalarConverter("0");
	basicTestsScalarConverter("nan");
	basicTestsScalarConverter("42.0f");

}


void testChar()
{
	printSeparator("testChar");

	basicTestsScalarConverter("a");
	basicTestsScalarConverter("Z");
	basicTestsScalarConverter(" ");
	basicTestsScalarConverter("0");
	basicTestsScalarConverter("31");
	basicTestsScalarConverter("127");
	basicTestsScalarConverter("128");
}

void testInt()
{
	printSeparator("testInt");

	basicTestsScalarConverter("42");
	basicTestsScalarConverter("-42");
	basicTestsScalarConverter("2147483647");
	basicTestsScalarConverter("2147483648");
	basicTestsScalarConverter("-2147483648");
}

void testFloat()
{
	printSeparator("testFloat");

	basicTestsScalarConverter("42.0f");
	basicTestsScalarConverter("-3.14f");
	basicTestsScalarConverter("+inff");
	basicTestsScalarConverter("inff");
	basicTestsScalarConverter("-inff");
	basicTestsScalarConverter("nanf");
}

void testDouble()
{
	printSeparator("testDouble");


	basicTestsScalarConverter("3.14");
	basicTestsScalarConverter("+inf");
	basicTestsScalarConverter("inf");
	basicTestsScalarConverter("-inf");
	basicTestsScalarConverter("nan");
	basicTestsScalarConverter("1.7e308");
	basicTestsScalarConverter("1.8e308");
}

void testFailures()
{
	printSeparator("testFailures");

	basicTestsScalarConverter("");
	basicTestsScalarConverter("abc");
	basicTestsScalarConverter("42abc");
	basicTestsScalarConverter("-42.0fq");
	basicTestsScalarConverter("10.ewrewrf");
	basicTestsScalarConverter("42.1.2");
	basicTestsScalarConverter("--42");
	basicTestsScalarConverter(".");
	basicTestsScalarConverter("f");
	basicTestsScalarConverter(".f");
}
void testBoundariesScalarConverter()
{
	printSeparator("testBoundariesScalarConverter");

	basicTestsScalarConverter(".5");
	basicTestsScalarConverter("5.");
	basicTestsScalarConverter("+42");
	basicTestsScalarConverter("++42");
	basicTestsScalarConverter("-42");
	basicTestsScalarConverter("--42");
	basicTestsScalarConverter("42f");

}
void testRoundingErrors()
{
	printSeparator("testRoundingErrors");
	basicTestsScalarConverter("111111");
	basicTestsScalarConverter("11111111");
	basicTestsScalarConverter("1111111111111");
	basicTestsScalarConverter("11111111111111111111111111");
	basicTestsScalarConverter("111111111111111111111111111111111111111111111111111111111");
	basicTestsScalarConverter("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
}


int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage ./Converter <text-to-convert> // [type \033[34m./Converter run_tests\033[0m to run unit tests]" << std::endl;
		return 1;
	}
	if(ac == 2 && !strcmp(av[1],"run_tests"))
	{

		printSeparator("CPP06 - EX00");

		testSubject();
		testChar();
		testInt();
		testFloat();
		testDouble();
		testFailures();
		testBoundariesScalarConverter();
		testRoundingErrors();

		printSeparator("ALL TESTS COMPLETED!");

		std::cout << "To check for memory leaks, run:" << std::endl;
		std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./Converter run_tests" << std::endl;
		std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
		std::cout << "========================================\n" << std::endl;
	}
	else
		ScalarConverter::convert(av[1]);

	return 0;
}
