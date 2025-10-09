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
	brain = new Brain();
}
Cat::~Cat()
{
	std::cout << "\033[31m[Cat]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
	delete brain;
}
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "\033[31m[Cat]\033[0m Copy assignment operator called";
	if (this != &other)
	{
		std::cout << "  \033[31m[Cat]\033[0m Making copy";
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << std::endl;
	return (*this);
}

// Better construction - best practice
Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "\033[31m[Cat]\033[0m Copy constructor called" << std::endl;
	if (this != &obj)
	{
		this->brain = new Brain(*obj.brain);
	}
}

// ################
// MEMBER FUNCTIONS
// ################

void Cat::makeSound() const
{
	std::cout << "\033[31m[Cat]\033[0m'" << this->_type << "' meowing!" << std::endl;
}

void Cat::haveIdea(std::string text)
{
	std::cout << "Cat had idea: " << text << std::endl;
	this->brain->createIdea(text);
}
std::string Cat::checkLastIdea()
{
	return this->brain->getLastIdea();
}
