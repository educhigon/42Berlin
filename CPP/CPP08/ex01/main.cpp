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

#include "Span.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void basicTestsSpan()
{
	printSeparator("basicTestsSpan");
	Span y(5); // Parameterized constructor, creates an Span of size 5
	Span z = y; // Copy constructor, creates a copy of y
	Span z1(y); // Also Copy constructor, creates a copy of y
	Span w(0); // Default constructor, creates an empty Span
	w = y; // Copy assignment operator, assigns the contents of y to w
}

void basicTestsSpanAddNumber()
{
	printSeparator("basicTestsSpanAddNumber");
	Span y(5); // Parameterized constructor, creates an Span of size 5
	y.addNumber(3);
	y.addNumber(2);
	y.addNumber(4);
	y.addNumber(1);
	y.addNumber(5);
	try	{ y.addNumber(6); }
	catch(const std::exception& e)	{
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
	}

	std::cout << "Shortest Span is: " << y.shortestSpan() << std::endl;
	std::cout << "Shortest Span Slow is: " << y.shortestSpan_slow() << std::endl;
	std::cout << "Longest Span is: " << y.longestSpan() << std::endl;
}

void basicTestsSpanAddNumberBulkVector()
{
	printSeparator("basicTestsSpanAddNumberBulkVector");
	Span y(5); // Parameterized constructor, creates an Span of size 5
	std::vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);

	y.addNumber(vec.begin(), vec.end());
	try	{ y.addNumber(6); }
	catch(const std::exception& e)	{
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
	}

	std::cout << "Shortest Span is: " << y.shortestSpan() << std::endl;
	std::cout << "Shortest Span Slow is: " << y.shortestSpan_slow() << std::endl;
	std::cout << "Longest Span is: " << y.longestSpan() << std::endl;
}

void basicTestsSpanAddNumberBulkList()
{
	printSeparator("basicTestsSpanAddNumberBulkList");
	Span y(5); // Parameterized constructor, creates an Span of size 5
	std::list<int> list;
	list.push_back(3);
	list.push_back(2);
	list.push_back(4);
	list.push_back(1);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	y.addNumber(list.begin(), list.end());
	try	{	y.addNumber(6); }
	catch(const std::exception& e)	{
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
	}

	std::cout << "Shortest Span is: " << y.shortestSpan() << std::endl;
	std::cout << "Shortest Span Slow is: " << y.shortestSpan_slow() << std::endl;
	std::cout << "Longest Span is: " << y.longestSpan() << std::endl;
}

void basicTestsSpanBoundaries()
{
	printSeparator("basicTestsSpanBoundaries");
	std::cout << "Zero members" << std::endl;
	Span y(0); // Parameterized constructor, creates an Span of size 5
	try	{ y.addNumber(6);}
	catch(const std::exception& e)	{
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
	}
	try	{ std::cout << "Shortest Span is: " << y.shortestSpan() << std::endl;}
	catch(const std::exception& e)	{
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
	}
	try	{ std::cout << "Longest Span is: " << y.longestSpan() << std::endl;}
	catch(const std::exception& e)	{
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
	}

	std::cout << "One member" << std::endl;
	Span x(1); // Parameterized constructor, creates an Span of size 5
	try	{ x.addNumber(6);}
	catch(const std::exception& e)	{
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
	}
	try	{ std::cout << "Shortest Span is: " << x.shortestSpan() << std::endl;}
	catch(const std::exception& e)	{
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
	}
	try	{ std::cout << "Longest Span is: " << x.longestSpan() << std::endl;}
	catch(const std::exception& e)	{
		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
	}

}

void SubjectTests()
{
	printSeparator("SubjectTests");

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "Must match: \n2\n14" << std::endl;
	return;
}
void StresTest10000()
{
	printSeparator("StresTest10000");
	std::cout << "\033[33mBefore running this test comment the log in AddNumber for a cleaner result in the terminal\033[0m" << std::endl;
	// Comment the following return as well:
	return;
	clock_t time1, time2;

	Span sp = Span(10000);
	for(size_t i = 0; i < 10000; i++)
	{
		sp.addNumber(rand());
	}

	time1 = clock();
	std::cout << "- Shortest Span is: " << sp.shortestSpan() << std::endl;
	time2 = clock();
	double difference = (time2 - time1) * 1000.0 / CLOCKS_PER_SEC;
	std::cout << " --- Time function took: " << difference << std::endl;

	time1 = clock();
	std::cout << "- Shortest Span Slow is: " << sp.shortestSpan_slow() << std::endl;
	time2 = clock();
	difference = (time2 - time1) * 1000.0 / CLOCKS_PER_SEC;
	std::cout << " --- Time function took: " << difference << std::endl;

	std::cout << "- Longest Span is: " << sp.longestSpan() << std::endl;


	return;
}

int main()
{
	printSeparator("CPP08 - EX01");
	srand(time(0));

	basicTestsSpan();
	basicTestsSpanAddNumber();
	basicTestsSpanAddNumberBulkVector();
	basicTestsSpanAddNumberBulkList();
	basicTestsSpanBoundaries();
	SubjectTests();
	StresTest10000();


	printSeparator("ALL TESTS COMPLETED!");
	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./Span" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}
