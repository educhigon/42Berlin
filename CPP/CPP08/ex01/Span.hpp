/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2026/03/16 21:44:35 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
# define Span_HPP

#include <cstddef>
#include <iostream>
#include <vector>

class Span {

	private:
		size_t _size;
		size_t _it;
		std::vector<int> _data;

	public:
		// Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);

		// template <typename T>
		// void addNumberFail(typename T::iterator start, typename T::iterator finish);
		template <typename It>
		void addNumber(It start, It finish);

		int shortestSpan();
		int shortestSpan_slow();
		int longestSpan();
};

/*
  template <typename T>
  void Span::addNumber(typename T::iterator start, typename T::iterator finish)

The compiler sees two arguments of type std::vector<int>::iterator.
It needs to figure out what T is. T is the container type, but you're passing iterator types.
The compiler would need to reverse-engineer: "what container T has T::iterator equal to std::vector<int>::iterator?"

That's not possible — T::iterator is a dependent name, and the
C++ standard explicitly states that template deduction cannot work backwards through dependent names.
The compiler won't guess that T = std::vector<int> just because the argument matches std::vector<int>::iterator.
*/

// template <typename T>
// void Span::addNumberFail(typename T::iterator start, typename T::iterator finish)
	// while(start != finish)
	// {
	// 	try
	// 	{
	// 		this->addNumber(*start);
	// 		start++;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << "\033[31m" << e.what() << "\033[0m\n";
	// 		break;
	// 	}
	// }
// }

template <typename It>
void Span::addNumber(It start, It finish)
{
	while(start != finish)
	{
		try
		{
			this->addNumber(*start);
			start++;
		}
		catch(const std::exception& e)
		{
			std::cerr << "\033[31m" << e.what() << "\033[0m\n";
			break;
		}
	}
}

#endif
