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
	brain = new Brain();
}
Dog::~Dog()
{
	std::cout << "\033[33m[Dog]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
	delete brain;
}
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "\033[33m[Dog]\033[0m Copy assignment operator called";
	if (this != &other)
	{
		delete this->brain;
		std::cout << "  \033[33m[Dog]\033[0m Making copy";
		this->brain = new Brain(*other.brain);
	}
	std::cout << std::endl;
	return (*this);
}

// Better construction - best practice
Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "\033[33m[Dog]\033[0m Copy constructor called" << std::endl;
	if (this != &obj)
	{
		this->brain = new Brain(*obj.brain);
	}
}

// ################
// MEMBER FUNCTIONS
// ################

void Dog::makeSound() const
{
	std::cout << "\033[33m[Dog]\033[0m '" << this->_type << "' barking!" << std::endl;
}

void Dog::haveIdea(std::string text)
{
	std::cout << "Dog had idea: " << text << std::endl;
	this->brain->createIdea(text);
}
std::string Dog::checkLastIdea()
{
	return this->brain->getLastIdea();
}
