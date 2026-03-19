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

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <deque>

// <stack>: Contains the std::stack class, which is a container adapter.
// <queue>: Contains the std::queue and std::priority_queue classes.


/*
Vector	std::vector
A dynamic array that can resize automatically, managing capacity as needed.	Dynamic size; efficient for
inserting/removing elements at the end.	Slower insertion/removal in the middle.

List	std::list
A doubly linked list allowing for efficient insertions and deletions anywhere in the list.	Fast insertions/deletions;
can grow/shrink dynamically.	Slower access times; higher memory overhead.

Set	std::set
A collection of unique integers, automatically sorted and prevents duplicates.	Unique values; fast lookups,
insertions, and deletions.	Not index-accessible; may have higher overhead.

Deque	std::deque
A double-ended queue that allows insertion and deletion from both ends.	Fast insertion/removal from both ends; can grow dynamically.
More complex than vectors; memory could be fragmented.

Map	std::map
A collection of key-value pairs where keys are unique, often used for associating integers with other data.
Fast lookups; useful for relationships.	Higher memory overhead; not index-accessible.

*/

void printSeparator(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void basicTestsEasyFindVector()
{
	printSeparator("basicTestsEasyFindVector");
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try
	{
		std::cout << "Finding 3 inside the container: " << easyfind(vec, 3) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

		try
	{
		std::cout << "Finding 6 inside the container: " << easyfind(vec, 6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void basicTestsEasyFindList()
{
	printSeparator("basicTestsEasyFindList");
	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	try
	{
		std::cout << "Finding 3 inside the container: " << easyfind(list, 3) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

		try
	{
		std::cout << "Finding 6 inside the container: " << easyfind(list, 6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}

void basicTestsEasyFindSet()
{
	printSeparator("basicTestsEasyFindSet");
	std::set<int> set;
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(4);
	set.insert(5);

	try
	{
		std::cout << "Finding 3 inside the container: " << easyfind(set, 3) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

		try
	{
		std::cout << "Finding 6 inside the container: " << easyfind(set, 6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void basicTestsEasyFindMap()
{
	printSeparator("basicTestsEasyFindMap");
	std::map<int, int> map;
	map[1] = 10;
	map[2] = 20;
	map[3] = 30;
	map[4] = 40;
	map[5] = 50;

	std::cout << "\033[33mMaps are key/value pairs, it cannot be used with easyfind (not T<int>)\033[0m" << std::endl;

	/*
	This is the fundamental reason map doesn't fit: the subject says "assuming T is a container of integers", and std::map is not a container of integers —
	it's a container of key-value pairs. Map is intentionally out of scope for this exercise. The containers that work are the ones whose elements are
	integers: vector<int>, list<int>, set<int>, deque<int>.

	*/
	// try
	// {
	// 	std::cout << "Finding 3 inside the container: " << easyfind(map, 3) << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// 	try
	// {
	// 	std::cout << "Finding 6 inside the container: " << easyfind(map, 6) << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

}

void basicTestsEasyFindDeque()
{
	printSeparator("basicTestsEasyFindDeque");
	std::deque<int> deque;
	deque.push_back(1);
	deque.push_back(2);
	deque.push_back(3);
	deque.push_back(4);
	deque.push_back(5);

	try
	{
		std::cout << "Finding 3 inside the container: " << easyfind(deque, 3) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

		try
	{
		std::cout << "Finding 6 inside the container: " << easyfind(deque, 6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}


int main()
{
	printSeparator("CPP08 - EX00");

	basicTestsEasyFindVector();
	basicTestsEasyFindList();
	basicTestsEasyFindSet();
	basicTestsEasyFindMap();
	basicTestsEasyFindDeque();

	printSeparator("ALL TESTS COMPLETED!");
	std::cout << "To check for memory leaks, run:" << std::endl;
	std::cout << "  valgrind --leak-check=full --show-leak-kinds=all ./Easyfind" << std::endl;
	std::cout << "\nExpected result: \"All heap blocks were freed -- no leaks are possible\" " << std::endl;
	std::cout << "========================================\n" << std::endl;
	return 0;
}
