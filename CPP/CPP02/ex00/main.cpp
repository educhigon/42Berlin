/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:17:03 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/08 16:02:18 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	std::cout << "=== CPP02 EX00 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

	std::cout << std::endl << "###### Test 0: Subject's exact test case" << std::endl;
	{
			Fixed a;
			Fixed b( a );
			Fixed c;
			c = b;
			std::cout << a.getRawBits() << std::endl;
			std::cout << b.getRawBits() << std::endl;
			std::cout << c.getRawBits() << std::endl;
	}
	std::cout << std::endl;

	// Test 2: setRawBits and getRawBits
	std::cout << std::endl << "###### Test 1: setRawBits and getRawBits functionality" << std::endl;
	{
		Fixed c;
		c.setRawBits(42);
		std::cout << "-- After c.setRawBits(42): " << c.getRawBits() << std::endl;

		c.setRawBits(-10);
		std::cout << "-- After c.setRawBits(-10): " << c.getRawBits() << std::endl;

		c.setRawBits(0);
		std::cout << "-- After c.setRawBits(0): " << c.getRawBits() << std::endl;
	}

	std::cout << std::endl << "###### Test 2: Copy constructor with non-zero value" << std::endl;
	{
		Fixed e;
		e.setRawBits(100);
		std::cout << "-- Created Fixed e, set to 100" << std::endl;

		Fixed f(e);
		std::cout << "-- Created Fixed f(e) using copy constructor" << std::endl;
		std::cout << "-- e.getRawBits() = " << e.getRawBits() << std::endl;
		std::cout << "-- f.getRawBits() = " << f.getRawBits() << std::endl;
	}

	std::cout << std::endl << "###### Test 3: Assignment operator with different values" << std::endl;
	{
		Fixed g, h;
		g.setRawBits(200);
		h.setRawBits(300);

		std::cout << "-- Before assignment:" << std::endl;
		std::cout << "-- g.getRawBits() = " << g.getRawBits() << std::endl;
		std::cout << "-- h.getRawBits() = " << h.getRawBits() << std::endl;

		h = g;
		std::cout << "-- After h = g:" << std::endl;
		std::cout << "-- g.getRawBits() = " << g.getRawBits() << std::endl;
		std::cout << "-- h.getRawBits() = " << h.getRawBits() << std::endl;
	}

	std::cout << std::endl << "###### Test 4: Self-assignment" << std::endl;
	{
		Fixed i;
		i.setRawBits(500);
		std::cout << "-- Created Fixed i, set to 500" << std::endl;
		std::cout << "-- Before self-assignment i = i: " << i.getRawBits() << std::endl;

		// i = i;
		std::cout << "-- After self-assignment i = i: " << i.getRawBits() << std::endl;
	}

	std::cout << std::endl << "###### Test 5: Chain assignment" << std::endl;
	{
		Fixed j, k, l;
		j.setRawBits(777);

		std::cout << "-- Before chain assignment (l = k = j):" << std::endl;
		std::cout << "-- j.getRawBits() = " << j.getRawBits() << std::endl;
		std::cout << "-- k.getRawBits() = " << k.getRawBits() << std::endl;
		std::cout << "-- l.getRawBits() = " << l.getRawBits() << std::endl;

		l = k = j;
		std::cout << "-- After chain assignment (l = k = j):" << std::endl;
		std::cout << "-- j.getRawBits() = " << j.getRawBits() << std::endl;
		std::cout << "-- k.getRawBits() = " << k.getRawBits() << std::endl;
		std::cout << "-- l.getRawBits() = " << l.getRawBits() << std::endl;
	}

	std::cout << std::endl << "###### Test 6: Large and extreme values" << std::endl;
	{
		Fixed m;

		m.setRawBits(2147483647); // INT_MAX
		std::cout << "-- Set to INT_MAX (2147483647): " << m.getRawBits() << std::endl;

		m.setRawBits(-2147483648); // INT_MIN
		std::cout << "-- Set to INT_MIN (-2147483648): " << m.getRawBits() << std::endl;
	}

	std::cout << std::endl << "###### Test 7: Multiple objects and scope test" << std::endl;
	{
			std::cout << "-- Entering inner scope..." << std::endl;
			Fixed inner1, inner2;
			inner1.setRawBits(1000);
			inner2 = inner1;

			std::cout << "-- inner1.getRawBits() = " << inner1.getRawBits() << std::endl;
			std::cout << "-- inner2.getRawBits() = " << inner2.getRawBits() << std::endl;

			Fixed inner3(inner2);
			std::cout << "-- inner3.getRawBits() = " << inner3.getRawBits() << std::endl;
			std::cout << "-- Exiting inner scope..." << std::endl;
	}
	std::cout << "-- Back in outer scope" << std::endl << std::endl;

	return 0;
}
