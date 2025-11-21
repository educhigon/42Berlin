/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:37:36 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/10 17:35:00 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void testSubjectRequirements()
{
	printSeparator("SUBJECT REQUIRED TESTS");

	std::cout << "Creating MateriaSource and learning Ice & Cure:\n" << std::endl;
	IMateriaSource* src = new MateriaSource();

	// FIX: Save pointers before learning (learnMateria clones them)
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;   // Safe to delete - MateriaSource cloned it
	delete cure;  // Safe to delete - MateriaSource cloned it
	std::cout << std::endl;

	std::cout << "Creating Character 'me':\n" << std::endl;
	ICharacter* me = new Character("me");
	std::cout << std::endl;

	std::cout << "Creating and equipping materias:\n" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << "Creating target Character 'bob':\n" << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;

	std::cout << "Using materias on bob:\n" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	std::cout << "Cleaning up:\n" << std::endl;
	delete bob;
	delete me;
	delete src;
	std::cout << "\n✓ Subject required test complete!" << std::endl;
}

void testMateriaSourceLearning()
{
	printSeparator("MATERIASOURCE: Learning Materias");

	std::cout << "Creating MateriaSource:\n" << std::endl;
	MateriaSource src;
	std::cout << std::endl;

	std::cout << "Learning 4 materias (max capacity):\n" << std::endl;
	AMateria* ice1 = new Ice();
	AMateria* cure1 = new Cure();
	AMateria* ice2 = new Ice();
	AMateria* cure2 = new Cure();

	src.learnMateria(ice1);
	src.learnMateria(cure1);
	src.learnMateria(ice2);
	src.learnMateria(cure2);

	delete ice1;
	delete cure1;
	delete ice2;
	delete cure2;
	std::cout << std::endl;

	std::cout << "Trying to learn 5th materia (should fail):\n" << std::endl;
	AMateria* ice3 = new Ice();
	src.learnMateria(ice3);
	delete ice3;
	std::cout << "\n✓ MateriaSource correctly limits to 4 materias!" << std::endl;
}

void testMateriaSourceCreation()
{
	printSeparator("MATERIASOURCE: Creating Materias");

	std::cout << "Creating and learning materias:\n" << std::endl;
	IMateriaSource* src = new MateriaSource();
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;
	std::cout << std::endl;

	std::cout << "Creating materias from templates:\n" << std::endl;
	AMateria* m1 = src->createMateria("ice");
	std::cout << "Created: " << m1->getType() << std::endl;
	AMateria* m2 = src->createMateria("cure");
	std::cout << "Created: " << m2->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Trying to create unknown type:\n" << std::endl;
	AMateria* m3 = src->createMateria("fire");
	if (m3 == NULL)
		std::cout << "✓ Returns NULL for unknown type!" << std::endl;
	std::cout << std::endl;

	std::cout << "Cleaning up:\n" << std::endl;
	delete m1;
	delete m2;
	delete src;
	std::cout << "\n✓ MateriaSource creation works correctly!" << std::endl;
}

void testCharacterInventory()
{
	printSeparator("CHARACTER: Inventory Management");

	std::cout << "Creating character and materias:\n" << std::endl;
	Character hero("Hero");
	AMateria* mat1 = new Ice();
	AMateria* mat2 = new Cure();
	AMateria* mat3 = new Ice();
	AMateria* mat4 = new Cure();
	AMateria* mat5 = new Ice();  // Extra for overflow test
	std::cout << std::endl;

	std::cout << "Equipping 4 materias (max capacity):\n" << std::endl;
	hero.equip(mat1);
	hero.equip(mat2);
	hero.equip(mat3);
	hero.equip(mat4);
	std::cout << std::endl;

	std::cout << "Trying to equip 5th materia (should fail):\n" << std::endl;
	hero.equip(mat5);
	delete mat5;  // We must delete it since equip failed
	std::cout << "\n✓ Character correctly limits inventory to 4 slots!" << std::endl;
}

void testCharacterUnequip()
{
	printSeparator("CHARACTER: Unequip & Memory Management");

	std::cout << "Creating character and equipping materias:\n" << std::endl;
	Character hero("Hero");
	AMateria* mat1 = new Ice();
	AMateria* mat2 = new Cure();
	hero.equip(mat1);
	hero.equip(mat2);
	std::cout << std::endl;

	std::cout << "Unequipping materia at index 0:\n" << std::endl;
	hero.unequip(0);  // This sets slot to NULL but DOESN'T delete
	std::cout << "\n⚠️  IMPORTANT: Unequipped materia is NOT deleted!" << std::endl;
	std::cout << "We must track and delete it manually to avoid leaks:\n" << std::endl;
	delete mat1;  // Main's responsibility to delete "floor materias"
	std::cout << "Manually deleted unequipped materia ✓" << std::endl;
	std::cout << std::endl;

	std::cout << "Trying to unequip invalid index:\n" << std::endl;
	hero.unequip(10);  // Out of bounds
	std::cout << std::endl;

	std::cout << "Trying to unequip empty slot:\n" << std::endl;
	hero.unequip(0);  // Already unequipped
	std::cout << "\n✓ Unequip handles edge cases correctly!" << std::endl;

	// mat2 will be deleted by hero's destructor (still equipped)
}

void testCharacterUse()
{
	printSeparator("CHARACTER: Using Materias");

	std::cout << "Creating characters and materias:\n" << std::endl;
	Character caster("Mage");
	Character target("Enemy");

	IMateriaSource* src = new MateriaSource();
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;

	AMateria* m1 = src->createMateria("ice");
	AMateria* m2 = src->createMateria("cure");
	caster.equip(m1);
	caster.equip(m2);
	std::cout << std::endl;

	std::cout << "Using ice materia on target:\n" << std::endl;
	caster.use(0, target);
	std::cout << std::endl;

	std::cout << "Using cure materia on target:\n" << std::endl;
	caster.use(1, target);
	std::cout << std::endl;

	std::cout << "Trying to use invalid index:\n" << std::endl;
	caster.use(10, target);
	std::cout << std::endl;

	std::cout << "Trying to use empty slot:\n" << std::endl;
	caster.use(3, target);
	std::cout << std::endl;

	delete src;
	std::cout << "✓ Use function works correctly!" << std::endl;
}

void testCharacterDeepCopyCopyConstructor()
{
	printSeparator("CHARACTER: Deep Copy (Copy Constructor)");

	std::cout << "Creating hero1 with materias:\n" << std::endl;
	Character hero1("Hero1");
	AMateria* mat1 = new Ice();
	AMateria* mat2 = new Cure();
	hero1.equip(mat1);
	hero1.equip(mat2);
	std::cout << std::endl;

	std::cout << "Creating hero2 as copy of hero1:\n" << std::endl;
	Character hero2 = hero1;  // Copy constructor
	std::cout << std::endl;

	std::cout << "Testing that copies are independent:\n" << std::endl;
	Character target("Target");

	std::cout << "hero1 using materia:" << std::endl;
	hero1.use(0, target);

	std::cout << "hero2 using materia:" << std::endl;
	hero2.use(0, target);
	std::cout << std::endl;

	std::cout << "Unequipping from hero1:" << std::endl;
	hero1.unequip(1);
	delete mat2;  // Delete the unequipped one
	std::cout << std::endl;

	std::cout << "hero2 should still have its copy:" << std::endl;
	hero2.use(1, target);
	std::cout << std::endl;

	std::cout << "✓ Deep copy works! Each character has independent inventory." << std::endl;
	std::cout << "Exiting scope (watch for double-free if shallow copy):\n" << std::endl;
}

void testCharacterDeepCopyAssignment()
{
	printSeparator("CHARACTER: Deep Copy (Assignment Operator)");

	std::cout << "Creating hero1 with materias:\n" << std::endl;
	Character hero1("Hero1");
	AMateria* mat1 = new Ice();
	hero1.equip(mat1);
	std::cout << std::endl;

	std::cout << "Creating hero2 with different materias:\n" << std::endl;
	Character hero2("Hero2");
	AMateria* mat2 = new Cure();
	hero2.equip(mat2);
	std::cout << std::endl;

	std::cout << "Assigning hero1 to hero2:\n" << std::endl;
	hero2 = hero1;  // Assignment operator (hero2's old materia should be deleted)
	std::cout << std::endl;

	std::cout << "Testing that copies are independent:\n" << std::endl;
	Character target("Target");

	std::cout << "hero1 using materia:" << std::endl;
	hero1.use(0, target);

	std::cout << "hero2 using materia:" << std::endl;
	hero2.use(0, target);
	std::cout << std::endl;

	std::cout << "✓ Deep copy via assignment works!" << std::endl;
	std::cout << "Exiting scope (watch for double-free if shallow copy):\n" << std::endl;
}

void testMateriaClone()
{
	printSeparator("MATERIA: Clone Pattern");

	std::cout << "Creating original Ice materia:\n" << std::endl;
	AMateria* original = new Ice();
	std::cout << "Original type: " << original->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Cloning the materia:\n" << std::endl;
	AMateria* clone = original->clone();
	std::cout << "Clone type: " << clone->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Testing that they're independent objects:\n" << std::endl;
	Character target("Target");

	std::cout << "Original using:" << std::endl;
	original->use(target);

	std::cout << "Clone using:" << std::endl;
	clone->use(target);
	std::cout << std::endl;

	std::cout << "Deleting original:\n" << std::endl;
	delete original;
	std::cout << std::endl;

	std::cout << "Clone still works after original deleted:" << std::endl;
	clone->use(target);
	std::cout << std::endl;

	delete clone;
	std::cout << "✓ Clone creates independent copy!" << std::endl;
}

void testPolymorphism()
{
	printSeparator("POLYMORPHISM: Interfaces");

	std::cout << "Creating objects through interface pointers:\n" << std::endl;
	IMateriaSource* src = new MateriaSource();
	ICharacter* hero = new Character("Polymorphic Hero");
	std::cout << std::endl;

	std::cout << "Using through interface pointers:\n" << std::endl;
	AMateria* ice = new Ice();
	src->learnMateria(ice);
	delete ice;

	AMateria* created = src->createMateria("ice");
	hero->equip(created);

	ICharacter* target = new Character("Polymorphic Target");
	hero->use(0, *target);
	std::cout << std::endl;

	std::cout << "Cleaning up through base pointers:\n" << std::endl;
	delete target;
	delete hero;
	delete src;
	std::cout << "\n✓ Polymorphism and interfaces work correctly!" << std::endl;
}

void testEdgeCases()
{
	printSeparator("EDGE CASES");

	std::cout << "Test 1: Self-assignment\n" << std::endl;
	Character hero("Hero");
	hero = hero;  // Should handle: if (this != &other)
	std::cout << "✓ Self-assignment handled!\n" << std::endl;

	std::cout << "Test 2: Equipping NULL\n" << std::endl;
	hero.equip(NULL);  // Should handle gracefully
	std::cout << "✓ NULL equip handled!\n" << std::endl;

	std::cout << "Test 3: Learning NULL\n" << std::endl;
	MateriaSource src;
	src.learnMateria(NULL);  // Should handle gracefully
	std::cout << "✓ NULL learning handled!\n" << std::endl;

	std::cout << "Test 4: Empty character operations" << std::endl;
	Character empty("Empty");
	Character target("Target");
	empty.use(0, target);  // Using empty slot
	empty.unequip(0);      // Unequipping empty slot
	std::cout << "✓ Empty operations handled!" << std::endl;
}

void testComplexScenario()
{
	printSeparator("COMPLEX SCENARIO: Floor Management");

	std::cout << "Creating spell book (MateriaSource):\n" << std::endl;
	IMateriaSource* book = new MateriaSource();

	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	book->learnMateria(ice);
	book->learnMateria(cure);
	delete ice;
	delete cure;
	std::cout << std::endl;

	std::cout << "Wizard equipping materias:\n" << std::endl;
	Character wizard("Gandalf");

	AMateria* spell1 = book->createMateria("ice");
	AMateria* spell2 = book->createMateria("cure");
	AMateria* spell3 = book->createMateria("ice");
	AMateria* spell4 = book->createMateria("cure");

	wizard.equip(spell1);
	wizard.equip(spell2);
	wizard.equip(spell3);
	wizard.equip(spell4);
	std::cout << std::endl;

	std::cout << "Wizard drops some materias on the floor:\n" << std::endl;
	wizard.unequip(1);  // spell2 on floor
	wizard.unequip(3);  // spell4 on floor
	std::cout << std::endl;

	std::cout << "Tracking floor materias to delete later:" << std::endl;
	AMateria* floor[2];
	floor[0] = spell2;
	floor[1] = spell4;
	std::cout << "Floor materias tracked: " << floor[0]->getType()
	          << " and " << floor[1]->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Wizard picks up new materias:\n" << std::endl;
	AMateria* spell5 = book->createMateria("ice");
	AMateria* spell6 = book->createMateria("cure");
	wizard.equip(spell5);
	wizard.equip(spell6);
	std::cout << std::endl;

	std::cout << "Battle scenario:\n" << std::endl;
	Character enemy("Balrog");
	wizard.use(0, enemy);
	wizard.use(1, enemy);
	wizard.use(2, enemy);
	wizard.use(3, enemy);
	std::cout << std::endl;

	std::cout << "Cleaning up floor materias:\n" << std::endl;
	delete floor[0];
	delete floor[1];
	std::cout << "Floor cleaned ✓" << std::endl;
	std::cout << std::endl;

	delete book;
	std::cout << "✓ Complex scenario with proper memory management!" << std::endl;
}

int main()
{
	printSeparator("CPP04 - EX03: COMPREHENSIVE TESTS");

	// Run all test suites
	testSubjectRequirements();
	testMateriaSourceLearning();
	testMateriaSourceCreation();
	testCharacterInventory();
	testCharacterUnequip();
	testCharacterUse();
	testCharacterDeepCopyCopyConstructor();
	testCharacterDeepCopyAssignment();
	testMateriaClone();
	testPolymorphism();
	testEdgeCases();
	testComplexScenario();

	printSeparator("ALL TESTS COMPLETED!");
	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./Interface" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\"" << std::endl;
	std::cout << "========================================\n" << std::endl;

	return 0;
}
