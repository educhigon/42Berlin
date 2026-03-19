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

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void basicTestsMutantStack()
{
	printSeparator("basicTestsMutantStack");
	MutantStack<int> y; // Parameterized constructor, creates an MutantStack of size 5
	y.push(5);
	std::cout << "Printing y..." << std::endl;
	std::cout << y.top() << std::endl;
	std::cout << y.size() << std::endl;
	MutantStack<int> z = y; // Copy constructor, creates a copy of y
	std::cout << "Printing z..." << std::endl;
	std::cout << z.top() << std::endl;
	std::cout << z.size() << std::endl;
	MutantStack<int> z1(y); // Also Copy constructor, creates a copy of y
	std::cout << "Printing z1..." << std::endl;
	std::cout << z1.top() << std::endl;
	std::cout << z1.size() << std::endl;
	MutantStack<int> w; // Default constructor, creates an empty MutantStack
	w.push(0);
	std::cout << "Printing w before copy..." << std::endl;
	std::cout << w.top() << std::endl;
	std::cout << w.size() << std::endl;
	w = y; // Copy assignment operator, assigns the contents of y to w
	std::cout << "Printing w after copy..." << std::endl;
	std::cout << w.top() << std::endl;
	std::cout << w.size() << std::endl;
}

void SubjectTests()
{
	printSeparator("SubjectTests");

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

void SubjectTests_DequeComparisson()
{
	printSeparator("SubjectTests_DequeComparisson");

	std::deque<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::deque<int>::iterator it = mstack.begin();
	std::deque<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

void SubjectTests_ListComparisson()
{
	printSeparator("SubjectTests_ListComparisson");

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	// std::stack<int> s(mstack); -> list can't be used to initialize stack
}

void SubjectTestsNonInt()
{
	printSeparator("SubjectTestsNonInt");

	MutantStack<std::string> mstack;
	mstack.push("5");
	mstack.push("17");
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push("3");
	mstack.push("5");
	mstack.push("737");
	//[...]
	mstack.push("0");
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << "\"" <<  *it << "\"" << std::endl;
	++it;
	}
	std::stack<std::string> s(mstack);
}

void SubjectTestsConstInt()
{
	printSeparator("SubjectTestsConstInt");

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	const MutantStack<int> cmstack = mstack;
	MutantStack<int>::const_iterator it = cmstack.begin();
	MutantStack<int>::const_iterator ite = cmstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout <<  *it << std::endl;
	++it;
	}
	// *it = 42;  // uncomment -> this will fail
	std::stack<int> s(mstack);
}

int main()
{
	printSeparator("CPP08 - EX02");

	basicTestsMutantStack();
	SubjectTests();
	SubjectTests_DequeComparisson();
	SubjectTests_ListComparisson();
	SubjectTestsNonInt();
	SubjectTestsConstInt();

	printSeparator("ALL TESTS COMPLETED!");
	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./MutantStack" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}
