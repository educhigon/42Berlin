/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:17:03 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 14:23:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	std::cout << "=== CPP02 EX02 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

	std::cout << "Test 0: Subject's exact test case" << std::endl;
	{
			Fixed a;
			Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

			std::cout << a << std::endl;
			std::cout << ++a << std::endl;
			std::cout << a << std::endl;
			std::cout << a++ << std::endl;
			std::cout << a << std::endl;

			std::cout << b << std::endl;

			std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << std::endl;

	// Test 1: Comparison operators
	std::cout << "##### Test 1: Comparison operators" << std::endl;
	{
		Fixed a(5.5f);
		Fixed b(10.25f);
		Fixed c(5.5f);

		std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << "a > b: " << (a > b) << " (expected: 0)" << std::endl;
		std::cout << "b > a: " << (b > a) << " (expected: 1)" << std::endl;
		std::cout << "a >= c: " << (a >= c) << " (expected: 1)" << std::endl;
		std::cout << "a >= b: " << (a >= b) << " (expected: 0)" << std::endl;
		std::cout << "a < b: " << (a < b) << " (expected: 1)" << std::endl;
		std::cout << "b < a: " << (b < a) << " (expected: 0)" << std::endl;
		std::cout << "a <= c: " << (a <= c) << " (expected: 1)" << std::endl;
		std::cout << "b <= a: " << (b <= a) << " (expected: 0)" << std::endl;
		std::cout << "a == c: " << (a == c) << " (expected: 1)" << std::endl;
		std::cout << "a == b: " << (a == b) << " (expected: 0)" << std::endl;
		std::cout << "a != b: " << (a != b) << " (expected: 1)" << std::endl;
		std::cout << "a != c: " << (a != c) << " (expected: 0)" << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Arithmetic operators
	std::cout << "##### Test 2: Arithmetic operators" << std::endl;
	{
		Fixed d(10.0f);
		Fixed e(3.0f);

		std::cout << "d = " << d << ", e = " << e << std::endl;
		std::cout << "d + e = " << (d + e) << " (expected: 13)" << std::endl;
		std::cout << "d - e = " << (d - e) << " (expected: 7)" << std::endl;
		std::cout << "d * e = " << (d * e) << " (expected: 30)" << std::endl;
		std::cout << "d / e = " << (d / e) << " (expected: ~3.33)" << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Increment and decrement operators
	std::cout << "##### Test 3: Increment and decrement operators" << std::endl;
	{
		Fixed f(5.5f);

		std::cout << "Initial f = " << f << std::endl;
		std::cout << "Pre-increment ++f = " << (++f) << std::endl;
		std::cout << "After pre-increment f = " << f << std::endl;
		std::cout << "Post-increment f++ = " << (f++) << std::endl;
		std::cout << "After post-increment f = " << f << std::endl;

		std::cout << "Pre-decrement --f = " << (--f) << std::endl;
		std::cout << "After pre-decrement f = " << f << std::endl;
		std::cout << "Post-decrement f-- = " << (f--) << std::endl;
		std::cout << "After post-decrement f = " << f << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Static min and max functions
	std::cout << "##### Test 4: Static min and max functions" << std::endl;
	{
		Fixed g(42.42f);
		Fixed h(10.5f);

		std::cout << "g = " << g << ", h = " << h << std::endl;
		std::cout << "Fixed::min(g, h) = " << Fixed::min(g, h) << std::endl;
		std::cout << "Fixed::max(g, h) = " << Fixed::max(g, h) << std::endl;

		const Fixed i(15.75f);
		const Fixed j(20.25f);
		std::cout << "const i = " << i << ", const j = " << j << std::endl;
		std::cout << "Fixed::min(i, j) = " << Fixed::min(i, j) << std::endl;
		std::cout << "Fixed::max(i, j) = " << Fixed::max(i, j) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// Test 5: Complex arithmetic expressions
	std::cout << "##### Test 5: Complex arithmetic expressions" << std::endl;
	{
		Fixed k(8.0f);
		Fixed l(2.0f);
		Fixed m(3.0f);

		std::cout << "k = " << k << ", l = " << l << ", m = " << m << std::endl;
		Fixed result1 = k + l * m;
		std::cout << "k + l * m = " << result1 << " (expected: 14)" << std::endl;

		Fixed result2 = (k + l) * m;
		std::cout << "(k + l) * m = " << result2 << " (expected: 30)" << std::endl;

		Fixed result3 = k / l + m;
		std::cout << "k / l + m = " << result3 << " (expected: 7)" << std::endl;
	}
	std::cout << std::endl;

	// Test 6: Edge cases with zero and negative numbers
	std::cout << "##### Test 6: Edge cases with zero and negative numbers" << std::endl;
	{
		Fixed zero(0.0f);
		Fixed positive(5.0f);
		Fixed negative(-3.0f);

		std::cout << "zero = " << zero << ", positive = " << positive << ", negative = " << negative << std::endl;
		std::cout << "positive + negative = " << (positive + negative) << std::endl;
		std::cout << "positive - negative = " << (positive - negative) << std::endl;
		std::cout << "positive * negative = " << (positive * negative) << std::endl;
		std::cout << "positive > zero = " << (positive > zero) << std::endl;
		std::cout << "negative < zero = " << (negative < zero) << std::endl;
		std::cout << "Fixed::min(positive, negative) = " << Fixed::min(positive, negative) << std::endl;
		std::cout << "Fixed::max(positive, negative) = " << Fixed::max(positive, negative) << std::endl;
	}
	std::cout << std::endl;

	// Test 7: Precision tests with small numbers
	std::cout << "##### Test 7: Precision tests with small numbers" << std::endl;
	{
		Fixed small1(0.25f);
		Fixed small2(0.5f);

		std::cout << "small1 = " << small1 << ", small2 = " << small2 << std::endl;
		std::cout << "small1 + small2 = " << (small1 + small2) << std::endl;
		std::cout << "small2 - small1 = " << (small2 - small1) << std::endl;
		std::cout << "small1 * small2 = " << (small1 * small2) << std::endl;
		std::cout << "small2 / small1 = " << (small2 / small1) << std::endl;
	}
	std::cout << std::endl;

	// Test 8: Chain operations
	std::cout << "##### Test 8: Chain operations" << std::endl;
	{
		Fixed chain(1.0f);
		std::cout << "Starting with chain = " << chain << std::endl;
		chain = chain + Fixed(2.0f) - Fixed(1.5f) + Fixed(0.5f);
		std::cout << "After chain = chain + 2 - 1.5 + 0.5: " << chain << std::endl;

		Fixed chain2(10.0f);
		std::cout << "chain2 = " << chain2 << std::endl;
		++chain2;
		chain2--;
		++chain2;
		std::cout << "After ++chain2; chain2--; ++chain2;: " << chain2 << std::endl;
	}
	std::cout << std::endl;

	// Test 9: Comparison edge cases
	std::cout << "##### Test 9: Comparison edge cases" << std::endl;
	{
		Fixed equal1(7.0f);
		Fixed equal2(7.0f);
		Fixed slightly_bigger(7.00390625f); // 7 + 1/256 (smallest increment with 8 fractional bits)

		std::cout << "equal1 = " << equal1 << ", equal2 = " << equal2 << std::endl;
		std::cout << "slightly_bigger = " << slightly_bigger << std::endl;
		std::cout << "equal1 == equal2: " << (equal1 == equal2) << std::endl;
		std::cout << "equal1 == slightly_bigger: " << (equal1 == slightly_bigger) << std::endl;
		std::cout << "equal1 < slightly_bigger: " << (equal1 < slightly_bigger) << std::endl;
	}
	std::cout << std::endl;

	// Test 10: Multiple increment/decrement
	std::cout << "##### Test 10: Multiple increment/decrement operations" << std::endl;
	{
		Fixed multi(0.0f);
		std::cout << "Starting multi = " << multi << std::endl;

		for (int i = 0; i < 5; i++) {
				std::cout << "Iteration " << i << ": ++multi = " << (++multi) << std::endl;
		}

		for (int i = 0; i < 3; i++) {
				std::cout << "Iteration " << i << ": multi-- = " << (multi--) << std::endl;
		}
		std::cout << "Final multi = " << multi << std::endl;
	}
	std::cout << std::endl;

	// Test 11: Division by small numbers
	std::cout << "##### Test 11: Division edge cases" << std::endl;
	{
		Fixed big(100.0f);
		Fixed tiny(0.25f);
		Fixed one(1.0f);

		std::cout << "big = " << big << ", tiny = " << tiny << ", one = " << one << std::endl;
		std::cout << "big / one = " << (big / one) << std::endl;
		std::cout << "big / tiny = " << (big / tiny) << std::endl;
		std::cout << "one / tiny = " << (one / tiny) << std::endl;
	}
	std::cout << std::endl;
}
