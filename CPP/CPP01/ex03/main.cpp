/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 12:12:48 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::cout << "=== CPP01 EX03 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

	// Test 1: Basic HumanA functionality (always armed)
	std::cout << "## Test 1: HumanA - Always armed with reference" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;

	// Test 2: Basic HumanB functionality (optionally armed)
	std::cout << "## Test 2: HumanB - Optionally armed with pointer" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << std::endl;

	// Test 3: HumanB without weapon (edge case)
	std::cout << "## Test 3: HumanB without weapon" << std::endl;
	{
		HumanB alice("Alice");
		alice.attack(); // Should handle null weapon gracefully
	}
	std::cout << std::endl;

	// Test 4: Multiple weapons and humans
	std::cout << "## Test 4: Multiple weapons and humans" << std::endl;
	{
		Weapon sword = Weapon("sharp sword");
		Weapon axe = Weapon("heavy axe");
		Weapon dagger = Weapon("quick dagger");

		HumanA knight("Knight", sword);
		HumanB rogue("Rogue");
		HumanB berserker("Berserker");

		knight.attack();

		rogue.setWeapon(dagger);
		rogue.attack();

		berserker.setWeapon(axe);
		berserker.attack();

		// Change weapon types
		sword.setType("legendary sword");
		axe.setType("enchanted axe");
		dagger.setType("poisoned dagger");

		std::cout << "-- After weapon upgrades:" << std::endl;
		knight.attack();
		rogue.attack();
		berserker.attack();
	}
	std::cout << std::endl;

	// Test 5: Weapon sharing between HumanB instances
	std::cout << "## Test 5: Weapon sharing between HumanB instances" << std::endl;
	{
		Weapon sharedWeapon = Weapon("shared club");
		HumanB fighter1("Fighter1");
		HumanB fighter2("Fighter2");

		fighter1.setWeapon(sharedWeapon);
		fighter1.attack();

		fighter2.setWeapon(sharedWeapon);
		fighter2.attack();

		// Both should reflect the change
		sharedWeapon.setType("upgraded shared weapon");
		std::cout << "-- After upgrading shared weapon:" << std::endl;
		fighter1.attack();
		fighter2.attack();
	}
	std::cout << std::endl;

	// Test 6: Edge cases - Empty weapon names
	std::cout << "## Test 6: Edge cases - Empty and unusual weapon names" << std::endl;
	{
		Weapon emptyWeapon = Weapon("");
		Weapon longWeapon = Weapon("an extremely long weapon name that tests string handling capabilities");

		HumanA emptyArmed("EmptyArmed", emptyWeapon);
		HumanB longArmed("LongArmed");

		emptyArmed.attack();

		longArmed.setWeapon(longWeapon);
		longArmed.attack();
	}
	std::cout << std::endl;

	// Test 7: Reference vs Pointer behavior demonstration
	std::cout << "## Test 7: Reference vs Pointer behavior demonstration" << std::endl;
	{
		Weapon primaryWeapon = Weapon("primary weapon");
		Weapon secondaryWeapon = Weapon("secondary weapon");

		HumanA refUser("RefUser", primaryWeapon); // Uses reference - cannot change weapon
		HumanB ptrUser("PtrUser"); // Uses pointer - can change weapon

		refUser.attack();
		ptrUser.setWeapon(primaryWeapon);
		ptrUser.attack();

		std::cout << "-- Changing PtrUser's weapon..." << std::endl;
		ptrUser.setWeapon(secondaryWeapon);
		ptrUser.attack();

		std::cout << "-- RefUser still has original weapon (cannot be changed):" << std::endl;
		refUser.attack();
	}
	std::cout << std::endl;

	// Test 8: Weapon modification during combat
	std::cout << "## Test 8: Weapon modification during combat" << std::endl;
	{
		Weapon morphWeapon = Weapon("basic staff");
		HumanA mage("Mage", morphWeapon);
		HumanB warrior("Warrior");

		mage.attack();
		warrior.setWeapon(morphWeapon);
		warrior.attack();

		// Upgrade weapon - both should see change
		morphWeapon.setType("enchanted staff");
		std::cout << "-- After enchantment:" << std::endl;
		mage.attack();
		warrior.attack();

		// Another upgrade
		morphWeapon.setType("staff of ultimate power");
		std::cout << "-- After ultimate upgrade:" << std::endl;
		mage.attack();
		warrior.attack();
	}
	std::cout << std::endl;

	// Test 9: Scope and lifetime testing
	std::cout << "## Test 9: Scope and lifetime testing" << std::endl;
	{
		std::cout << "-- Creating weapon in outer scope..." << std::endl;
		Weapon outerWeapon = Weapon("outer weapon");
		HumanB scopeTester("ScopeTester");
		{
			std::cout << "-- Entering inner scope..." << std::endl;
			HumanA innerScopeTester("InnerScopeTester", outerWeapon);
			scopeTester.setWeapon(outerWeapon);
			scopeTester.attack();
			innerScopeTester.attack();
			std::cout << "-- Exiting inner scope..." << std::endl;
		}
		std::cout << "-- Back in outer scope - weapon still valid:" << std::endl;
		scopeTester.attack();
	}
	std::cout << std::endl;

	return 0;
}
