/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/10 17:24:47 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"AMateria.hpp"

// ##############
// CANONICAL FORM
// ##############

AMateria::AMateria() : _type("")
{
	std::cout << "\033[32m[AMateria]\033[0m Default Constructor called on '" << this->_type << "'" << std::endl;
}
AMateria::~AMateria()
{
	std::cout << "\033[32m[AMateria]\033[0m Destructor called on '" << this->_type << "'" << std::endl;
}
AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "\033[32m[AMateria]\033[0m Copy assignment operator called" << std::endl;
	(void) other;
	// if (this != &other)
	// {
	// 	this->_type = other._type;
	// }
	return (*this);
}

// Better construction - best practice
AMateria::AMateria(const AMateria &obj) : _type(obj._type)
{
	std::cout << "\033[32m[AMateria]\033[0m Copy constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "\033[32m[AMateria]\033[0m Constructor called on '" << this->_type << "'" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

std::string const & AMateria::getType() const
{
	return(this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void) target;
	std::cout << "\033[32m[AMateria]\033[0m ##########   I should not have been called !!!!!!!!" << std::endl;
}
