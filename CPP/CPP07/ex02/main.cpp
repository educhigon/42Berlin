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

#include "Array.hpp"
#include <iostream>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void basicTestsArray()
{
	printSeparator("basicTestsArray");
	Array<int> x; // Defualt constructor, creates an empty array
	std::cout << "Size of x: " << x.size() << std::endl;
	Array<int> y(5); // Parameterized constructor, creates an array of size 5
	std::cout << "Size of y: " << y.size() << std::endl;
	y[0] = 42;
	std::cout << "First item of y: " << y[0] << std::endl;
	Array<int> z = y; // Copy constructor, creates a copy of y
	std::cout << "Size of z: " << z.size() << std::endl;
	std::cout << "First item of z: " << z[0] << std::endl;
	z[0] = 24;
	std::cout << "First item of z after modification: " << z[0] << std::endl;
	std::cout << "First item of y after modification in z (they are independent): " << y[0] << std::endl;

	Array<int> z1(y); // Also Copy constructor, creates a copy of y
	std::cout << "Size of z1: " << z1.size() << std::endl;
	Array<int> w; // Default constructor, creates an empty array
	std::cout << "Size of w: " << w.size() << std::endl;
	w = y; // Copy assignment operator, assigns the contents of y to w
	std::cout << "Size of w after assignment: " << w.size() << std::endl;
}


void basicTestsArrayFunctions()
{
	printSeparator("basicTestsArrayFunctions");

	Array<int> b(2);
	for (size_t i = 0; i < b.size(); i++)
		b[i] = i + 1;

	//Printing array
	std::cout << "Array b, with size " << b.size() << ": \n";
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	Array<char> c(3);
	for (size_t i = 0; i < c.size(); i++)
		c[i] = 'a' + i;

	std::cout << "Array c, with size " << c.size() << ": \n";
	for (size_t i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;
}

void basicTestsArrayFailWrongType()
{
	printSeparator("basicTestsArrayFailWrongType");
	Array<int> b(2);
	for (size_t i = 0; i < b.size(); i++)
		b[i] = i + 1;

	std::cout << "\033[33m ***** Uncomment the code in this function to show that C++ knows the type of the Array on compilation.\n\033[0m" << std::endl;
	// b[0] = "42"; // This should cause a compilation error, as we are trying to assign a string to an int array
}

void basicTestsArrayFailAccessingNULLArray()
{
	printSeparator("basicTestsArrayFailAccessingNULLArray");

	Array<char> c;
	try
	{
		std::cout << c[0] << " ";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\033[31mException caught while accessing item in empty array: \033[0m -> ";
		std::cerr << e.what() << '\n';
	}
}

void basicTestsArrayFailIndexGreater()
{
	printSeparator("basicTestsArrayFailIndexGreater");

	Array<int> b(2);
	for (size_t i = 0; i < b.size(); i++)
		b[i] = i + 1;

	//Printing array
	std::cout << "Array b, with size " << b.size() << ": \n";
	for (size_t i = 0; i < b.size() * 3; i++)
	{
		try
		{
			std::cout << b[i] << " ";
		}
		catch(const std::exception& e)
		{
			std::cerr << "\n\033[31mException caught while accessing index: \033[0m" << i << " -> ";
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
}

int main()
{
	printSeparator("CPP07 - EX02");

	basicTestsArray();
	basicTestsArrayFunctions();
	basicTestsArrayFailWrongType();
	basicTestsArrayFailIndexGreater();
	basicTestsArrayFailAccessingNULLArray();

	printSeparator("ALL TESTS COMPLETED!");
	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./Array" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}
