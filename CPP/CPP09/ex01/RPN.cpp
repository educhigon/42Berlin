/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"RPN.hpp"

// ##############
// CANONICAL FORM
// ##############

RPN::RPN()
{
	std::cout << "\033[32m[RPN]\033[0m Default Constructor called on " << std::endl;
}
RPN::~RPN()
{
	std::cout << "\033[32m[RPN]\033[0m Destructor called on " << std::endl;
}
RPN& RPN::operator=(const RPN& other)
{
	std::cout << "\033[32m[RPN]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (size_t i = 0; i < other._items.size(); i++)
			this->_items[i] = other._items[i];
	}
	return (*this);
}

// Better construction - best practice
RPN::RPN(const RPN &obj)
{
	std::cout << "\033[32m[RPN]\033[0m Copy constructor called" << std::endl;
	for (size_t i = 0; i < obj._items.size(); i++)
		this->_items[i] = obj._items[i];
}

// // Not the best practice:
// RPN::RPN(const RPN &obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
//	*this = obj;
// }

RPN::RPN(std::deque<char> items) : _items(items)
{
	std::cout << "\033[32m[RPN]\033[0m Constructor called on " << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

bool is_dig(char c)
{
	return (std::isdigit(c));
}

bool is_op(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}


double calculate(double val1, double val2, char op)
{
	switch (op)
	{
		case '+':
			return (val1 + val2);
		case '-':
			return (val1 - val2);
		case '*':
			return (val1 * val2);
		case '/':
			if (val2 == 0)
				throw std::runtime_error("Division by zero");
			return (val1 / val2);
		default:
			throw std::runtime_error("Invalid operator");
	}
}

double RPN::evaluate()
{
	std::deque<double> numbers;

	for (size_t i = 0; i < this->_items.size(); i++)
	{
		if (is_dig(this->_items[i]))
			numbers.push_back(this->_items[i] - '0');
		else if (is_op(this->_items[i]))
		{
			if (numbers.size() >= 2)
			{
				double val2 = numbers.back();
				numbers.pop_back();
				double val1 = numbers.back();
				numbers.pop_back();
				numbers.push_back(calculate(val1, val2, this->_items[i]));
			}
			else
				throw std::runtime_error("Invalid expression: too few numbers or too many operands");
		}
	}
	if (numbers.size() != 1)
		throw std::runtime_error("Invalid expression: too few operands or too many numbers");
	return (numbers.back());
}


RPN* check_save_input(std::string input)
{
	std::deque<char> items;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (is_dig(input[i]) || is_op(input[i]) || std::isspace(input[i]))
			items.push_back(input[i]);
		else
			throw std::runtime_error("Invalid character in input");
	}

	RPN *rpn = new RPN(items);
	return (rpn);
}
