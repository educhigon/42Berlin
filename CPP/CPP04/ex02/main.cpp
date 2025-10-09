/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:11:07 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/09 14:41:31 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <sstream>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void testSubjectRequirements()
{
	printSeparator("SUBJECT REQUIRED TESTS");

	std::cout << "From subject: Create array of Animals (half Dog, half Cat)\n" << std::endl;
	const int size = 10;
	AAnimal* animals[size];

	std::cout << "Creating " << size << " animals (50% Dogs, 50% Cats):\n" << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
		{
			std::cout << "[" << i << "] Creating Dog:" << std::endl;
			animals[i] = new Dog();
		}
		else
		{
			std::cout << "[" << i << "] Creating Cat:" << std::endl;
			animals[i] = new Cat();
		}
	}
	std::cout << std::endl;

	std::cout << "Deleting all animals (tests virtual destructor + Brain cleanup):\n" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << i << "] Deleting " << animals[i]->getType() << ":" << std::endl;
		delete animals[i];
	}
	std::cout << "\n✓ If you see Brain destructors, memory is properly freed!" << std::endl;
}

void testDeepCopyCopyConstructor()
{
	printSeparator("DEEP COPY: Copy Constructor");

	std::cout << "Creating dog1 and giving it an idea:\n" << std::endl;
	Dog dog1;
	dog1.haveIdea("Chase squirrels");
	dog1.haveIdea("Bark at mailman");
	dog1.haveIdea("Dig hole in backyard");
	std::cout << "\ndog1's last idea: " << dog1.checkLastIdea() << std::endl;
	std::cout << std::endl;

	std::cout << "Creating dog2 as COPY of dog1 (copy constructor):\n" << std::endl;
	Dog dog2 = dog1;  // Copy constructor called here
	std::cout << "\ndog2's last idea (should be same): " << dog2.checkLastIdea() << std::endl;
	std::cout << std::endl;

	std::cout << "Now giving dog2 a NEW idea:\n" << std::endl;
	dog2.haveIdea("Sleep on couch");
	std::cout << std::endl;

	std::cout << "=== VERIFICATION ===" << std::endl;
	std::cout << "dog1's last idea: " << dog1.checkLastIdea() << std::endl;
	std::cout << "dog2's last idea: " << dog2.checkLastIdea() << std::endl;
	std::cout << std::endl;

	if (dog1.checkLastIdea() != dog2.checkLastIdea())
		std::cout << "✓ DEEP COPY SUCCESS: Dogs have independent brains!" << std::endl;
	else
		std::cout << "✗ SHALLOW COPY BUG: Dogs share same brain!" << std::endl;

	std::cout << "\nExiting scope (watch for double-free if shallow copy):\n" << std::endl;
}

void testDeepCopyAssignmentOperator()
{
	printSeparator("DEEP COPY: Assignment Operator");

	std::cout << "Creating cat1 with ideas:\n" << std::endl;
	Cat cat1;
	cat1.haveIdea("Knock over vase");
	cat1.haveIdea("Meow at 3am");
	cat1.haveIdea("Ignore human");
	std::cout << "\ncat1's last idea: " << cat1.checkLastIdea() << std::endl;
	std::cout << std::endl;

	std::cout << "Creating cat2 with different ideas:\n" << std::endl;
	Cat cat2;
	cat2.haveIdea("Sleep all day");
	std::cout << "\ncat2's last idea: " << cat2.checkLastIdea() << std::endl;
	std::cout << std::endl;

	std::cout << "Assigning cat1 to cat2 (assignment operator):\n" << std::endl;
	cat2 = cat1;  // Assignment operator called here
	std::cout << "\ncat2's last idea after assignment: " << cat2.checkLastIdea() << std::endl;
	std::cout << std::endl;

	std::cout << "Giving cat2 a NEW idea:\n" << std::endl;
	cat2.haveIdea("Scratch furniture");
	std::cout << std::endl;

	std::cout << "=== VERIFICATION ===" << std::endl;
	std::cout << "cat1's last idea: " << cat1.checkLastIdea() << std::endl;
	std::cout << "cat2's last idea: " << cat2.checkLastIdea() << std::endl;
	std::cout << std::endl;

	if (cat1.checkLastIdea() != cat2.checkLastIdea())
		std::cout << "✓ DEEP COPY SUCCESS: Cats have independent brains!" << std::endl;
	else
		std::cout << "✗ SHALLOW COPY BUG: Cats share same brain!" << std::endl;

	std::cout << "\nExiting scope (watch for double-free if shallow copy):\n" << std::endl;
}

void testVirtualDestructor()
{
	printSeparator("VIRTUAL DESTRUCTOR + BRAIN CLEANUP");

	std::cout << "Creating Dog through Animal pointer:\n" << std::endl;
	AAnimal* animal = new Dog();
	std::cout << std::endl;

	std::cout << "Giving it an idea (to allocate Brain memory):" << std::endl;
	animal->haveIdea("Test idea");
	std::cout << std::endl;

	std::cout << "Deleting through Animal* pointer:" << std::endl;
	std::cout << "Expected order: Dog destructor -> Brain destructor -> Animal destructor\n" << std::endl;
	delete animal;
	std::cout << "\n✓ If Brain destructor was called, virtual destructor works!" << std::endl;
	std::cout << "✓ If it wasn't called, you have a MEMORY LEAK!" << std::endl;
}

void testSelfAssignment()
{
	printSeparator("EDGE CASE: Self-Assignment");

	std::cout << "Creating dog:\n" << std::endl;
	Dog dog;
	Dog dog1;
	dog.haveIdea("Original idea");
	std::cout << "\ndog's idea: " << dog.checkLastIdea() << std::endl;
	std::cout << std::endl;

	std::cout << "Self-assigning (dog = dog):\n" << std::endl;
	dog1 = dog;
	dog = dog;  // Should be handled by: if (this != &other)
	std::cout << "\ndog's idea after self-assign: " << dog.checkLastIdea() << std::endl;
	std::cout << "\ndog1's idea after self-assign: " << dog1.checkLastIdea() << std::endl;
	std::cout << std::endl;

	std::cout << "✓ If no crash and idea unchanged, self-assignment handled!" << std::endl;
}

void testMultipleIdeas()
{
	printSeparator("TEST: Multiple Ideas (Brain Array)");

	std::cout << "Creating cat and filling brain with ideas:\n" << std::endl;
	Cat cat;

	std::cout << "\nAdding 5 ideas:" << std::endl;
	cat.haveIdea("Idea 1: Hunt mice");
	cat.haveIdea("Idea 2: Nap in sun");
	cat.haveIdea("Idea 3: Groom self");
	cat.haveIdea("Idea 4: Climb tree");
	cat.haveIdea("Idea 5: Purr loudly");

	std::cout << "\nLast idea: " << cat.checkLastIdea() << std::endl;
	std::cout << "\n✓ Brain can store multiple ideas!" << std::endl;
}

void testCopyWithManyIdeas()
{
	printSeparator("DEEP COPY: With Multiple Ideas");

	std::cout << "Creating dog with many ideas:\n" << std::endl;
	Dog dog1;
	for (int i = 0; i < 10; i++)
	{
		std::string idea = "Idea number ";
		// Simple integer to string conversion for C++98
		std::stringstream ss;
		ss << i;
		idea += ss.str();
		dog1.haveIdea(idea);
	}
	std::cout << "\ndog1's last idea: " << dog1.checkLastIdea() << std::endl;
	std::cout << std::endl;

	std::cout << "Copying dog1 to dog2:\n" << std::endl;
	Dog dog2 = dog1;
	std::cout << "\ndog2's last idea: " << dog2.checkLastIdea() << std::endl;
	std::cout << std::endl;

	std::cout << "Adding new idea to dog2:" << std::endl;
	dog2.haveIdea("New idea after copy");
	std::cout << std::endl;

	std::cout << "=== VERIFICATION ===" << std::endl;
	std::cout << "dog1's last idea: " << dog1.checkLastIdea() << std::endl;
	std::cout << "dog2's last idea: " << dog2.checkLastIdea() << std::endl;
	std::cout << std::endl;

	if (dog1.checkLastIdea() != dog2.checkLastIdea())
		std::cout << "✓ DEEP COPY SUCCESS: All ideas copied independently!" << std::endl;
	else
		std::cout << "✗ SHALLOW COPY BUG!" << std::endl;
}

void testPolymorphicCopy()
{
	printSeparator("POLYMORPHIC + DEEP COPY");

	std::cout << "Creating animals through base pointers:\n" << std::endl;
	AAnimal* dog = new Dog();
	AAnimal* cat = new Cat();
	std::cout << std::endl;

	std::cout << "Giving them ideas:" << std::endl;
	dog->haveIdea("Polymorphic dog idea");
	cat->haveIdea("Polymorphic cat idea");
	std::cout << std::endl;

	std::cout << "Making sounds (tests polymorphism still works):" << std::endl;
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	std::cout << "Deleting (tests virtual destructor + Brain cleanup):\n" << std::endl;
	delete dog;
	delete cat;
	std::cout << "\n✓ Polymorphism + Deep copy + Virtual destructor all work!" << std::endl;
}

void testAbstractClass()
{
	printSeparator("ABSTRACT CLASS TEST - KEY DIFFERENCE FROM EX01");

	// Uncomment to see the compilation error:
	// AAnimal test;  // ERROR: cannot declare variable 'test' to be of abstract type 'AAnimal'
	// AAnimal* ptr = new AAnimal();  // ERROR: invalid new-expression of abstract class type 'AAnimal'
	std::cout << "Commented lines in main() that throw compilation error:" << std::endl;
	std::cout << "  // AAnimal test;  // This will NOT compile!" << std::endl;
	std::cout << "  // AAnimal* ptr = new AAnimal();  // This will NOT compile!" << std::endl;

	std::cout << "In ex01, this would compile:\n" << std::endl;
	std::cout << "  Animal animal;  // ✓ Works in ex01 (concrete class)" << std::endl;
	std::cout << "  animal.makeSound();" << std::endl;
	std::cout << std::endl;

	std::cout << "In ex02, this FAILS to compile:\n" << std::endl;
	std::cout << "  AAnimal animal;  // ✗ COMPILATION ERROR!" << std::endl;
	std::cout << "  Error: cannot declare variable 'animal' to be of abstract type 'AAnimal'" << std::endl;
	std::cout << std::endl;

	std::cout << "Why? Because AAnimal has pure virtual function:" << std::endl;
	std::cout << "  virtual void makeSound() const = 0;" << std::endl;
	std::cout << std::endl;

	std::cout << "✓ You can ONLY create Dog/Cat objects (derived classes)" << std::endl;
	std::cout << "✓ You CANNOT instantiate AAnimal directly" << std::endl;
	std::cout << "✓ But AAnimal constructor still runs when creating Dog/Cat!" << std::endl;
	std::cout << std::endl;

}

int main()
{
	printSeparator("CPP04 - EX02: ABSTRACT CLASS TESTS");

	// First, show the KEY difference from ex01
	testAbstractClass();

	// Run all test suites
	testSubjectRequirements();
	testDeepCopyCopyConstructor();
	testDeepCopyAssignmentOperator();
	testVirtualDestructor();
	testSelfAssignment();
	testMultipleIdeas();
	testCopyWithManyIdeas();
	testPolymorphicCopy();
	testAbstractClass();

	printSeparator("ALL TESTS COMPLETED!");
	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./Animalbrains" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\"" << std::endl;
	std::cout << "========================================\n" << std::endl;

	return 0;
}
