/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:16:02 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/25 21:54:53 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== CPP03 EX00 - ORTHODOX CANONICAL FORM TESTS ===" << std::endl << std::endl;

	// Test 0: Basic constructor and destructor
	std::cout << "--- Test 0: Basic tests ---" << std::endl;
	{
		ClapTrap a("num1");
		ClapTrap b("num2");
		std::cout << std::endl;

		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		a.attack("num2");
		std::cout << std::endl;

		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		b.beRepaired(10);
		std::cout << std::endl;

		a.takeDamage(3);
		a.takeDamage(3);
		a.takeDamage(3);
		a.takeDamage(3);
		a.takeDamage(3);
		a.takeDamage(3);
		a.takeDamage(3);
		a.takeDamage(3);
		a.takeDamage(3);
		a.takeDamage(3);
		std::cout << std::endl;

		b.takeDamage(30);
		b.takeDamage(30);
		b.takeDamage(30);
		b.takeDamage(30);
		b.takeDamage(30);
		b.takeDamage(30);
		b.takeDamage(30);
		b.takeDamage(30);
		b.takeDamage(30);
		b.takeDamage(30);
		std::cout << std::endl;

	}
	std::cout << std::endl;

	// Test 1: Basic constructor and destructor
	std::cout << "--- Test 1: Basic Constructor & Destructor ---" << std::endl;
	{
		ClapTrap robot("R2D2");
		std::cout << "(R2D2 created in this scope)" << std::endl;
	} // R2D2 destroyed here
	std::cout << std::endl;

	// Test 2: Default constructor
	std::cout << "--- Test 2: Default Constructor ---" << std::endl;
	ClapTrap anonymous;
	std::cout << std::endl;

	// Test 3: Copy constructor
	std::cout << "--- Test 3: Copy Constructor ---" << std::endl;
	ClapTrap original("Master");
	std::cout << "About to copy 'Master'..." << std::endl;
	ClapTrap copy(original);
	std::cout << "Copy created successfully!" << std::endl;
	std::cout << std::endl;

	// Test 4: Assignment operator
	std::cout << "--- Test 4: Assignment Operator ---" << std::endl;
	ClapTrap target("Target");
	std::cout << "About to assign 'Master' to 'Target'..." << std::endl;
	target = original;
	std::cout << "Assignment completed!" << std::endl;
	std::cout << std::endl;

	// Test 5: Self-assignment (edge case)
	std::cout << "--- Test 5: Self-Assignment Edge Case ---" << std::endl;
	std::cout << "About to do original = original..." << std::endl;
	original = original;
	std::cout << "Self-assignment handled!" << std::endl;
	std::cout << std::endl;

	// Test 6: Chain assignment
	std::cout << "--- Test 6: Chain Assignment ---" << std::endl;
	ClapTrap a("A"), b("B"), c("C");
	std::cout << "About to do: c = b = a..." << std::endl;
	c = b = a;
	std::cout << "Chain assignment completed!" << std::endl;
	std::cout << std::endl;

	// Test 7: Copy constructor vs Assignment operator
	std::cout << "--- Test 7: Copy Constructor vs Assignment Operator ---" << std::endl;
	ClapTrap source("Source");

	std::cout << "Using copy constructor: ClapTrap copyVersion(source);" << std::endl;
	ClapTrap copyVersion(source);  // Copy constructor

	std::cout << "Using assignment operator: ClapTrap assignVersion; assignVersion = source;" << std::endl;
	ClapTrap assignVersion;  // Default constructor
	assignVersion = source;  // Assignment operator
	std::cout << std::endl;

	// Test 8: Functional testing with copied objects
	std::cout << "--- Test 8: Functional Testing with Copied Objects ---" << std::endl;
	ClapTrap fighter("Fighter");
	ClapTrap clone(fighter);  // Copy the fighter

	std::cout << "Original fighter attacks:" << std::endl;
	fighter.attack("Enemy");

	std::cout << "Cloned fighter attacks:" << std::endl;
	clone.attack("Enemy");

	std::cout << "Original takes damage:" << std::endl;
	fighter.takeDamage(5);

	std::cout << "Clone repairs itself:" << std::endl;
	clone.beRepaired(3);
	std::cout << std::endl;

	// Test 9: Multiple copies
	std::cout << "--- Test 9: Multiple Copies ---" << std::endl;
	ClapTrap prototype("Proto");
	ClapTrap copy1(prototype);
	ClapTrap copy2(copy1);
	ClapTrap copy3;
	copy3 = copy2;
	std::cout << "Created prototype -> copy1 -> copy2 -> copy3 chain" << std::endl;
	std::cout << std::endl;

	// Test 10: Scope and automatic destruction
	std::cout << "--- Test 10: Scope and Automatic Destruction ---" << std::endl;
	std::cout << "Creating robots in nested scopes..." << std::endl;
	{
		ClapTrap outer("Outer");
		{
			ClapTrap inner("Inner");
			ClapTrap innerCopy(outer);
			std::cout << "Copied outer to innerCopy with name 'Outer'" << std::endl;
			std::cout << "About to exit inner scope..." << std::endl;
		} // inner and innerCopy destroyed here
		std::cout << "Back in outer scope..." << std::endl;
	} // outer destroyed here
	std::cout << "Back in main scope" << std::endl;
	std::cout << std::endl;

	std::cout << "=== END OF TESTS - Watch destructor sequence below ===" << std::endl;
	// All remaining objects destroyed here in reverse order of creation
}
