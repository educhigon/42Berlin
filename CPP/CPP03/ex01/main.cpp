/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:16:02 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/25 22:06:43 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "=== CPP03 EX01 - SCAVTRAP INHERITANCE TESTS ===" << std::endl << std::endl;

	// Test 1: Constructor/Destructor Chaining
	std::cout << "--- Test 1: Constructor/Destructor Chaining ---" << std::endl;
	{
		std::cout << "Creating ClapTrap 'BasicBot':" << std::endl;
		ClapTrap basic("BasicBot");
		std::cout << std::endl;

		std::cout << "Creating ScavTrap 'AdvancedBot':" << std::endl;
		ScavTrap advanced("AdvancedBot");
		std::cout << "(Notice: ClapTrap constructor called first, then ScavTrap)" << std::endl;
		std::cout << std::endl;

		std::cout << "About to exit scope - watch destructor order:" << std::endl;
	} // Destructors called here: ScavTrap first, then ClapTrap
	std::cout << std::endl;

	// Test 2: Stats Comparison (ClapTrap vs ScavTrap)
	std::cout << "--- Test 2: Stats Comparison ---" << std::endl;
	ClapTrap weakBot("WeakBot");
	ScavTrap strongBot("StrongBot");
	std::cout << std::endl;

	std::cout << "ClapTrap stats: 10 HP, 10 Energy, 0 Damage" << std::endl;
	std::cout << "ScavTrap stats: 100 HP, 50 Energy, 20 Damage" << std::endl;
	std::cout << std::endl;

	// Test 3: Attack Method Override
	std::cout << "--- Test 3: Attack Method Override ---" << std::endl;
	std::cout << "ClapTrap attack (green messages):" << std::endl;
	weakBot.attack("Enemy");
	std::cout << std::endl;

	std::cout << "ScavTrap attack (red messages - overridden method):" << std::endl;
	strongBot.attack("Enemy");
	std::cout << std::endl;

	// Test 4: Inherited vs New Methods
	std::cout << "--- Test 4: Inherited vs New Methods ---" << std::endl;
	std::cout << "Both can use inherited takeDamage() and beRepaired():" << std::endl;
	weakBot.takeDamage(5);
	strongBot.takeDamage(5);
	std::cout << std::endl;

	weakBot.beRepaired(3);
	strongBot.beRepaired(3);
	std::cout << std::endl;

	std::cout << "Only ScavTrap has guardGate() method:" << std::endl;
	strongBot.guardGate();
	// weakBot.guardGate(); // This would cause compilation error
	std::cout << std::endl;

	// Test 5: Energy Exhaustion Comparison
	std::cout << "--- Test 5: Energy Exhaustion Comparison ---" << std::endl;
	std::cout << "ClapTrap has only 10 energy points:" << std::endl;
	for (int i = 0; i < 12; i++) {
		weakBot.attack("Target");
	}
	std::cout << std::endl;

	std::cout << "ScavTrap has 50 energy points (showing first 10 attacks):" << std::endl;
	for (int i = 0; i < 10; i++) {
		strongBot.attack("Target");
	}
	std::cout << "(... ScavTrap still has 40 energy left)" << std::endl;
	std::cout << std::endl;

	// Test 6: Orthodox Canonical Form with Inheritance
	std::cout << "--- Test 6: Orthodox Canonical Form with Inheritance ---" << std::endl;

	std::cout << "Default constructor:" << std::endl;
	ScavTrap defaultScav;
	std::cout << std::endl;

	std::cout << "Copy constructor:" << std::endl;
	ScavTrap original("Original");
	ScavTrap copy(original);
	std::cout << std::endl;

	std::cout << "Assignment operator:" << std::endl;
	ScavTrap assigned("Assigned");
	assigned = original;
	std::cout << std::endl;

	// Test 7: Polymorphic Behavior (Upcasting)
	std::cout << "--- Test 7: Upcasting Demonstration ---" << std::endl;
	std::cout << "Creating ScavTrap and treating it as ClapTrap:" << std::endl;
	ScavTrap scavBot("ScavBot");
	ClapTrap* clapPtr = &scavBot; // Upcasting

	std::cout << "Calling attack through ClapTrap pointer:" << std::endl;
	clapPtr->attack("Enemy"); // Calls ScavTrap::attack (not virtual, so actually calls ClapTrap::attack)

	std::cout << "Calling inherited methods:" << std::endl;
	clapPtr->takeDamage(10);
	clapPtr->beRepaired(5);
	// clapPtr->guardGate(); // This would cause compilation error
	std::cout << std::endl;

	// Test 8: Damage Resistance Comparison
	std::cout << "--- Test 8: Damage Resistance Comparison ---" << std::endl;
	ClapTrap fragile("Fragile");
	ScavTrap tough("Tough");

	std::cout << "Dealing 15 damage to both:" << std::endl;
	fragile.takeDamage(15); // Dies (10 HP)
	tough.takeDamage(15);   // Survives (100 HP)
	std::cout << std::endl;

	std::cout << "Trying to attack after damage:" << std::endl;
	fragile.attack("Someone"); // Should fail (dead)
	tough.attack("Someone");   // Should succeed
	std::cout << std::endl;

	// Test 9: ScavTrap Special Ability
	std::cout << "--- Test 9: ScavTrap Special Abilities ---" << std::endl;
	ScavTrap guardian("Guardian");
	std::cout << "ScavTrap using special ability:" << std::endl;
	guardian.guardGate();

	std::cout << "Guardian can still perform normal actions:" << std::endl;
	guardian.attack("Intruder");
	guardian.beRepaired(10);
	std::cout << std::endl;

	std::cout << "=== END OF TESTS - Watch destructor sequence below ===" << std::endl;
	// All objects destroyed here in reverse order of creation
}
