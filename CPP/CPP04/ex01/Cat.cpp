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
	std::cout << "\033[31m[Cat]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
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

// // Not the best practice:
// Cat::Cat(const Cat &obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
//	*this = obj;
// }

// Cat::Cat(std::string name) : Animal(name)
// {
// 	std::cout << "\033[31m[Cat]\033[0m Constructor called on '" << this->_type << "'" << std::endl;
// }

// ################
// MEMBER FUNCTIONS
// ################

void Cat::makeSound() const
{
	std::cout << "\033[31m[Cat]\033[0m'" << this->_type << "' meowing!" << std::endl;
}
// std::string Cat::getType() const
// {
// 	std::cout << "\033[31m[Cat]\033[0m has type: '" << this->_type << "'" << std::endl;
// 	return this->_type;
// }

void Cat::haveIdea(std::string text)
{
	std::cout << "Cat had idea: " << text << std::endl;
	this->brain->createIdea(text);
}
std::string Cat::checkLastIdea()
{
	return this->brain->getLastIdea();
}
