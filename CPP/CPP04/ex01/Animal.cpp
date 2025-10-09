/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Animal.hpp"

// ##############
// CANONICAL FORM
// ##############

Animal::Animal() : _type("")
{
	std::cout << "\033[32m[Animal]\033[0m Default Constructor called on '" << this->_type << "'" << std::endl;
}
Animal::~Animal()
{
	std::cout << "\033[32m[Animal]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "\033[32m[Animal]\033[0m Copy assignment operator called";
	if (this != &other)
	{
		std::cout << "  \033[32m[Animal]\033[0m Making copy";
		this->_type = other._type;
	}
	std::cout << std::endl;
	return (*this);
}

Animal::Animal(const Animal &obj) : _type(obj._type)
{
	std::cout << "\033[32m[Animal]\033[0m Copy constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "\033[32m[Animal]\033[0m Constructor called on '" << this->_type << "'" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

void Animal::makeSound() const
{
	std::cout << "\033[32m[Animal]\033[0m'" << this->_type << "' making weird sound" << std::endl;
}
std::string Animal::getType() const
{
	// std::cout << "\033[32m[Animal]\033[0m has type: '" << this->_type << "'" << std::endl;
	return this->_type;
}
void Animal::haveIdea(std::string text)
{
	(void) text;
}
std::string Animal::checkLastIdea()
{
	return "";
}
