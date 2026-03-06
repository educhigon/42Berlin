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

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <sstream>
#include <cstdlib>

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

// ------------------------

void basicTestsAFormWithPrint()
{
	printSeparator("basicTestsAFormWithPrint");
	AForm* x = new PresidentialPardonForm("28A");
	std::cout << "----- " << *x << std::endl;
	AForm* y = new RobotomyRequestForm("28B");
	std::cout << "----- " << *y << std::endl;
	AForm* z = new ShrubberyCreationForm("28C");
	std::cout << "----- " << *z << std::endl;
	std::cout << std::endl;
	delete x;
	delete y;
	delete z;
	std::cout << std::endl;
}

void basicTestsPresidentialPardonForm()
{
	printSeparator("basicTestsPresidentialPardonForm");
	PresidentialPardonForm x("28A");           // Default constructor
	PresidentialPardonForm y(x);        // Copy constructor (not assignment!)
	PresidentialPardonForm z = x;       // Also copy constructor! (confusing syntax)
	PresidentialPardonForm w("28D");
	w = x;             // Copy assignment operator
	std::cout << z << std::endl;
	std::cout << std::endl;
}
void basicTestsRobotomyRequestForm()
{
	printSeparator("basicTestsRobotomyRequestForm");
	RobotomyRequestForm x("28B");           // Default constructor
	RobotomyRequestForm y(x);        // Copy constructor (not assignment!)
	RobotomyRequestForm z = x;       // Also copy constructor! (confusing syntax)
	RobotomyRequestForm w("28D");
	w = x;             // Copy assignment operator
	std::cout << z << std::endl;
	std::cout << std::endl;
}
void basicTestsShrubberyCreationForm()
{
	printSeparator("basicTestsShrubberyCreationForm");
	ShrubberyCreationForm x("28C");           // Default constructor
	ShrubberyCreationForm y(x);        // Copy constructor (not assignment!)
	ShrubberyCreationForm z = x;       // Also copy constructor! (confusing syntax)
	ShrubberyCreationForm w("28D");
	w = x;             // Copy assignment operator
	std::cout << z << std::endl;
	std::cout << std::endl;
}

	// -------------------------------------- ------------------- -------------------


void basicTestsIntern()
{
	printSeparator("basicTestsIntern");
	Intern x;           // Default constructor
	Intern y(x);        // Copy constructor (not assignment!)
	Intern z = x;       // Also copy constructor! (confusing syntax)
	Intern w;
	w = x;             // Copy assignment operator
	std::cout << std::endl;
}

	// -------------------------------------- ------------------- -------------------

void basicFunctionalityForm()
{
	printSeparator("basicFunctionalityForm");

	std::cout << "\n--- Creating Form with different grades..." << std::endl;
	AForm* x = new ShrubberyCreationForm("28A");
	std::cout << *x << std::endl;
	AForm* y = new RobotomyRequestForm("28B");
	std::cout << *y << std::endl;
	AForm* z = new PresidentialPardonForm("28C");
	std::cout << *z << std::endl;

	std::cout << "\n--- Creating bureaucrats with different grades..." << std::endl;
	Bureaucrat a("A", 150);
	std::cout << a << std::endl;
	Bureaucrat b("B", 140);
	std::cout << b << std::endl;
	Bureaucrat c("C", 80);
	std::cout << c << std::endl;
	Bureaucrat d("D", 50);
	std::cout << d << std::endl;
	Bureaucrat e("E", 30);
	std::cout << e << std::endl;
	Bureaucrat f("F", 10);
	std::cout << f << std::endl;
	Bureaucrat g("G", 1);
	std::cout << g << std::endl;

	std::cout << "\n--- All bureaucrats trying to sign and execute ShrubberyCreationForm" << std::endl;
	a.signForm(*x);
	a.executeForm(*x);
	b.signForm(*x);
	b.executeForm(*x);
	c.signForm(*x);
	c.executeForm(*x);
	d.signForm(*x);
	d.executeForm(*x);
	e.signForm(*x);
	e.executeForm(*x);
	f.signForm(*x);
	f.executeForm(*x);
	g.signForm(*x);
	g.executeForm(*x);

	std::cout << "\n--- All bureaucrats trying to sign and execute RobotomyRequestForm" << std::endl;
	a.signForm(*y);
	a.executeForm(*y);
	b.signForm(*y);
	b.executeForm(*y);
	c.signForm(*y);
	c.executeForm(*y);
	d.signForm(*y);
	d.executeForm(*y);
	e.signForm(*y);
	e.executeForm(*y);
	f.signForm(*y);
	f.executeForm(*y);
	g.signForm(*y);
	g.executeForm(*y);

	std::cout << "\n--- All bureaucrats trying to sign and execute PresidentialPardonForm" << std::endl;
	a.signForm(*z);
	a.executeForm(*z);
	b.signForm(*z);
	b.executeForm(*z);
	c.signForm(*z);
	c.executeForm(*z);
	d.signForm(*z);
	d.executeForm(*z);
	e.signForm(*z);
	e.executeForm(*z);
	f.signForm(*z);
	f.executeForm(*z);
	g.signForm(*z);
	g.executeForm(*z);


	printSeparator("InternWorking");
	Intern xx;           // Default constructor
	AForm* f1 = xx.makeForm("shrubbery creation", "INTERN_WORK_A");
	if (f1)
	{
		std::cout << *f1 << std::endl;
		std::cout << "\n--- All bureaucrats trying to sign and execute INTERN_WORK_A" << std::endl;
		a.signForm(*f1);
		a.executeForm(*f1);
		b.signForm(*f1);
		b.executeForm(*f1);
		c.signForm(*f1);
		c.executeForm(*f1);
		d.signForm(*f1);
		d.executeForm(*f1);
		e.signForm(*f1);
		e.executeForm(*f1);
		f.signForm(*f1);
		f.executeForm(*f1);
		g.signForm(*f1);
		g.executeForm(*f1);
	}


	AForm* f2 = xx.makeForm("i dunno", "INTERN_WORK_B");
	if (f2)
	{
		std::cout << *f2 << std::endl;
		std::cout << "\n--- All bureaucrats trying to sign and execute INTERN_WORK_B" << std::endl;
		a.signForm(*f2);
		a.executeForm(*f2);
		b.signForm(*f2);
		b.executeForm(*f2);
		c.signForm(*f2);
		c.executeForm(*f2);
		d.signForm(*f2);
		d.executeForm(*f2);
		e.signForm(*f2);
		e.executeForm(*f2);
		f.signForm(*f2);
		f.executeForm(*f2);
		g.signForm(*f2);
		g.executeForm(*f2);
	}

	AForm* f3 = xx.makeForm("presidential pardon", "INTERN_WORK_C");
	if (f3)
	{
		std::cout << *f3 << std::endl;
		std::cout << "\n--- All bureaucrats trying to sign and execute INTERN_WORK_C" << std::endl;
		a.signForm(*f3);
		a.executeForm(*f3);
		b.signForm(*f3);
		b.executeForm(*f3);
		c.signForm(*f3);
		c.executeForm(*f3);
		d.signForm(*f3);
		d.executeForm(*f3);
		e.signForm(*f3);
		e.executeForm(*f3);
		f.signForm(*f3);
		f.executeForm(*f3);
		g.signForm(*f3);
		g.executeForm(*f3);
	}

	delete x;
	delete y;
	delete z;
	delete f1;
	delete f3;
}


int main()
{
	srand(time(0));

	printSeparator("CPP05 - EX03");

	basicTestsBureaucrat();
	printBureaucrat();

	basicTestsBureaucratFail1();
	basicTestsBureaucratFail2();
	basicFunctionalityBureaucratPass();
	basicFunctionalityBureaucratFail();

	// -------------------------------------- ------------------- -------------------

	basicTestsAFormWithPrint();
	basicTestsPresidentialPardonForm();
	basicTestsRobotomyRequestForm();
	basicTestsShrubberyCreationForm();

	// -------------------------------------- ------------------- -------------------

	basicTestsIntern();

	// -------------------------------------- ------------------- -------------------

	basicFunctionalityForm();

	printSeparator("ALL TESTS COMPLETED!");

	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./Bureaucrats" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;

	return 0;
}
