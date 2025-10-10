/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Ice.hpp"
#include	"ICharacter.hpp"

// ##############
// CANONICAL FORM
// ##############

Ice::Ice() : AMateria("ice")
{
	std::cout << "\033[34m[Ice]\033[0m Default Constructor called on '" << this->_type << "'" << std::endl;
}
Ice::~Ice()
{
	std::cout << "\033[34m[Ice]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
}
Ice& Ice::operator=(const Ice& other)
{
	std::cout << "\033[34m[Ice]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

// Better construction - best practice
Ice::Ice(const Ice &obj) : AMateria(obj)
{
	std::cout << "\033[34m[Ice]\033[0m Copy constructor called" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

Ice* Ice::clone() const
{
	return(new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
