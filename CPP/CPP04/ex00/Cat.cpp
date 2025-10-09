/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Cat.hpp"

// ##############
// CANONICAL FORM
// ##############

Cat::Cat() : Animal("Cat")
{
	std::cout << "\033[31m[Cat]\033[0m Default Constructor called on '" << this->_type << "'" << std::endl;
}
Cat::~Cat()
{
	std::cout << "\033[31m[Cat]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "\033[31m[Cat]\033[0m Copy assignment operator called";
	if (this != &other)
	{
		std::cout << "  \033[31m[Cat]\033[0m Making copy";
		this->_type = other._type;
	}
	std::cout << std::endl;
	return (*this);
}

// Better construction - best practice
Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "\033[31m[Cat]\033[0m Copy constructor called" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

void Cat::makeSound() const
{
	std::cout << "\033[31m[Cat]\033[0m'" << this->_type << "' meowing!" << std::endl;
}
