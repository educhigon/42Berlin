/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 11:43:09 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void) {

	std::cout << "=== CPP01 EX02 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

	// Test 0: Failed test
	std::cout << "Test 0: Failed test, wrong manipulation of references" << std::endl;
	std::string brain = "HI THIS IS BRAIN";
	std::string* strPTR = &brain;
	std::string strREF = brain;

	std::cout << "Original string: \"" << brain << "\"" << std::endl;
	std::cout << "The memory address of the string variable: " << &brain << std::endl;
	std::cout << "The memory address held by strPTR: " << strPTR << std::endl;
	std::cout << "The memory address held by strREF: " << &strREF << std::endl;
	std::cout << std::endl;

	std::cout << "The value of the string variable: " << brain << std::endl;
	std::cout << "The value pointed to by strPTR: " << *strPTR << std::endl;
	std::cout << "The value pointed to by strREF: " << strREF << std::endl;
	std::cout << std::endl;

	// Test 1: Basic string, pointer, and reference
	std::cout << "Test 1: Basic string, pointer, and reference demonstration" << std::endl;
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Original string: \"" << str << "\"" << std::endl;
	std::cout << "Memory address of string variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:  " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Value of string variable: \"" << str << "\"" << std::endl;
	std::cout << "Value pointed to by stringPTR: \"" << *stringPTR << "\"" << std::endl;
	std::cout << "Value pointed to by stringREF: \"" << stringREF << "\"" << std::endl;
	std::cout << std::endl;

	// Test 2: Modification through pointer
	std::cout << "Test 2: Modification through pointer" << std::endl;
	std::cout << "Before modification:" << std::endl;
	std::cout << "str = \"" << str << "\"" << std::endl;
	std::cout << "*stringPTR = \"" << *stringPTR << "\"" << std::endl;
	std::cout << "stringREF = \"" << stringREF << "\"" << std::endl;

	*stringPTR = "MODIFIED THROUGH POINTER";
	std::cout << "After modifying through pointer:" << std::endl;
	std::cout << "str = \"" << str << "\"" << std::endl;
	std::cout << "*stringPTR = \"" << *stringPTR << "\"" << std::endl;
	std::cout << "stringREF = \"" << stringREF << "\"" << std::endl;
	std::cout << std::endl;

	// Test 3: Modification through reference
	std::cout << "Test 3: Modification through reference" << std::endl;
	stringREF = "MODIFIED THROUGH REFERENCE";
	std::cout << "After modifying through reference:" << std::endl;
	std::cout << "str = \"" << str << "\"" << std::endl;
	std::cout << "*stringPTR = \"" << *stringPTR << "\"" << std::endl;
	std::cout << "stringREF = \"" << stringREF << "\"" << std::endl;
	std::cout << std::endl;

	// Test 4: Address comparison verification
	std::cout << "Test 4: Address comparison verification" << std::endl;
	std::cout << "Are all addresses the same?" << std::endl;
	std::cout << "&str == stringPTR: " << (&str == stringPTR ? "YES" : "NO") << std::endl;
	std::cout << "&str == &stringREF: " << (&str == &stringREF ? "YES" : "NO") << std::endl;
	std::cout << "stringPTR == &stringREF: " << (stringPTR == &stringREF ? "YES" : "NO") << std::endl;
	std::cout << std::endl;

	// Test 5: Edge case - Empty string
	std::cout << "Test 5: Edge case - Empty string" << std::endl;
	std::string emptyStr = "";
	std::string* emptyPTR = &emptyStr;
	std::string& emptyREF = emptyStr;

	std::cout << "Empty string addresses:" << std::endl;
	std::cout << "&emptyStr: " << &emptyStr << std::endl;
	std::cout << "emptyPTR:  " << emptyPTR << std::endl;
	std::cout << "&emptyREF: " << &emptyREF << std::endl;

	std::cout << "Empty string values:" << std::endl;
	std::cout << "emptyStr: \"" << emptyStr << "\" (length: " << emptyStr.length() << ")" << std::endl;
	std::cout << "*emptyPTR: \"" << *emptyPTR << "\" (length: " << emptyPTR->length() << ")" << std::endl;
	std::cout << "emptyREF: \"" << emptyREF << "\" (length: " << emptyREF.length() << ")" << std::endl;
	std::cout << std::endl;

	// Test 6: Large string handling
	std::cout << "Test 6: Large string handling" << std::endl;
	std::string largeStr = "This is a very long string that contains many words and characters to test how pointers and references handle larger data structures in memory";
	std::string* largePTR = &largeStr;
	std::string& largeREF = largeStr;

	std::cout << "Large string length: " << largeStr.length() << std::endl;
	std::cout << "All point to same address: " << (&largeStr == largePTR && largePTR == &largeREF ? "YES" : "NO") << std::endl;
	std::cout << "First 20 chars via pointer: \"" << largePTR->substr(0, 20) << "...\"" << std::endl;
	std::cout << "Last 20 chars via reference: \"..." << largeREF.substr(largeREF.length() - 20) << "\"" << std::endl;
	std::cout << std::endl;

	// Test 7: Pointer reassignment vs reference binding
	std::cout << "Test 7: Pointer reassignment vs reference binding" << std::endl;
	std::string str1 = "First String";
	std::string str2 = "Second String";

	std::string* ptr = &str1;
	std::string& ref = str1;

	std::cout << "Initial state:" << std::endl;
	std::cout << "str1: \"" << str1 << "\" at " << &str1 << std::endl;
	std::cout << "str2: \"" << str2 << "\" at " << &str2 << std::endl;
	std::cout << "ptr points to: \"" << *ptr << "\" at " << ptr << std::endl;
	std::cout << "ref refers to: \"" << ref << "\" at " << &ref << std::endl;

	// Reassign pointer
	ptr = &str2;
	std::cout << "After ptr = &str2:" << std::endl;
	std::cout << "ptr now points to: \"" << *ptr << "\" at " << ptr << std::endl;
	std::cout << "ref still refers to: \"" << ref << "\" at " << &ref << std::endl;
	std::cout << std::endl;

	return 0;
}
