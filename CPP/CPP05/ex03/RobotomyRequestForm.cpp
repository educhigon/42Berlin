/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"RobotomyRequestForm.hpp"
#include	<cstdlib>

// ##############
// CANONICAL FORM
// ##############

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[35m[RobotomyRequestForm]\033[0m Default Constructor called on '" << this->getName() << " with target: " << this->_target << "'" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[35m[RobotomyRequestForm]\033[0m Destructor called on '" << this->getName() << "'" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "\033[35m[RobotomyRequestForm]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

// Better construction - best practice
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target)
{
	std::cout << "\033[35m[RobotomyRequestForm]\033[0m Copy constructor called" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Making some drilling noises" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized sucessfully" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << std::endl;
}
