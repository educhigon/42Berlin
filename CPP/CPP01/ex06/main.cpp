/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 13:27:22 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av) {

	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac == 2)
	{
		int i = 0;
		while(i<4)
		{
			if (av[1] == levels[i])
				break;
			i++;
		}
		// if(i<4)
		// 	std::cout << "[" << levels[i] << "]" << std::endl;

		switch (i)
		{
		case 0:
			std::cout << "[ " << levels[0] << " ]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
			//fall through
		case 1:
			std::cout << "[ " << levels[1] << " ]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
			//fall through
		case 2:
			std::cout << "[ " << levels[2] << " ]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
			//fall through
		case 3:
			std::cout << "[ " << levels[3] << " ]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
		std::cout << std::endl;
	}
	else
	{
		harl.complain("DEBUG");
		std::cout << std::endl;
		harl.complain("INFO");
		std::cout << std::endl;
		harl.complain("WARNING");
		std::cout << std::endl;
		harl.complain("ERROR");
		std::cout << std::endl;
	}

	return 0;
}

/*
	std::cout << "=== CPP01 EX06 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

	// Test 1: DEBUG level (shows all levels)
	std::cout << "Test 1: DEBUG level filter (should show all levels)" << std::endl;
	std::cout << "Running: harlFilter(\"DEBUG\")" << std::endl;
	std::cout << "Expected: DEBUG, INFO, WARNING, ERROR messages" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("DEBUG");
	std::cout << "---" << std::endl << std::endl;

	// Test 2: INFO level (shows INFO, WARNING, ERROR)
	std::cout << "Test 2: INFO level filter" << std::endl;
	std::cout << "Running: harlFilter(\"INFO\")" << std::endl;
	std::cout << "Expected: INFO, WARNING, ERROR messages (no DEBUG)" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("INFO");
	std::cout << "---" << std::endl << std::endl;

	// Test 3: WARNING level (shows WARNING, ERROR)
	std::cout << "Test 3: WARNING level filter" << std::endl;
	std::cout << "Running: harlFilter(\"WARNING\")" << std::endl;
	std::cout << "Expected: WARNING, ERROR messages (no DEBUG, INFO)" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("WARNING");
	std::cout << "---" << std::endl << std::endl;

	// Test 4: ERROR level (shows only ERROR)
	std::cout << "Test 4: ERROR level filter" << std::endl;
	std::cout << "Running: harlFilter(\"ERROR\")" << std::endl;
	std::cout << "Expected: ERROR message only" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("ERROR");
	std::cout << "---" << std::endl << std::endl;

	// Test 5: Invalid level
	std::cout << "Test 5: Invalid level filter" << std::endl;
	std::cout << "Running: harlFilter(\"INVALID\")" << std::endl;
	std::cout << "Expected: 'Probably complaining about insignificant problems' message" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("INVALID");
	std::cout << "---" << std::endl << std::endl;

	// Test 6: Empty string
	std::cout << "Test 6: Empty string filter" << std::endl;
	std::cout << "Running: harlFilter(\"\")" << std::endl;
	std::cout << "Expected: 'Probably complaining about insignificant problems' message" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("");
	std::cout << "---" << std::endl << std::endl;

	// Test 7: Case sensitivity
	std::cout << "Test 7: Case sensitivity" << std::endl;
	std::cout << "Running: harlFilter(\"debug\") - lowercase" << std::endl;
	std::cout << "Expected: 'Probably complaining about insignificant problems' message" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("debug");
	std::cout << "---" << std::endl << std::endl;

	std::cout << "Running: harlFilter(\"Error\") - mixed case" << std::endl;
	std::cout << "Expected: 'Probably complaining about insignificant problems' message" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("Error");
	std::cout << "---" << std::endl << std::endl;

	// Test 8: Random invalid inputs
	std::cout << "Test 8: Various invalid inputs" << std::endl;

	std::cout << "Running: harlFilter(\"CRITICAL\")" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("CRITICAL");
	std::cout << "---" << std::endl;

	std::cout << "Running: harlFilter(\"TRACE\")" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("TRACE");
	std::cout << "---" << std::endl;

	std::cout << "Running: harlFilter(\"123\")" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("123");
	std::cout << "---" << std::endl;

	std::cout << "Running: harlFilter(\"HELLO WORLD\")" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("HELLO WORLD");
	std::cout << "---" << std::endl << std::endl;

	// Test 9: Edge cases with special characters
	std::cout << "Test 9: Special characters" << std::endl;

	std::cout << "Running: harlFilter(\" DEBUG \")" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter(" DEBUG ");
	std::cout << "---" << std::endl;

	std::cout << "Running: harlFilter(\"DEBUG!\")" << std::endl;
	std::cout << "---" << std::endl;
	harlFilter("DEBUG!");
	std::cout << "---" << std::endl << std::endl;

	// Test 10: Demonstration of switch fall-through behavior
	std::cout << "Test 10: Demonstrating filter hierarchy" << std::endl;
	std::cout << "This test shows the hierarchical nature of the filter:" << std::endl;
	std::cout << "DEBUG includes all levels, INFO excludes DEBUG, etc." << std::endl << std::endl;

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
			std::cout << "Filter level: " << levels[i] << std::endl;
			std::cout << "---" << std::endl;
			harlFilter(levels[i]);
			std::cout << "---" << std::endl << std::endl;
	}

	std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
	std::cout << "Key features tested:" << std::endl;
	std::cout << "1. DEBUG filter shows all message types" << std::endl;
	std::cout << "2. INFO filter shows INFO, WARNING, ERROR (no DEBUG)" << std::endl;
	std::cout << "3. WARNING filter shows WARNING, ERROR only" << std::endl;
	std::cout << "4. ERROR filter shows ERROR only" << std::endl;
	std::cout << "5. Invalid inputs show default message" << std::endl;
	std::cout << "6. Case sensitivity is enforced" << std::endl;
	std::cout << "7. Special characters and spaces handled" << std::endl;
	std::cout << "8. Switch statement fall-through behavior" << std::endl;
	std::cout << "9. Hierarchical filtering system" << std::endl;
	std::cout << "10. Robust error handling for edge cases" << std::endl;

*/
