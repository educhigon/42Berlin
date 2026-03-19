/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2026/03/16 21:44:35 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "Span.hpp"

Span::Span(unsigned int n) {
	_size = n;
	_it = 0;
	_data = std::vector<int>(n);
	std::cout << "\033[32m[Span]\033[0m Constructor called with size: " << this->_size << std::endl;
}

Span::Span(const Span& other) {
	this->_size = other._size;
	this->_it = other._it;
	this->_data = std::vector<int>(other._size);
	for (size_t i = 0; i < this->_size; i++)
		this->_data[i] = other._data[i];
	std::cout << "\033[32m[Span]\033[0m Copy Constructor called with size: " << this->_size << std::endl;
}

Span& Span::operator=(const Span& other) {
	if (&other != this)
	{
		this->_size = other._size;
		this->_it = other._it;
		this->_data = std::vector<int>(other._size);
		for (size_t i = 0; i < this->_size; i++)
			this->_data[i] = other._data[i];
	};
	std::cout << "\033[32m[Span]\033[0m Assignment operator called with size: " << this->_size << std::endl;
	return *this;
}

Span::~Span() {
	std::cout << "\033[32m[Span]\033[0m Destructor called" << std::endl;
}

// ----------
// ----------
// ----------

void Span::addNumber(int number)
{
	std::cout << "\033[32m[Span]\033[0m ---Adding number... " << number << std::endl;

	if(this->_it < this->_size)
		this->_data[this->_it++] = number;
	else
		throw std::out_of_range("Index out of bounds");
}

int Span::shortestSpan()
{
	if(this->_it > 1)
	{
		std::vector<int> sorted(_data.begin(), _data.begin() + _it);
	  std::sort(sorted.begin(), sorted.end());
		int dist = sorted[1] - sorted[0];
		for(size_t i = 1; i < this->_it; i++)
		{
			if(sorted[i] - sorted[i - 1] < dist)
				dist = sorted[i] - sorted[i - 1];
		}
		return dist;
	}
	else
		throw std::invalid_argument("Not enough members");
}

int Span::shortestSpan_slow()
{
	if(this->_it > 1)
	{
		int dist = this->_data[0] - this->_data[1];
		if (dist < 0)
			dist *= -1;
		for(size_t i = 0; i < this->_it; i++)
		{
			for(size_t j = i + 1; j < this->_it; j++)
			{
				int temp = this->_data[i] - this->_data[j];
				if (temp < 0)
					temp *= -1;
				if (temp < dist)
					dist = temp;
			}
		}
		return(dist);
	}
	else
		throw std::invalid_argument("Not enough members");

}
int Span::longestSpan()
{
	if(this->_it > 1)
	{
		std::vector<int>::iterator min = std::min_element(this->_data.begin(), this->_data.begin() + this->_it);
		std::vector<int>::iterator max = std::max_element(this->_data.begin(), this->_data.begin() + this->_it);
		return(*max - *min);
	}
	else
		throw std::invalid_argument("Not enough members");

}
