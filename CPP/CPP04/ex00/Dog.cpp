/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Dog.hpp"

// ##############
// CANONICAL FORM
// ##############

Dog::Dog() : Animal("Dog")
{
	std::cout << "\033[33m[Dog]\033[0m Default Constructor called on '" << this->_type << "'" << std::endl;
}
Dog::~Dog()
{
	std::cout << "\033[33m[Dog]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "\033[33m[Dog]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Better construction - best practice
Dog::Dog(const Dog &obj) : Animal(obj._type)
{
	std::cout << "\033[33m[Dog]\033[0m Copy constructor called" << std::endl;
}

// // Not the best practice:
// Dog::Dog(const Dog &obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
//	*this = obj;
// }

// Dog::Dog(std::string name) : Animal(name)
// {
// 	std::cout << "\033[33m[Dog]\033[0m Constructor called on '" << this->_type << "'" << std::endl;
// }

// ################
// MEMBER FUNCTIONS
// ################

void Dog::makeSound() const
{
	std::cout << "\033[33m[Dog]\033[0m '" << this->_type << "' barking!" << std::endl;
}

// std::string Dog::getType() const
// {
// 	std::cout << "\033[33m[Dog]\033[0m has type: '" << this->_type << "'" << std::endl;
// 	return this->_type;
// }
