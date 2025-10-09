/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/09 14:07:32 by edugonza         ###   ########.fr       */
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
	std::cout << "\033[36m[WrongCat]\033[0m Copy assignment operator called";
	if (this != &other)
	{
		std::cout << "  \033[36m[WrongCat]\033[0m Making copy";
		this->_type = other._type;
	}
	std::cout << std::endl;
	return (*this);
}

// Better construction - best practice
WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "\033[36m[WrongCat]\033[0m Copy constructor called" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

void WrongCat::makeSound() const
{
	std::cout << "\033[36m[WrongCat]\033[0m'" << this->_type << "' WOEMING!" << std::endl;
}
