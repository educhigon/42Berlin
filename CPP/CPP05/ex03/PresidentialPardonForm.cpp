/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"PresidentialPardonForm.hpp"

// ##############
// CANONICAL FORM
// ##############

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\033[34m[PresidentialPardonForm]\033[0m Default Constructor called on '" << this->getName() << " with target: " << this->_target << "'" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[34m[PresidentialPardonForm]\033[0m Destructor called on '" << this->getName() << "'" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "\033[34m[PresidentialPardonForm]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

// Better construction - best practice
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), _target(obj._target)
{
	std::cout << "\033[34m[PresidentialPardonForm]\033[0m Copy constructor called" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

void PresidentialPardonForm::executeAction() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
