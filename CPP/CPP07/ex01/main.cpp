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

#include "iter.hpp"
#include <iostream>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

// Test functions for iter
void printInt(const int& n) { std::cout << n << " "; }
void printStr(const char& s) { std::cout << s << " "; }
void increment(int& n) { n++; }
void toUpper(char& s) { s = std::toupper(s); }
struct Square {
	Square() {}
	void operator()(int& n) const { n *= n; }
};

struct TurnA {
	TurnA() {}
	void operator()(char& n) const { n = 'A'; }
};


// All tests for iter and iter2
void basicTestsIter()
{
	printSeparator("basicTestsIter");

	// Test with int array
	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Original int array: ";
	iter(intArr, 5, printInt);
	std::cout << "\nIncrementing int array..." << std::endl;
	iter(intArr, 5, increment);
	std::cout << "Modified int array: ";
	iter(intArr, 5, printInt);
	std::cout << "\n\n";

	// Test with char array
	char charArr[] = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Original char array: ";
	iter(charArr, 5, printStr);
	std::cout << "\nConverting char array to uppercase..." << std::endl;
	iter(charArr, 5, toUpper);
	std::cout << "Modified char array: ";
	iter(charArr, 5, printStr);
	std::cout << "\n\n";
}
void basicTestsIter2()
{
	printSeparator("basicTestsIter2");

	// Test with int array
	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Original int array: ";
	iter2(intArr, 5, printInt);
	std::cout << "\nIncrementing int array..." << std::endl;
	iter2(intArr, 5, increment);
	std::cout << "Modified int array: ";
	iter2(intArr, 5, printInt);
	std::cout << "\n\n";

	// Test with char array
	char charArr[] = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Original char array: ";
	iter2(charArr, 5, printStr);
	std::cout << "\nConverting char array to uppercase..." << std::endl;
	iter2(charArr, 5, toUpper);
	std::cout << "Modified char array: ";
	iter2(charArr, 5, printStr);
	std::cout << "\n\n";
}

void basicTestsIterConst()
{
	printSeparator("basicTestsIterConst");
	std::cout << "\033[33m *** Uncomment this code to test iter with \033[35mconst arrays and non-const function pointers\033[33m. " << std::endl;
	std::cout << " This should fail to compile, demonstrating that iter does not allow modifying const data, but allows using it without modification.\n\n\033[0m" << std::endl;

	// Test with int array
	int const intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Original int array: ";
	iter(intArr, 5, printInt);
	// std::cout << "\nIncrementing int array..." << std::endl;
	// iter(intArr, 5, increment);
	// std::cout << "Modified int array: ";
	// iter(intArr, 5, printInt);
	std::cout << "\n\n";

	// Test with char array
	char const charArr[] = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Original char array: ";
	iter(charArr, 5, printStr);
	// std::cout << "\nConverting char array to uppercase..." << std::endl;
	// iter(charArr, 5, toUpper);
	// std::cout << "Modified char array: ";
	// iter(charArr, 5, printStr);
	std::cout << "\n\n";
}
void basicTestsIter2Const()
{
	printSeparator("basicTestsIter2Const");
	std::cout << "\033[33m *** Uncomment this code to test iter2 with \033[35mconst arrays and non-const function pointers\033[33m. " << std::endl;
	std::cout << " This should fail to compile, demonstrating that iter2 does not allow modifying const data, but allows using it without modification.\n\n\033[0m" << std::endl;

	// Test with int array
	int const intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Original int array: ";
	iter2(intArr, 5, printInt);
	// std::cout << "\nIncrementing int array..." << std::endl;
	// iter2(intArr, 5, increment);
	// std::cout << "Modified int array: ";
	// iter2(intArr, 5, printInt);
	std::cout << "\n\n";

	// Test with char array
	char const charArr[] = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Original char array: ";
	iter2(charArr, 5, printStr);
	// std::cout << "\nConverting char array to uppercase..." << std::endl;
	// iter2(charArr, 5, toUpper);
	// std::cout << "Modified char array: ";
	// iter2(charArr, 5, printStr);
	std::cout << "\n\n";
}

void IterWithFunctor()
{
	printSeparator("IterWithFunctor");
	std::cout << "\033[33m *** Uncomment the code in this function to test iter with \033[35mFunctor\033[33m." << std::endl;
	std::cout << "  This should fail to compile, demonstrating that iter can't accept annonymous functions .\n\n\033[0m" << std::endl;

	// Test with int array
	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Original int array: ";
	iter(intArr, 5, printInt);
	// std::cout << "\nSquaring int array..." << std::endl;
	// iter(intArr, 5, Square());
	// std::cout << "Modified int array: ";
	// iter(intArr, 5, printInt);
	std::cout << "\n\n";

	// Test with char array
	char charArr[] = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Original char array: ";
	iter(charArr, 5, printStr);
	// std::cout << "\nConverting char array to 'A'..." << std::endl;
	// iter(charArr, 5, TurnA());
	// std::cout << "Modified char array: ";
	// iter(charArr, 5, printStr);
	std::cout << "\n\n";
}

void Iter2WithFunctor()
{
	printSeparator("Iter2WithFunctor");

	// Test with int array
	int intArr[] = {1, 2, 3, 4, 5};
	std::cout << "Original int array: ";
	iter2(intArr, 5, printInt);
	std::cout << "\nSquaring int array..." << std::endl;
	iter2(intArr, 5, Square());
	std::cout << "Modified int array: ";
	iter2(intArr, 5, printInt);
	std::cout << "\n\n";

	// Test with char array
	char charArr[] = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Original char array: ";
	iter2(charArr, 5, printStr);
	std::cout << "\nConverting char array to 'A'..." << std::endl;
	iter2(charArr, 5, TurnA());
	std::cout << "Modified char array: ";
	iter2(charArr, 5, printStr);
	std::cout << "\n\n";

}

int main()
{
	printSeparator("CPP07 - EX01");

	basicTestsIter();
	basicTestsIter2();
	basicTestsIterConst();
	basicTestsIter2Const();
	IterWithFunctor();
	Iter2WithFunctor();

	printSeparator("ALL TESTS COMPLETED!");
	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./Iter" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}
