/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"AForm.hpp"
#include	"Bureaucrat.hpp"

// ##############
// CANONICAL FORM
// ##############

AForm::AForm(std::string _name, int gradeToSign, int gradeToExecute) : _name(_name), _isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	// if (gradeToExecute < gradeToSign)
	// 	throw AForm::GradeTooLowException();
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "\033[33m[AForm]\033[0m Default Constructor called on '" << this->_name << "'" << std::endl;
}
AForm::~AForm()
{
	std::cout << "\033[33m[AForm]\033[0m Destructor called on '" << this->_name << "'" << std::endl;
}
AForm& AForm::operator=(const AForm& other)
{
	std::cout << "\033[33m[AForm]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

// Better construction - best practice
AForm::AForm(const AForm &obj) : _name(obj._name), _isSigned(obj._isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	std::cout << "\033[33m[AForm]\033[0m Copy constructor called" << std::endl;
}

// // Not the best practice:
// AForm::AForm(const AForm &obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
//	*this = obj;
// }

// ################
// MEMBER FUNCTIONS
// ################

std::string AForm::getName() const {
	return (this->_name);
}

int AForm::getGradeToSign() const {
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (this->gradeToExecute);
}

bool AForm::isSigned() const {
	return (this->_isSigned);
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os << "AForm " << other.getName();
	if (other.isSigned())
		os << " is signed";
	else
		os << " is NOT signed";
	os << " with grade to sign " << other.getGradeToSign() << " and grade to execute " << other.getGradeToExecute() << ".";
	return (os);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}
void AForm::execute(Bureaucrat const & executor) const
{
	if(!this->isSigned())
		throw AForm::NotSignedException();
	if(this->gradeToExecute < executor.getGrade())
		throw AForm::GradeTooLowException();
	this->executeAction();
}
