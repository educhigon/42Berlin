/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:17:03 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/08 11:38:51 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include <iomanip>
#include "Fixed.hpp"

int main( void )
{
	// std::cout << std::fixed;

	std::cout << "=== CPP02 EX01 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

	std::cout << std::endl << "###### Test 0: Subject's exact test case" << std::endl;
	{
			Fixed a;
			Fixed const b( 10 );
			Fixed const c( 42.42f );
			Fixed const d( b );

			a = Fixed( 1234.4321f );

			std::cout << "a is " << a << std::endl;
			std::cout << "b is " << b << std::endl;
			std::cout << "c is " << c << std::endl;
			std::cout << "d is " << d << std::endl;

			std::cout << "a is " << a.toInt() << " as integer" << std::endl;
			std::cout << "b is " << b.toInt() << " as integer" << std::endl;
			std::cout << "c is " << c.toInt() << " as integer" << std::endl;
			std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}

	// Test 1: Default constructor
	std::cout << std::endl << "###### Test 1: Default constructor" << std::endl;
	{
		Fixed a;
		std::cout << "Fixed a; -> " << a << std::endl;
		std::cout << "a.toFloat() = " << a.toFloat() << std::endl;
		std::cout << "a.toInt() = " << a.toInt() << std::endl;
	}

	// Test 2: Integer constructor
	std::cout << std::endl << "###### Test 2: Integer constructors" << std::endl;
	{
		Fixed b(10);
		std::cout << "Fixed b(10); -> " << b << std::endl;
		std::cout << "b.toFloat() = " << b.toFloat() << std::endl;
		std::cout << "b.toInt() = " << b.toInt() << std::endl;

		Fixed c(-5);
		std::cout << "Fixed c(-5); -> " << c << std::endl;
		std::cout << "c.toFloat() = " << c.toFloat() << std::endl;
		std::cout << "c.toInt() = " << c.toInt() << std::endl;

		Fixed d(0);
		std::cout << "Fixed d(0); -> " << d << std::endl;
		std::cout << "d.toFloat() = " << d.toFloat() << std::endl;
		std::cout << "d.toInt() = " << d.toInt() << std::endl;
	}

	// Test 3: Float constructor
	std::cout << std::endl << "###### Test 3: Float constructors" << std::endl;
	{
		Fixed e(42.52f);
		std::cout << "Fixed e(42.52f); -> " << e << std::endl;
		std::cout << "e.toFloat() = " << e.toFloat() << std::endl;
		std::cout << "e.toInt() = " << e.toInt() << std::endl;

		Fixed f(-3.14f);
		std::cout << "Fixed f(-3.14f); -> " << f << std::endl;
		std::cout << "f.toFloat() = " << f.toFloat() << std::endl;
		std::cout << "f.toInt() = " << f.toInt() << std::endl;

		Fixed g(0.5f);
		std::cout << "Fixed g(0.5f); -> " << g << std::endl;
		std::cout << "g.toFloat() = " << g.toFloat() << std::endl;
		std::cout << "g.toInt() = " << g.toInt() << std::endl;
	}

	// Test 4: Copy constructor
	std::cout << std::endl << "###### Test 4: Copy constructor" << std::endl;
	{
		Fixed e(42.42f);
		Fixed h(e);
		std::cout << "Fixed h(e); where e = " << e << " -> h = " << h << std::endl;
		std::cout << "h.toFloat() = " << h.toFloat() << std::endl;
		std::cout << "h.toInt() = " << h.toInt() << std::endl;
	}

	// Test 5: Assignment operator
	std::cout << std::endl << "###### Test 5: Assignment operator" << std::endl;
	{
		Fixed f(-3.14f);
		Fixed i;
		std::cout << "Before assignment: i = " << i << std::endl;
		i = f;
		std::cout << "After i = f (where f = " << f << "): i = " << i << std::endl;
	}

	// Test 6: Stream insertion operator chaining
	std::cout << std::endl << "###### Test 6: Stream insertion operator chaining" << std::endl;
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );

		std::cout << "Chaining: a=" << a << ", b=" << b << ", c=" << c << std::endl;
	}

	// Test 7: Precision testing
	std::cout << std::endl << "###### Test 7: Precision testing with small decimals" << std::endl;
	{
		Fixed j(0.25f);
		Fixed k(0.75f);
		Fixed l(0.125f);
		Fixed m(0.0625f);

		std::cout << "0.25f -> " << j << " (toFloat: " << j.toFloat() << ")" << std::endl;
		std::cout << "0.75f -> " << k << " (toFloat: " << k.toFloat() << ")" << std::endl;
		std::cout << "0.125f -> " << l << " (toFloat: " << l.toFloat() << ")" << std::endl;
		std::cout << "0.0625f -> " << m << " (toFloat: " << m.toFloat() << ")" << std::endl;
	}

	// Test 8: Large numbers
	std::cout << std::endl << "###### Test 8: Large numbers" << std::endl;
	{
		Fixed n(1000);
		Fixed o(999.999f);
		Fixed p(-1000);

		std::cout << "1000 -> " << n << " (toInt: " << n.toInt() << ")" << std::endl;
		std::cout << "999.999f -> " << o << " (toFloat: " << o.toFloat() << ", toInt: " << o.toInt() << ")" << std::endl;
		std::cout << "-1000 -> " << p << " (toInt: " << p.toInt() << ")" << std::endl;
	}

	// Test 9: Rounding behavior
	std::cout << std::endl << "###### Test 9: Rounding behavior" << std::endl;
	{
		Fixed q(1.4f);
		Fixed r(1.5f);
		Fixed s(1.6f);
		Fixed t(2.4f);
		Fixed u(2.5f);
		Fixed v(2.6f);

		std::cout << "1.4f -> " << q << " (toInt: " << q.toInt() << ")" << std::endl;
		std::cout << "1.5f -> " << r << " (toInt: " << r.toInt() << ")" << std::endl;
		std::cout << "1.6f -> " << s << " (toInt: " << s.toInt() << ")" << std::endl;
		std::cout << "2.4f -> " << t << " (toInt: " << t.toInt() << ")" << std::endl;
		std::cout << "2.5f -> " << u << " (toInt: " << u.toInt() << ")" << std::endl;
		std::cout << "2.6f -> " << v << " (toInt: " << v.toInt() << ")" << std::endl;
	}

	// Test 11: Edge cases
	std::cout << std::endl << "###### Test 11: Edge cases" << std::endl;
	{
		Fixed w(0.0f);
		Fixed x(-0.0f);
		Fixed y(1.0f);
		Fixed z(-1.0f);

		std::cout << "0.0f -> " << w << std::endl;
		std::cout << "-0.0f -> " << x << std::endl;
		std::cout << "1.0f -> " << y << std::endl;
		std::cout << "-1.0f -> " << z << std::endl;
	}

	// Test 12: Conversion accuracy test
	std::cout << std::endl << "###### Test 12: Conversion accuracy test" << std::endl;
	{
		float original = 123.456f;
		Fixed converted(original);
		float backToFloat = converted.toFloat();

		std::cout << "Original float: " << original << std::endl;
		std::cout << "Fixed representation: " << converted << std::endl;
		std::cout << "Back to float: " << backToFloat << std::endl;
		std::cout << "Difference: " << (original - backToFloat) << std::endl;
	}



}
