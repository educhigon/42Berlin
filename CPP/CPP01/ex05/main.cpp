/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 13:11:49 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Harl.hpp"

int main(void) {

	// Harl harl;
	// harl.complain("DEBUG");
	// std::cout << std::endl;
	// harl.complain("INFO");
	// std::cout << std::endl;
	// harl.complain("WARNING");
	// std::cout << std::endl;
	// harl.complain("ERROR");
	// std::cout << std::endl;


	std::cout << "=== CPP01 EX05 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

	Harl harl;

	// Test 1: All valid complaint levels
	std::cout << "Test 1: All valid complaint levels" << std::endl;
	std::cout << std::endl << "Testing DEBUG level:" << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl << "Testing INFO level:" << std::endl;
	harl.complain("INFO");

	std::cout << std::endl << "Testing WARNING level:" << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl << "Testing ERROR level:" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	// Test 2: Invalid complaint levels
	std::cout << "Test 2: Invalid complaint levels" << std::endl;
	std::cout << "Testing invalid level 'CRITICAL':" << std::endl;
	harl.complain("CRITICAL");

	std::cout << "Testing invalid level 'TRACE':" << std::endl;
	harl.complain("TRACE");

	std::cout << "Testing empty string:" << std::endl;
	harl.complain("");

	std::cout << "Testing random string 'HELLO':" << std::endl;
	harl.complain("HELLO");
	std::cout << std::endl;

	// Test 3: Case sensitivity
	std::cout << "Test 3: Case sensitivity" << std::endl;
	std::cout << "Testing lowercase 'debug':" << std::endl;
	harl.complain("debug");

	std::cout << "Testing mixed case 'Error':" << std::endl;
	harl.complain("Error");

	std::cout << "Testing mixed case 'warning':" << std::endl;
	harl.complain("warning");
	std::cout << std::endl;

	// Test 4: Edge cases with spaces and special characters
	std::cout << "Test 4: Edge cases with spaces and special characters" << std::endl;
	std::cout << "Testing ' DEBUG ' (with spaces):" << std::endl;
	harl.complain(" DEBUG ");

	std::cout << "Testing 'DEBUG!' (with exclamation):" << std::endl;
	harl.complain("DEBUG!");

	std::cout << "Testing '123' (numbers):" << std::endl;
	harl.complain("123");
	std::cout << std::endl;

	// Test 5: Repeated calls
	std::cout << "Test 5: Repeated calls to same level" << std::endl;
	std::cout << "Calling INFO three times:" << std::endl;
	harl.complain("INFO");
	harl.complain("INFO");
	harl.complain("INFO");
	std::cout << std::endl;

	// Test 6: Sequential calls to demonstrate consistency
	std::cout << "Test 6: Sequential calls in different order" << std::endl;
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("INFO");
	std::cout << std::endl;

	// Test 7: Performance test (many calls)
	std::cout << "Test 7: Performance test (50 rapid calls)" << std::endl;
	std::cout << "Making 50 rapid calls to different levels..." << std::endl;

	for (int i = 0; i < 50; i++) {
			switch (i % 4) {
					case 0: harl.complain("DEBUG"); break;
					case 1: harl.complain("INFO"); break;
					case 2: harl.complain("WARNING"); break;
					case 3: harl.complain("ERROR"); break;
			}
	}
	std::cout << "Performance test completed." << std::endl << std::endl;

	// Test 8: Multiple Harl instances
	std::cout << "Test 8: Multiple Harl instances" << std::endl;
	Harl harl1, harl2, harl3;

	std::cout << "Harl1 complaining:" << std::endl;
	harl1.complain("DEBUG");

	std::cout << "Harl2 complaining:" << std::endl;
	harl2.complain("WARNING");

	std::cout << "Harl3 complaining:" << std::endl;
	harl3.complain("ERROR");
	std::cout << std::endl;

	// Test 9: Function pointer mechanism demonstration
	std::cout << "Test 9: Demonstrating function pointer efficiency" << std::endl;
	std::cout << "This test shows that the implementation uses function pointers" << std::endl;
	std::cout << "instead of multiple if/else statements for better performance." << std::endl;

	std::cout << std::endl << "Quick succession of different complaint levels:" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INVALID");
	std::cout << std::endl;

	// Test 10: Boundary and stress testing
	std::cout << "Test 10: Boundary and stress testing" << std::endl;

	std::cout << "Testing very long invalid string:" << std::endl;
	harl.complain("THISISAVERYLONGINVALIDSTRINGTHATSHOULDBEIGNORED");

	std::cout << "Testing single character:" << std::endl;
	harl.complain("D");

	std::cout << "Testing null-like scenarios:" << std::endl;
	harl.complain("NULL");
	harl.complain("nullptr");
	std::cout << std::endl;

	return 0;

}
