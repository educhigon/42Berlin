/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:16:02 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 16:21:39 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "=== CPP03 EX01 - SCAVTRAP INHERITANCE TESTS ===" << std::endl << std::endl;

	std::cout << "--- Test 0: Very basic set of test ---" << std::endl;
	std::cout << "0.1: Only Parent ---" << std::endl;

	ClapTrap x;           // Default constructor
	ClapTrap y(x);        // Copy constructor (not assignment!)
	ClapTrap z = x;       // Also copy constructor! (confusing syntax)
	ClapTrap w;
	w = x;             // Copy assignment operator

	std::cout << std::endl;
	std::cout << "0.2: Calling on Child - Parent should also be called ---" << std::endl;
	ScavTrap xx;           // Default constructor
	ScavTrap yy(xx);        // Copy constructor (not assignment!)
	ScavTrap zz = xx;       // Also copy constructor! (confusing syntax)
	ScavTrap ww;
	ww = xx;             // Copy assignment operator

	std::cout << std::endl;
	std::cout << "0.3: Calling another Child - Parent should also be called ---" << std::endl;
	FragTrap xxx;           // Default constructor
	FragTrap yyy(xxx);        // Copy constructor (not assignment!)
	FragTrap zzz = xxx;       // Also copy constructor! (confusing syntax)
	FragTrap www;
	www = xxx;             // Copy assignment operator

	std::cout << std::endl;
	// Test 1: Constructor/Destructor Chaining
	std::cout << "--- Test 1: Constructor/Destructor Chaining ---" << std::endl;
	{
		std::cout << "Creating ClapTrap 'BasicBot':" << std::endl;
		ClapTrap basic("BasicBot");
		std::cout << std::endl;

		std::cout << "Creating FragTrap 'AdvancedBot':" << std::endl;
		FragTrap advanced("AdvancedBot");
		std::cout << "(Notice: ClapTrap constructor called first, then FragTrap)" << std::endl;
		std::cout << std::endl;

		std::cout << "About to exit scope - watch destructor order:" << std::endl;
	} // Destructors called here: FragTrap first, then ClapTrap
	std::cout << std::endl;

	// Test 2: Stats Comparison (ClapTrap vs FragTrap)
	std::cout << "--- Test 2: Stats Comparison ---" << std::endl;
	ClapTrap weakBot("WeakBot");
	FragTrap strongBot("StrongBot");
	std::cout << std::endl;

	std::cout << "EXPECTED: ClapTrap stats: 10 HP, 10 Energy, 0 Damage" << std::endl;
	std::cout << "EXPECTED: FragTrap stats: 100 HP, 50 Energy, 20 Damage" << std::endl;
	std::cout << std::endl;

	// Test 3: Attack Method Override
	std::cout << "--- Test 3: Attack Method Override ---" << std::endl;
	std::cout << "ClapTrap attack (green messages):" << std::endl;
	weakBot.attack("Enemy");
	std::cout << std::endl;

	std::cout << "FragTrap attack (red messages - overridden method):" << std::endl;
	strongBot.attack("Enemy");
	std::cout << "### ClapTrap and FragTrap stats are like EXPECTED" << std::endl;
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

	std::cout << "Only FragTrap has highFivesGuys() method:" << std::endl;
	strongBot.highFivesGuys();
	// weakBot.highFivesGuys(); // This would cause compilation error
	std::cout << std::endl;

	// Test 5: Energy Exhaustion Comparison
	std::cout << "--- Test 5: Energy Exhaustion Comparison ---" << std::endl;
	std::cout << "ClapTrap has only 10 energy points:" << std::endl;
	for (int i = 0; i < 12; i++) {
		weakBot.attack("Target");
	}
	std::cout << std::endl;

	std::cout << "FragTrap has 50 energy points (showing first 10 attacks):" << std::endl;
	for (int i = 0; i < 10; i++) {
		strongBot.attack("Target");
	}
	std::cout << "(... FragTrap still has 90 energy left)" << std::endl;
	std::cout << std::endl;

	// Test 6: Orthodox Canonical Form with Inheritance
	std::cout << "--- Test 6: Orthodox Canonical Form with Inheritance ---" << std::endl;

	std::cout << "Default constructor:" << std::endl;
	FragTrap defaultScav;
	std::cout << std::endl;

	std::cout << "Copy constructor:" << std::endl;
	FragTrap original("Original");
	FragTrap copy(original);
	std::cout << std::endl;

	std::cout << "Assignment operator:" << std::endl;
	FragTrap assigned("Assigned");
	assigned = original;
	std::cout << std::endl;

	// Test 7: Polymorphic Behavior (Upcasting)
	std::cout << "--- Test 7: Upcasting Demonstration (Polymorphic Behavior) ---" << std::endl;
	std::cout << "--- Remove VIRTUAL keyword to show different behaviour ---" << std::endl;
	std::cout << "Creating FragTrap and treating it as ClapTrap:" << std::endl;
	FragTrap scavBot("ScavBot");
	ClapTrap* clapPtr = &scavBot; // Upcasting

	std::cout << "Calling attack through ClapTrap pointer:" << std::endl;
	clapPtr->attack("Enemy"); // Calls FragTrap::attack (not virtual, so actually calls ClapTrap::attack)

	std::cout << "Calling inherited methods:" << std::endl;
	clapPtr->takeDamage(10);
	clapPtr->beRepaired(5);
	// clapPtr->highFivesGuys(); // This would cause compilation error
	std::cout << std::endl;

	// Test 8: Damage Resistance Comparison
	std::cout << "--- Test 8: Damage Resistance Comparison ---" << std::endl;
	ClapTrap fragile("Fragile");
	FragTrap tough("Tough");

	std::cout << "Dealing 15 damage to both:" << std::endl;
	fragile.takeDamage(15); // Dies (10 HP)
	tough.takeDamage(15);   // Survives (100 HP)
	std::cout << std::endl;

	std::cout << "Trying to attack after damage:" << std::endl;
	fragile.attack("Someone"); // Should fail (dead)
	tough.attack("Someone");   // Should succeed
	std::cout << std::endl;

	// Test 9: FragTrap Special Ability
	std::cout << "--- Test 9: FragTrap Special Abilities ---" << std::endl;
	FragTrap guardian("Guardian");
	std::cout << "FragTrap using special ability:" << std::endl;
	guardian.highFivesGuys();

	std::cout << "Guardian can still perform normal actions:" << std::endl;
	guardian.attack("Intruder");
	guardian.beRepaired(10);
	std::cout << std::endl;

	std::cout << "=== END OF TESTS - Watch destructor sequence below ===" << std::endl;
	// All objects destroyed here in reverse order of creation
}
