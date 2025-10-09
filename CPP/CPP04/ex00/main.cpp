/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:11:07 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/09 14:14:59 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void testSubjectRequirements()
{
	printSeparator("SUBJECT REQUIRED TESTS");

	std::cout << "Creating objects:\n" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << "Testing getType():" << std::endl;
	std::cout << "j->getType(): " << j->getType() << std::endl;
	std::cout << "i->getType(): " << i->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Testing makeSound() - polymorphism:" << std::endl;
	i->makeSound(); // Should output cat sound!
	j->makeSound(); // Should output dog sound!
	meta->makeSound(); // Should output generic animal sound
	std::cout << std::endl;

	std::cout << "Deleting objects (watch destructor order):\n" << std::endl;
	delete i;
	delete j;
	delete meta;
}

void testPolymorphism()
{
	printSeparator("POLYMORPHISM TESTS");

	std::cout << "Test 1: Array of Animal pointers\n" << std::endl;
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	std::cout << std::endl;

	std::cout << "Calling makeSound() on each through base pointer:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Animal[" << i << "] (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	std::cout << "Deleting through base pointer (tests virtual destructor):\n" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i]; // Should call derived destructor first!
	std::cout << std::endl;

	std::cout << "Test 2: Polymorphic function parameter\n" << std::endl;
	Dog dog;
	Cat cat;
	Animal animal;

	// This works because of polymorphism
	Animal* ptr;

	ptr = &dog;
	std::cout << "Pointer to Dog: ";
	ptr->makeSound();

	ptr = &cat;
	std::cout << "Pointer to Cat: ";
	ptr->makeSound();

	ptr = &animal;
	std::cout << "Pointer to Animal: ";
	ptr->makeSound();
}

void testWrongPolymorphism()
{
	printSeparator("WRONG POLYMORPHISM (No virtual)");

	std::cout << "Creating WrongAnimal objects:\n" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << "Testing getType():" << std::endl;
	std::cout << "wrongCat->getType(): " << wrongCat->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Testing makeSound() - NO polymorphism:" << std::endl;
	std::cout << "Expected: WrongAnimal sound (not WrongCat!)" << std::endl;
	std::cout << "Actual: ";
	wrongCat->makeSound(); // ❌ Calls WrongAnimal::makeSound() - wrong!

	std::cout << "\nFor comparison, wrongMeta: ";
	wrongMeta->makeSound();
	std::cout << std::endl;

	std::cout << "WHY? makeSound() is NOT virtual in WrongAnimal!" << std::endl;
	std::cout << "This demonstrates the NEED for virtual functions.\n" << std::endl;

	std::cout << "Deleting objects:\n" << std::endl;
	delete wrongCat;
	delete wrongMeta;
}

void testCopyConstructor()
{
	printSeparator("COPY CONSTRUCTOR TESTS");

	std::cout << "Creating original Dog:\n" << std::endl;
	Dog originalDog;
	std::cout << "\nCreating copy of Dog:\n" << std::endl;
	Dog copyDog = originalDog;
	std::cout << std::endl;

	std::cout << "Both dogs making sound:" << std::endl;
	originalDog.makeSound();
	copyDog.makeSound();
	std::cout << std::endl;

	std::cout << "Exiting scope - watch destruction order:\n" << std::endl;
}

void testAssignmentOperator()
{
	printSeparator("ASSIGNMENT OPERATOR TESTS");

	std::cout << "Creating two separate Dogs:\n" << std::endl;
	Dog dog1;
	Dog dog2;
	std::cout << std::endl;

	std::cout << "Assigning dog1 to dog2:\n" << std::endl;
	dog2 = dog1;
	std::cout << std::endl;

	std::cout << "Both dogs making sound:" << std::endl;
	dog1.makeSound();
	dog2.makeSound();
	std::cout << std::endl;

	std::cout << "Exiting scope:\n" << std::endl;
}

void testVirtualDestructor()
{
	printSeparator("VIRTUAL DESTRUCTOR TEST");

	std::cout << "Creating Dog through Animal pointer:\n" << std::endl;
	Animal* animal = new Dog();
	std::cout << std::endl;

	std::cout << "Deleting through Animal pointer:" << std::endl;
	std::cout << "Expected: Dog destructor called FIRST, then Animal" << std::endl;
	std::cout << "Actual:\n" << std::endl;
	delete animal; // Virtual destructor ensures Dog destructor is called!
	std::cout << "\nIf you see Dog destructor, virtual destructor works! ✓" << std::endl;
}

void testEdgeCases()
{
	printSeparator("EDGE CASES");

	std::cout << "Test 1: Self-assignment\n" << std::endl;
	Dog dog;
	Dog dog1;
	dog = dog; // Should handle self-assignment
	dog1 = dog;
	std::cout << "Self-assignment handled ✓\n" << std::endl;

	std::cout << "Test 2: Const correctness" << std::endl;
	const Animal* constAnimal = new Dog();
	constAnimal->makeSound(); // Should work - makeSound() is const
	std::cout << "Const method works ✓\n" << std::endl;
	delete constAnimal;

	std::cout << "Test 3: Base class instantiation" << std::endl;
	Animal baseAnimal;
	baseAnimal.makeSound(); // Should work - Animal is concrete
	std::cout << "Base class can be instantiated ✓" << std::endl;
}

int main()
{
	printSeparator("CPP04 - EX00: COMPREHENSIVE TESTS");

	// Run all test suites
	testSubjectRequirements();
	testPolymorphism();
	testWrongPolymorphism();
	testCopyConstructor();
	testAssignmentOperator();
	testVirtualDestructor();
	testEdgeCases();

	std::cout << "\n========================================" << std::endl;
	std::cout << "  ALL TESTS COMPLETED!" << std::endl;
	std::cout << "========================================\n" << std::endl;
	std::cout << "Run with valgrind to check for memory leaks:" << std::endl;
	std::cout << "  valgrind --leak-check=full ./Animal" << std::endl;
	std::cout << "========================================\n" << std::endl;

	return 0;
}
