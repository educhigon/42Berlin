/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 11:25:44 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie* zumb = new Zombie("Joe");
	int N = 7;
	Zombie* zumbHord = zombieHorde(N, "Ellie");

	zumb->announce();
	for (int i = 0; i < N; i++)
		zumbHord[i].announce();

	delete zumb;
	delete[] zumbHord;

	std::cout << "=== CPP01 EX01 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

	// Test 1: Basic horde creation and announcement
	std::cout << "Test 1: Create horde of 5 zombies" << std::endl;
	Zombie* horde1 = zombieHorde(5, "BasicZombie");
	for (int i = 0; i < 5; i++) {
			std::cout << "Zombie [" << i << "]: ";
			horde1[i].announce();
	}
	delete[] horde1;
	std::cout << std::endl;

	// Test 2: Single zombie horde
	std::cout << "Test 2: Single zombie horde (N=1)" << std::endl;
	Zombie* singleHorde = zombieHorde(1, "LoneWolf");
	singleHorde[0].announce();
	delete[] singleHorde;
	std::cout << std::endl;

	// Test 3: Large horde
	std::cout << "Test 3: Large horde (N=10)" << std::endl;
	Zombie* largeHorde = zombieHorde(10, "MassZombie");
	for (int i = 0; i < 10; i++) {
			std::cout << "Zombie [" << i << "]: ";
			largeHorde[i].announce();
	}
	delete[] largeHorde;
	std::cout << std::endl;

	// Test 4: Edge case - Zero zombies
	std::cout << "Test 4: Edge case - Zero zombies (N=0)" << std::endl;
	Zombie* zeroHorde = zombieHorde(0, "NoZombies");
	if (zeroHorde == NULL) {
			std::cout << "Correctly returned nullptr for N=0" << std::endl;
	} else {
			std::cout << "Warning: Non-null pointer returned for N=0" << std::endl;
			delete[] zeroHorde;
	}
	std::cout << std::endl;

	// Test 5: Edge case - Empty name
	std::cout << "Test 5: Edge case - Empty name" << std::endl;
	Zombie* emptyNameHorde = zombieHorde(3, "");
	for (int i = 0; i < 3; i++) {
			std::cout << "Zombie [" << i << "]: ";
			emptyNameHorde[i].announce();
	}
	delete[] emptyNameHorde;
	std::cout << std::endl;

	// Test 6: Edge case - Very long name
	std::cout << "Test 6: Edge case - Very long name" << std::endl;
	Zombie* longNameHorde = zombieHorde(2, "VeryLongZombieNameForTestingPurposes");
	for (int i = 0; i < 2; i++) {
			std::cout << "Zombie [" << i << "]: ";
			longNameHorde[i].announce();
	}
	delete[] longNameHorde;
	std::cout << std::endl;

	// Test 7: Multiple hordes memory management
	std::cout << "Test 7: Multiple hordes memory management" << std::endl;
	Zombie* horde_a = zombieHorde(3, "HordeA");
	Zombie* horde_b = zombieHorde(2, "HordeB");

	std::cout << "First horde:" << std::endl;
	for (int i = 0; i < 3; i++) {
			horde_a[i].announce();
	}

	std::cout << "Second horde:" << std::endl;
	for (int i = 0; i < 2; i++) {
			horde_b[i].announce();
	}

	delete[] horde_a;
	delete[] horde_b;
	std::cout << std::endl;

	// Test 8: Scope-based memory management
	std::cout << "Test 8: Scope-based memory management" << std::endl;
	{
			std::cout << "Creating horde in inner scope..." << std::endl;
			Zombie* scopeHorde = zombieHorde(3, "ScopeZombie");
			for (int i = 0; i < 3; i++) {
					scopeHorde[i].announce();
			}
			delete[] scopeHorde;
			std::cout << "Horde destroyed before leaving scope" << std::endl;
	}
	std::cout << "Scope exited successfully" << std::endl << std::endl;

	// Test 9: Performance test with larger array
	std::cout << "Test 9: Performance test (N=50 - showing first/last few)" << std::endl;
	Zombie* perfHorde = zombieHorde(50, "PerfTest");
	std::cout << "First 3 zombies:" << std::endl;
	for (int i = 0; i < 3; i++) {
			std::cout << "Zombie [" << i << "]: ";
			perfHorde[i].announce();
	}
	std::cout << "... (47 zombies in between) ..." << std::endl;
	std::cout << "Last 3 zombies:" << std::endl;
	for (int i = 47; i < 50; i++) {
			std::cout << "Zombie [" << i << "]: ";
			perfHorde[i].announce();
	}
	delete[] perfHorde;
	std::cout << std::endl;

	std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
	return 0;

}
