/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 19:56:40 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"WrongCat.hpp"

// ##############
// CANONICAL FORM
// ##############

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "\033[36m[WrongCat]\033[0m Default Constructor called on '" << this->_type << "'" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "\033[36m[WrongCat]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "\033[36m[WrongCat]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Better construction - best practice
WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "\033[36m[WrongCat]\033[0m Copy constructor called" << std::endl;
}

// // Not the best practice:
// WrongCat::WrongCat(const WrongCat &obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
//	*this = obj;
// }

// WrongCat::WrongCat(std::string name) : _type(name)
// {
// 	std::cout << "\033[36m[WrongCat]\033[0m Constructor called on '" << this->_type << "'" << std::endl;
// }

// ################
// MEMBER FUNCTIONS
// ################

void WrongCat::makeSound() const
{
	std::cout << "\033[36m[WrongCat]\033[0m'" << this->_type << "' WOEMING!" << std::endl;
}
// std::string WrongCat::getType() const
// {
// 	std::cout << "\033[36m[WrongCat]\033[0m has type: '" << this->_type << "'" << std::endl;
// 	return this->_type;
// }
