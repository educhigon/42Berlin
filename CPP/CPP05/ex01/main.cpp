/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <sstream>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}
void basicTestsBureaucrat()
{
	printSeparator("basicTestsBureaucrat");
	Bureaucrat x("John", 150);           // Default constructor
	Bureaucrat y(x);        // Copy constructor (not assignment!)
	Bureaucrat z = x;       // Also copy constructor! (confusing syntax)
	Bureaucrat w("Peter", 1);
	w = x;             // Copy assignment operator
}

void basicTestsBureaucratFail1()
{
	printSeparator("basicTestsBureaucratFail1");
	try {
		Bureaucrat x("John", 151);           // Default constructor
	} catch (std::exception& e) {
		std::cout << "Exception caught while creating bureaucrat: " << e.what() << std::endl;
	}

}

void basicTestsBureaucratFail2()
{
	printSeparator("basicTestsBureaucratFail2");
	try {
		Bureaucrat x("John", 0);           // Default constructor
	} catch (std::exception& e) {
		std::cout << "Exception caught while creating bureaucrat: " << e.what() << std::endl;
	}
}

void basicFunctionalityBureaucratFail()
{
	printSeparator("basicFunctionalityBureaucratFail");
	Bureaucrat x("John", 150);           // Default constructor
	Bureaucrat w("Peter", 1);
	std::cout << x.getName() << " has grade " << x.getGrade() << std::endl;
	std::cout << w.getName() << " has grade " << w.getGrade() << std::endl;
	try {
		w.incrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught while incrementing grade of " << w.getName() << ": " << e.what() << std::endl;
	}
	try {
		w.decrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught while decrementing grade of " << w.getName() << ": " << e.what() << std::endl;
	}

}

void basicFunctionalityBureaucratPass()
{
	printSeparator("basicFunctionalityBureaucratPass");
	Bureaucrat x("John", 150);           // Default constructor
	Bureaucrat w("Peter", 1);
	std::cout << x.getName() << " has grade " << x.getGrade() << std::endl;
	std::cout << w.getName() << " has grade " << w.getGrade() << std::endl;
	try {
		w.decrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught while decrementing grade of " << w.getName() << ": " << e.what() << std::endl;
	}
	try {
		w.incrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught while incrementing grade of " << w.getName() << ": " << e.what() << std::endl;
	}

	try {
		x.incrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught while incrementing grade of " << x.getName() << ": " << e.what() << std::endl;
	}
	try {
		x.decrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception caught while decrementing grade of " << x.getName() << ": " << e.what() << std::endl;
	}

}

void printBureaucrat()
{
	printSeparator("printBureaucrat");
	Bureaucrat x("John", 1);           // Default constructor
	std::cout << x << std::endl;
}

// -------------------------------------- ------------------- -------------------


void basicTestsForm()
{
	printSeparator("basicTestsForm");
	Form x("28c", 10, 20);           // Default constructor
	Form y(x);        // Copy constructor (not assignment!)
	Form z = x;       // Also copy constructor! (confusing syntax)
	Form w("28b", 5, 50);
	w = x;             // Copy assignment operator
}


void basicTestsFormFail1()
{
	printSeparator("basicTestsFormFail1");
	try {
		Form x("28c", 10, 0);           // Default constructor
	} catch (std::exception& e) {
		std::cout << "Exception caught while creating form: " << e.what() << std::endl;
	}
}

void basicTestsFormFail2()
{
	printSeparator("basicTestsFormFail2");
	try {
		Form x("28c", 10, 151);           // Default constructor
	} catch (std::exception& e) {
		std::cout << "Exception caught while creating form: " << e.what() << std::endl;
	}
}

void basicFunctionalityFormFail()
{
	printSeparator("basicFunctionalityFormFail");
	Form x("28c", 10, 20);           // Default constructor
	Bureaucrat w("Peter", 50);
	std::cout << x << std::endl;
	std::cout << w << std::endl;
	try {
		w.signForm(x);
	} catch (std::exception& e) {
		std::cout << "Exception caught while signing form: " << e.what() << std::endl;
	}
}

void basicFunctionalityFormPass()
{
	printSeparator("basicFunctionalityFormPass");
	Form x("28c", 10, 20);           // Default constructor
	Bureaucrat w("Peter", 5);
	std::cout << x << std::endl;
	std::cout << w << std::endl;
	try {
		w.signForm(x);
	} catch (std::exception& e) {
		std::cout << "Exception caught while signing form: " << e.what() << std::endl;
	}

}

void printForm()
{
	printSeparator("printForm");
	Form x("John", 1, 100);           // Default constructor
	std::cout << x << std::endl;
}

int main()
{
	printSeparator("CPP05 - EX01");
	basicTestsBureaucrat();
	printBureaucrat();

	basicTestsBureaucratFail1();
	basicTestsBureaucratFail2();
	basicFunctionalityBureaucratPass();
	basicFunctionalityBureaucratFail();

	// -------------------------------------- ------------------- -------------------

	basicTestsForm();
	printForm();

	basicTestsFormFail1();
	basicTestsFormFail2();
	basicFunctionalityFormPass();
	basicFunctionalityFormFail();


	printSeparator("ALL TESTS COMPLETED!");

	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./BureaucratForm" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;

	return 0;
}
