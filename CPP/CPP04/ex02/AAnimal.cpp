/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"AAnimal.hpp"

// ##############
// CANONICAL FORM
// ##############

AAnimal::AAnimal() : _type("")
{
	std::cout << "\033[32m[AAnimal]\033[0m Default Constructor called on '" << this->_type << "'" << std::endl;
}
AAnimal::~AAnimal()
{
	std::cout << "\033[32m[AAnimal]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
}
AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "\033[32m[AAnimal]\033[0m Copy assignment operator called";
	if (this != &other)
	{
		std::cout << "  \033[32m[AAnimal]\033[0m Making copy";
		this->_type = other._type;
	}
	std::cout << std::endl;
	return (*this);
}

AAnimal::AAnimal(const AAnimal &obj) : _type(obj._type)
{
	std::cout << "\033[32m[AAnimal]\033[0m Copy constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "\033[32m[AAnimal]\033[0m Constructor called on '" << this->_type << "'" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

// void AAnimal::makeSound() const
// {
// 	std::cout << "\033[32m[AAnimal]\033[0m'" << this->_type << "' making weird sound" << std::endl;
// }
std::string AAnimal::getType() const
{
	// std::cout << "\033[32m[AAnimal]\033[0m has type: '" << this->_type << "'" << std::endl;
	return this->_type;
}
void AAnimal::haveIdea(std::string text)
{
	(void) text;
}
std::string AAnimal::checkLastIdea()
{
	return "";
}
