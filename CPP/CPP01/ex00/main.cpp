/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 11:20:41 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	std::cout << "=== CPP01 EX00 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

	// Test 1: Basic zombie creation and announcement
	std::cout << "Test 1: Basic zombie creation on heap" << std::endl;
	Zombie* heapZombie = newZombie("HeapWalker");
	heapZombie->announce();
	delete heapZombie;
	std::cout << std::endl;

	// Test 2: Stack allocation with randomChump
	std::cout << "Test 2: Stack allocation with randomChump" << std::endl;
	randomChump("StackBiter");
	std::cout << "randomChump function completed - zombie destroyed automatically" << std::endl << std::endl;

	// Test 3: Multiple heap zombies
	std::cout << "Test 3: Multiple heap zombies" << std::endl;
	Zombie* zombie1 = newZombie("Zombie1");
	Zombie* zombie2 = newZombie("Zombie2");
	Zombie* zombie3 = newZombie("Zombie3");

	zombie1->announce();
	zombie2->announce();
	zombie3->announce();

	delete zombie1;
	delete zombie2;
	delete zombie3;
	std::cout << std::endl;

	// Test 4: Edge case - Empty name
	std::cout << "Test 4: Edge case - Empty name" << std::endl;
	Zombie* emptyZombie = newZombie("");
	emptyZombie->announce();
	delete emptyZombie;
	std::cout << std::endl;

	// Test 5: Edge case - Long name
	std::cout << "Test 5: Edge case - Very long name" << std::endl;
	Zombie* longNameZombie = newZombie("VeryLongZombieNameThatTestsStringHandling");
	longNameZombie->announce();
	delete longNameZombie;
	std::cout << std::endl;

	// Test 6: Mixed allocation demonstration
	std::cout << "Test 6: Mixed allocation patterns" << std::endl;
	std::cout << "Creating heap zombie..." << std::endl;
	Zombie* mixedHeap = newZombie("MixedHeap");
	mixedHeap->announce();

	std::cout << "Creating stack zombie via randomChump..." << std::endl;
	randomChump("MixedStack");

	std::cout << "Heap zombie still exists:" << std::endl;
	mixedHeap->announce();
	delete mixedHeap;
	std::cout << std::endl;

	std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
	return 0;
}
