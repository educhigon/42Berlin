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

#include "Serializer.hpp"

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}
void basicTestsSerializer()
{
	printSeparator("basicTestsSerializer");

	Data a;
	a.str	= "John";
	a.age = 30;
	std::cout << "Original Data: " << a.str << ", " << a.age << std::endl;
	std::cout << "Original Data address: " << &a << std::endl;
	std::cout << "Original Data address (as an integer): " << reinterpret_cast<uintptr_t>(&a) << std::endl;
	uintptr_t pt = Serializer::serialize(&a);
	std::cout << "Original Data address (as an integer): " << pt << std::endl;

	Data* b = Serializer::deserialize(pt);
	std::cout << "Deserialized Data: " << b->str << ", " << b->age << std::endl;
	std::cout << "Deserialized Data address: " << b << std::endl;
	std::cout << "Deserialized Data address (as an integer): " << reinterpret_cast<uintptr_t>(b) << std::endl;
	uintptr_t pt2 = Serializer::serialize(b);
	std::cout << "Deserialized Data address (as an integer): " << pt2 << std::endl;


	if (b == &a)
		std::cout << "\033[32mPASS: pointers are equal\033[0m" << std::endl;
	else
		std::cout << "\033[31mFAIL: pointers differ\033[0m" << std::endl;

	return;
}
void basicTestsSerializerHeap()
{
	printSeparator("basicTestsSerializerHeap");

	Data* a = new Data();
	a->str	= "David";
	a->age = 20;
	std::cout << "Original Data: " << a->str << ", " << a->age << std::endl;
	std::cout << "Original Data address: " << a << std::endl;
	std::cout << "Original Data address (as an integer): " << reinterpret_cast<uintptr_t>(a) << std::endl;
	uintptr_t pt = Serializer::serialize(a);
	std::cout << "Original Data address (as an integer): " << pt << std::endl;

	Data* b = Serializer::deserialize(pt);
	std::cout << "Deserialized Data: " << b->str << ", " << b->age << std::endl;
	std::cout << "Deserialized Data address: " << b << std::endl;
	std::cout << "Deserialized Data address (as an integer): " << reinterpret_cast<uintptr_t>(b) << std::endl;
	uintptr_t pt2 = Serializer::serialize(b);
	std::cout << "Deserialized Data address (as an integer): " << pt2 << std::endl;


	if (b == a)
		std::cout << "\033[32mPASS: pointers are equal\033[0m" << std::endl;
	else
		std::cout << "\033[31mFAIL: pointers differ\033[0m" << std::endl;
	delete a;
	return;
}
int main()
{
	printSeparator("CPP06 - EX01");
	basicTestsSerializer();
	basicTestsSerializerHeap();
	printSeparator("ALL TESTS COMPLETED!");
	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./Serializer" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}
