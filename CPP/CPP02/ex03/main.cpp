/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:17:03 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 19:57:38 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void )
{
	// Point const a(1,2);
	// Point const b(2,3);
	// Point const c(4,1);
	// Point const p1(2,2);
	// Point const p2(4,4);

	// if(bsp(a, b, c, p1))
	// 	std::cout << "Inside!" << std::endl;
	// else
	// 	std::cout << "Ouside =(" << std::endl;

	// if(bsp(a, b, c, p2))
	// 	std::cout << "Inside!" << std::endl;
	// else
	// 	std::cout << "Ouside =(" << std::endl;



	std::cout << "=== CPP02 EX03 COMPREHENSIVE TESTS ===" << std::endl << std::endl;

	// Test 1: Basic Point construction and access
	std::cout << "###### Test 1: Basic Point construction and access" << std::endl;
	{
		Point p1;
		Point p2(Fixed(3.0f), Fixed(4.0f));
		Point p3(Fixed(-1.0f), Fixed(-2.0f));

		std::cout << "Default point p1: (" << p1.get_x() << ", " << p1.get_y() << ")" << std::endl;
		std::cout << "Point p2(3, 4): (" << p2.get_x() << ", " << p2.get_y() << ")" << std::endl;
		std::cout << "Point p3(-1, -2): (" << p3.get_x() << ", " << p3.get_y() << ")" << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Point copy constructor
	std::cout << "###### Test 2: Point copy constructor" << std::endl;
	{
		Point p2(Fixed(3.0f), Fixed(4.0f));
		Point p4(p2);
		std::cout << "Original p2: (" << p2.get_x() << ", " << p2.get_y() << ")" << std::endl;
		std::cout << "Copied p4(p2): (" << p4.get_x() << ", " << p4.get_y() << ")" << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Basic triangle - point inside
	std::cout << "###### Test 3: Basic triangle - point inside" << std::endl;
	{
		Point a(Fixed(0.0f), Fixed(0.0f));
		Point b(Fixed(10.0f), Fixed(0.0f));
		Point c(Fixed(5.0f), Fixed(10.0f));
		Point inside(Fixed(5.0f), Fixed(3.0f));

		std::cout << "Triangle vertices:" << std::endl;
		std::cout << "A: (" << a.get_x() << ", " << a.get_y() << ")" << std::endl;
		std::cout << "B: (" << b.get_x() << ", " << b.get_y() << ")" << std::endl;
		std::cout << "C: (" << c.get_x() << ", " << c.get_y() << ")" << std::endl;
		std::cout << "Test point: (" << inside.get_x() << ", " << inside.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, inside) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Basic triangle - point outside
	std::cout << "###### Test 4: Basic triangle - point outside" << std::endl;
	{
		Point a(Fixed(0.0f), Fixed(0.0f));
		Point b(Fixed(10.0f), Fixed(0.0f));
		Point c(Fixed(5.0f), Fixed(10.0f));

		Point outside(Fixed(15.0f), Fixed(3.0f));
		std::cout << "Test point: (" << outside.get_x() << ", " << outside.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, outside) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 5: Point on triangle edge (should be outside according to BSP definition)
	std::cout << "###### Test 5: Point on triangle edge" << std::endl;
	{
		Point a(Fixed(0.0f), Fixed(0.0f));
		Point b(Fixed(10.0f), Fixed(0.0f));
		Point c(Fixed(5.0f), Fixed(10.0f));

		Point onEdge(Fixed(5.0f), Fixed(0.0f)); // On edge AB
		std::cout << "Test point on edge AB: (" << onEdge.get_x() << ", " << onEdge.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, onEdge) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 6: Point at triangle vertex (should be outside)
	std::cout << "###### Test 6: Point at triangle vertex" << std::endl;
	{
		Point a(Fixed(0.0f), Fixed(0.0f));
		Point b(Fixed(10.0f), Fixed(0.0f));
		Point c(Fixed(5.0f), Fixed(10.0f));

		std::cout << "Test point at vertex A: (" << a.get_x() << ", " << a.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, a) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 7: Different triangle orientations - clockwise
	std::cout << "###### Test 7: Clockwise triangle orientation" << std::endl;
	{
		Point a_cw(Fixed(0.0f), Fixed(0.0f));
		Point b_cw(Fixed(5.0f), Fixed(10.0f));
		Point c_cw(Fixed(10.0f), Fixed(0.0f));
		Point test_cw(Fixed(5.0f), Fixed(3.0f));

		std::cout << "Clockwise triangle vertices:" << std::endl;
		std::cout << "A: (" << a_cw.get_x() << ", " << a_cw.get_y() << ")" << std::endl;
		std::cout << "B: (" << b_cw.get_x() << ", " << b_cw.get_y() << ")" << std::endl;
		std::cout << "C: (" << c_cw.get_x() << ", " << c_cw.get_y() << ")" << std::endl;
		std::cout << "Test point: (" << test_cw.get_x() << ", " << test_cw.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a_cw, b_cw, c_cw, test_cw) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 8: Triangle with negative coordinates
	std::cout << "###### Test 8: Triangle with negative coordinates" << std::endl;
	{
		Point a_neg(Fixed(-5.0f), Fixed(-5.0f));
		Point b_neg(Fixed(0.0f), Fixed(-5.0f));
		Point c_neg(Fixed(-2.5f), Fixed(0.0f));
		Point test_neg(Fixed(-2.5f), Fixed(-3.0f));

		std::cout << "Triangle with negative coordinates:" << std::endl;
		std::cout << "A: (" << a_neg.get_x() << ", " << a_neg.get_y() << ")" << std::endl;
		std::cout << "B: (" << b_neg.get_x() << ", " << b_neg.get_y() << ")" << std::endl;
		std::cout << "C: (" << c_neg.get_x() << ", " << c_neg.get_y() << ")" << std::endl;
		std::cout << "Test point: (" << test_neg.get_x() << ", " << test_neg.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a_neg, b_neg, c_neg, test_neg) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 9: Very small triangle
	std::cout << "###### Test 9: Very small triangle" << std::endl;
	{
		Point a_small(Fixed(0.0f), Fixed(0.0f));
		Point b_small(Fixed(1.0f), Fixed(0.0f));
		Point c_small(Fixed(0.5f), Fixed(1.0f));
		Point test_small(Fixed(0.5f), Fixed(0.25f));

		std::cout << "Small triangle:" << std::endl;
		std::cout << "A: (" << a_small.get_x() << ", " << a_small.get_y() << ")" << std::endl;
		std::cout << "B: (" << b_small.get_x() << ", " << b_small.get_y() << ")" << std::endl;
		std::cout << "C: (" << c_small.get_x() << ", " << c_small.get_y() << ")" << std::endl;
		std::cout << "Test point: (" << test_small.get_x() << ", " << test_small.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a_small, b_small, c_small, test_small) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 10: Right triangle
	std::cout << "###### Test 10: Right triangle" << std::endl;
	{
		Point a_right(Fixed(0.0f), Fixed(0.0f));
		Point b_right(Fixed(3.0f), Fixed(0.0f));
		Point c_right(Fixed(0.0f), Fixed(4.0f));
		Point test_right(Fixed(1.0f), Fixed(1.0f));

		std::cout << "Right triangle:" << std::endl;
		std::cout << "A: (" << a_right.get_x() << ", " << a_right.get_y() << ")" << std::endl;
		std::cout << "B: (" << b_right.get_x() << ", " << b_right.get_y() << ")" << std::endl;
		std::cout << "C: (" << c_right.get_x() << ", " << c_right.get_y() << ")" << std::endl;
		std::cout << "Test point: (" << test_right.get_x() << ", " << test_right.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a_right, b_right, c_right, test_right) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 11: Multiple points around the same triangle
	std::cout << "###### Test 11: Multiple points around the same triangle" << std::endl;
	{
		std::cout << "Using triangle A(0,0), B(6,0), C(3,6)" << std::endl;
		Point triangle_a(Fixed(0.0f), Fixed(0.0f));
		Point triangle_b(Fixed(6.0f), Fixed(0.0f));
		Point triangle_c(Fixed(3.0f), Fixed(6.0f));

		Point test_points[] = {
				Point(Fixed(3.0f), Fixed(2.0f)),    // Inside
				Point(Fixed(1.0f), Fixed(1.0f)),    // Inside
				Point(Fixed(5.0f), Fixed(1.0f)),    // Inside
				Point(Fixed(3.0f), Fixed(5.0f)),    // Inside
				Point(Fixed(-1.0f), Fixed(1.0f)),   // Outside left
				Point(Fixed(7.0f), Fixed(1.0f)),    // Outside right
				Point(Fixed(3.0f), Fixed(-1.0f)),   // Outside below
				Point(Fixed(3.0f), Fixed(7.0f)),    // Outside above
				Point(Fixed(0.0f), Fixed(3.0f)),    // Outside left side
				Point(Fixed(6.0f), Fixed(3.0f))     // Outside right side
		};

		const char* descriptions[] = {
				"Center", "Bottom-left inside", "Bottom-right inside", "Top inside",
				"Outside left", "Outside right", "Outside below", "Outside above",
				"Outside left side", "Outside right side"
		};

		const char* expected[] = {
				"\033[32m INSIDE", "\033[32m INSIDE", "\033[32m INSIDE", "\033[32m INSIDE",
				"\033[31m OUTSIDE", "\033[31m OUTSIDE", "\033[31m OUTSIDE", "\033[31m OUTSIDE",
				"\033[31m OUTSIDE", "\033[31m OUTSIDE"
		};

		for (int i = 0; i < 10; i++) {
				std::cout << descriptions[i] << " (" << test_points[i].get_x() << ", "
									<< test_points[i].get_y() << "): "
									<< (bsp(triangle_a, triangle_b, triangle_c, test_points[i]) ? "\033[32m INSIDE" : "\033[31m OUTSIDE")
									<< " <==> "<< expected[i] << "\033[0m" << ")" << std::endl;
		}
	}
	std::cout << std::endl;

	// Test 12: Degenerate cases - collinear points (\033[31m n<< "\033[0m" ot a valid triangle)
	std::cout << "###### Test 12: Degenerate case - collinear points" << std::endl;
	{
		Point collinear_a(Fixed(0.0f), Fixed(0.0f));
		Point collinear_b(Fixed(2.0f), Fixed(0.0f));
		Point collinear_c(Fixed(4.0f), Fixed(0.0f));
		Point test_collinear(Fixed(1.0f), Fixed(0.0f));

		std::cout << "Collinear 'triangle':" << std::endl;
		std::cout << "A: (" << collinear_a.get_x() << ", " << collinear_a.get_y() << ")" << std::endl;
		std::cout << "B: (" << collinear_b.get_x() << ", " << collinear_b.get_y() << ")" << std::endl;
		std::cout << "C: (" << collinear_c.get_x() << ", " << collinear_c.get_y() << ")" << std::endl;
		std::cout << "Test point: (" << test_collinear.get_x() << ", " << test_collinear.get_y() << ")" << std::endl;
		std::cout << "Is point 'inside' degenerate triangle? " << (bsp(collinear_a, collinear_b, collinear_c, test_collinear) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 13: Points with decimal coordinates
	std::cout << "###### Test 13: Points with decimal coordinates" << std::endl;
	{
		Point a_decimal(Fixed(1.5f), Fixed(2.25f));
		Point b_decimal(Fixed(4.75f), Fixed(1.25f));
		Point c_decimal(Fixed(3.25f), Fixed(5.5f));
		Point test_decimal(Fixed(3.0f), Fixed(3.0f));

		std::cout << "Triangle with decimal coordinates:" << std::endl;
		std::cout << "A: (" << a_decimal.get_x() << ", " << a_decimal.get_y() << ")" << std::endl;
		std::cout << "B: (" << b_decimal.get_x() << ", " << b_decimal.get_y() << ")" << std::endl;
		std::cout << "C: (" << c_decimal.get_x() << ", " << c_decimal.get_y() << ")" << std::endl;
		std::cout << "Test point: (" << test_decimal.get_x() << ", " << test_decimal.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a_decimal, b_decimal, c_decimal, test_decimal) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 14: Edge case - Vertical line triangles
	std::cout << "###### Test 14: Edge case - Vertical line triangles" <<	std::endl;
	{
		// Triangle with one vertical edge
		Point a(Fixed(0.0f), Fixed(0.0f));
		Point b(Fixed(0.0f), Fixed(4.0f));  // Vertical edge AB
		Point c(Fixed(3.0f), Fixed(2.0f));
		Point test1(Fixed(1.0f), Fixed(2.0f));  // Should be inside
		Point test2(Fixed(-1.0f), Fixed(2.0f)); // Should be outside

		std::cout << "Vertical edge triangle: A(0,0), B(0,4), C(3,2)" <<	std::endl;
		std::cout << "Test point 1: (" << test1.get_x() << ", " <<	test1.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test1) ?	"\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
		std::cout << "Test point 2: (" << test2.get_x() << ", " <<	test2.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test2) ?	"\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 15: Edge case - Horizontal line triangles
	std::cout << "###### Test 15: Edge case - Horizontal line triangles" << std::endl;
	{
		// Triangle with horizontal edge
		Point a(Fixed(0.0f), Fixed(2.0f));
		Point b(Fixed(4.0f), Fixed(2.0f));  // Horizontal edge AB
		Point c(Fixed(2.0f), Fixed(0.0f));
		Point test1(Fixed(2.0f), Fixed(1.5f));  // Should be inside
		Point test2(Fixed(2.0f), Fixed(3.0f));  // Should be outside

		std::cout << "Horizontal edge triangle: A(0,2), B(4,2), C(2,0)" <<	std::endl;
		std::cout << "Test point 1: (" << test1.get_x() << ", " <<	test1.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test1) ?	"\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
		std::cout << "Test point 2: (" << test2.get_x() << ", " <<	test2.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test2) ?	"\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 16: Edge case - Points very close to edges
	std::cout << "###### Test 16: Edge case - Points very close to edges" << std::endl;
	{
		Point a(Fixed(0.0f), Fixed(0.0f));
		Point b(Fixed(4.0f), Fixed(0.0f));
		Point c(Fixed(2.0f), Fixed(4.0f));

		// Point very close to edge but inside (using smallest representable increment)
		Point close_inside(Fixed(2.0f), Fixed(0.00390625f));  // Just above	edge AB
		// Point very close to edge but outside
		Point close_outside(Fixed(2.0f), Fixed(-0.00390625f)); // Just below edge AB

		std::cout << "Triangle: A(0,0), B(4,0), C(2,4)" << std::endl;
		std::cout << "Point just inside edge: (" << close_inside.get_x() << "," << close_inside.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, close_inside) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
		std::cout << "Point just outside edge: (" << close_outside.get_x() <<	", " << close_outside.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, close_outside) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 17: Edge case - Right-angled triangles at origin
	std::cout << "###### Test 17: Edge case - Right-angled triangles at origin" << std::endl;
	{
		// Different orientations of right triangles at origin
		Point a(Fixed(0.0f), Fixed(0.0f));
		Point b(Fixed(2.0f), Fixed(0.0f));
		Point c(Fixed(0.0f), Fixed(2.0f));
		Point test_inside(Fixed(0.5f), Fixed(0.5f));   // Should be inside
		Point test_outside(Fixed(1.5f), Fixed(1.5f));  // Should be outside (beyond hypotenuse)

		std::cout << "Right triangle at origin: A(0,0), B(2,0), C(0,2)" <<	std::endl;
		std::cout << "Test point inside: (" << test_inside.get_x() << ", " <<	test_inside.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test_inside) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
		std::cout << "Test point outside: (" << test_outside.get_x() << ", " << test_outside.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test_outside) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 18: Edge case - Isosceles triangles
	std::cout << "###### Test 18: Edge case - Isosceles triangles" <<	std::endl;
	{
		Point a(Fixed(-2.0f), Fixed(0.0f));
		Point b(Fixed(2.0f), Fixed(0.0f));
		Point c(Fixed(0.0f), Fixed(3.0f));
		Point test_center(Fixed(0.0f), Fixed(1.0f));     // Center, should be inside
		Point test_side(Fixed(1.5f), Fixed(0.75f));      // Near right side, should be inside
		Point test_outside(Fixed(0.0f), Fixed(-1.0f));   // Below base, should be outside

		std::cout << "Isosceles triangle: A(-2,0), B(2,0), C(0,3)" <<	std::endl;
		std::cout << "Center point: (" << test_center.get_x() << ", " <<	test_center.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test_center) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
		std::cout << "Side point: (" << test_side.get_x() << ", " <<	test_side.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test_side) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
		std::cout << "Outside point: (" << test_outside.get_x() << ", " <<	test_outside.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test_outside) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 19: Edge case - Obtuse triangles
	std::cout << "###### Test 19: Edge case - Obtuse triangles" <<	std::endl;
	{
		// Obtuse triangle (angle at B > 90 degrees)
		Point a(Fixed(0.0f), Fixed(0.0f));
		Point b(Fixed(1.0f), Fixed(0.0f));
		Point c(Fixed(-1.0f), Fixed(1.0f));
		Point test_inside(Fixed(0.0f), Fixed(0.25f));    // Should be inside
		Point test_outside(Fixed(-0.5f), Fixed(0.75f));  // Should be outside

		std::cout << "Obtuse triangle: A(0,0), B(1,0), C(-1,1)" << std::endl;
		std::cout << "Test point inside: (" << test_inside.get_x() << ", " <<	test_inside.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test_inside) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
		std::cout << "Test point outside: (" << test_outside.get_x() << ", " << test_outside.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test_outside) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;

	// Test 20: Edge case - Zero coordinate handling
	std::cout << "###### Test 20: Edge case - Zero coordinate handling" <<	std::endl;
	{
		Point a(Fixed(0.0f), Fixed(0.0f));
		Point b(Fixed(0.0f), Fixed(1.0f));  // Vertical line from origin
		Point c(Fixed(1.0f), Fixed(0.0f));  // Horizontal line from origin
		Point test_inside(Fixed(0.25f), Fixed(0.25f));   // Should be inside
		Point test_origin(Fixed(0.0f), Fixed(0.0f));     // At vertex A, should be outside

		std::cout << "Triangle with zero coordinates: A(0,0), B(0,1), C(1,0)" << std::endl;
		std::cout << "Test point inside: (" << test_inside.get_x() << ", " <<	test_inside.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test_inside) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[32m YES" << "\033[0m" << std::endl;
		std::cout << "Point at origin: (" << test_origin.get_x() << ", " <<	test_origin.get_y() << ")" << std::endl;
		std::cout << "Is point inside triangle? " << (bsp(a, b, c, test_origin) ? "\033[32m YES" : "\033[31m NO") << " <==> \033[31m NO" << "\033[0m" << std::endl;
	}
	std::cout << std::endl;


  // 1. Test 14: Vertical edges (your vertical line logic)
  // 2. Test 15: Horizontal edges (slope = 0 case)
  // 3. Test 16: Fixed-point precision at boundaries
  // 4. Test 17: Right triangles at origin (coordinate system edge case)
  // 5. Test 18: Symmetric triangles (isosceles)
  // 6. Test 19: Obtuse triangles (wide angles)
  // 7. Test 20: Zero coordinates (origin handling)
	return 0;
}
