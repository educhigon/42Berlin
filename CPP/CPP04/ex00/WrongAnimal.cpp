/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"WrongAnimal.hpp"

// ##############
// CANONICAL FORM
// ##############

WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "\033[35m[WrongAnimal]\033[0m Default Constructor called on '" << this->_type << "'" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[35m[WrongAnimal]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "\033[35m[WrongAnimal]\033[0m Copy assignment operator called";
	if (this != &other)
	{
		std::cout << "  \033[35m[WrongAnimal]\033[0m Making copy";
		this->_type = other._type;
	}
	std::cout << std::endl;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) : _type(obj._type)
{
	std::cout << "\033[35m[WrongAnimal]\033[0m Copy constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "\033[35m[WrongAnimal]\033[0m Constructor called on '" << this->_type << "'" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

void WrongAnimal::makeSound() const
{
	std::cout << "\033[35m[WrongAnimal]\033[0m'" << this->_type << "' making WEIRD sound" << std::endl;
}
std::string WrongAnimal::getType() const
{
	// std::cout << "\033[35m[WrongAnimal]\033[0m has type: '" << this->_type << "'" << std::endl;
	return this->_type;
}
