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

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

/*
  class Animal { public: virtual ~Animal() {} };
  class Dog : public Animal { public: void bark() {} };
  class Cat : public Animal {};

  Animal* a = new Dog();

  Dog* d = dynamic_cast<Dog*>(a);  // succeeds, d != nullptr
  Cat* c = dynamic_cast<Cat*>(a);  // fails, c == nullptr (it's really a Dog)
*/

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "Identified A" << std::endl;
	else
	{
		B* b = dynamic_cast<B*>(p);
		if (b)
			std::cout << "Identified B" << std::endl;
		else
		{
			C* c = dynamic_cast<C*>(p);
			if (c)
				std::cout << "Identified C" << std::endl;
			else
				std::cout << "Unknown type" << std::endl;
		}
	}
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Identified A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B b = dynamic_cast<B&>(p);
			std::cout << "Identified B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C c = dynamic_cast<C&>(p);
				std::cout << "Identified C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Unknown type" << '\n';
			}
		}
	}
}


Base * generate(void) {
	int random = rand() % 3;

	switch (random)
	{
	case 0:
		std::cout << "Generated A" << std::endl;
		return new A();
	case 1:
		std::cout << "Generated B" << std::endl;
		return new B();
	case 2:
		std::cout << "Generated C" << std::endl;
		return new C();
	default:
		return NULL;
	}
}

void basicTestsBase()
{
	printSeparator("basicTestsBase");

	Base* base = generate();
	std::cout << "-- Print pointer" << std::endl;
	identify(base);
	std::cout << "-- Print reference" << std::endl;
	identify(*base);
	delete base;
	return;
}

void	basicTestsBaseABC()
{
	printSeparator("basicTestsBaseABC");
  Base* a = new A();
  Base* b = new B();
  Base* c = new C();
  Base* base = new Base();
  identify(a);
	identify(*a);
	identify(b);
	identify(*b);
	identify(c);
	identify(*c);
	identify(base);
	identify(*base);
	delete a;
	delete b;
	delete c;
	delete base;
}


int main()
{
	srand(time(0));

	printSeparator("CPP06 - EX02");
	basicTestsBaseABC();

	basicTestsBase();
	basicTestsBase();
	basicTestsBase();
	basicTestsBase();
	basicTestsBase();

	printSeparator("ALL TESTS COMPLETED!");
	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./Base" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}
