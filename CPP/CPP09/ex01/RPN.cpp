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

RPN::RPN() : _name("")
{
	std::cout << "\033[32m[RPN]\033[0m Default Constructor called on '" << this->_name << "'" << std::endl;
}
RPN::~RPN()
{
	std::cout << "\033[32m[RPN]\033[0m Destructor called on '" << this->_name << "'" << std::endl;
}
RPN& RPN::operator=(const RPN& other)
{
	std::cout << "\033[32m[RPN]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
	}
	return (*this);
}

// Better construction - best practice
RPN::RPN(const RPN &obj) : _name(obj._name)
{
	std::cout << "\033[32m[RPN]\033[0m Copy constructor called" << std::endl;
}

// // Not the best practice:
// RPN::RPN(const RPN &obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
//	*this = obj;
// }

RPN::RPN(std::string name) : _name(name)
{
	std::cout << "\033[32m[RPN]\033[0m Constructor called on '" << this->_name << "'" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

