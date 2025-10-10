/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Cure.hpp"
#include	"ICharacter.hpp"

// ##############
// CANONICAL FORM
// ##############

Cure::Cure() : AMateria("cure")
{
	std::cout << "\033[33m[Cure]\033[0m Default Constructor called on '" << this->_type << "'" << std::endl;
}
Cure::~Cure()
{
	std::cout << "\033[33m[Cure]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
}
Cure& Cure::operator=(const Cure& other)
{
	std::cout << "\033[33m[Cure]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

// Better construction - best practice
Cure::Cure(const Cure &obj) : AMateria(obj)
{
	std::cout << "\033[33m[Cure]\033[0m Copy constructor called" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

Cure* Cure::clone() const
{
	return(new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
