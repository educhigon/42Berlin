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

#include	"Form.hpp"
#include	"Bureaucrat.hpp"

// ##############
// CANONICAL FORM
// ##############

Form::Form(std::string _name, int gradeToSign, int gradeToExecute) : _name(_name), _isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	// if (gradeToExecute < gradeToSign)
	// 	throw Form::GradeTooLowException();
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "\033[33m[Form]\033[0m Default Constructor called on '" << this->_name << "'" << std::endl;
}
Form::~Form()
{
	std::cout << "\033[33m[Form]\033[0m Destructor called on '" << this->_name << "'" << std::endl;
}
Form& Form::operator=(const Form& other)
{
	std::cout << "\033[33m[Form]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

// Better construction - best practice
Form::Form(const Form &obj) : _name(obj._name), _isSigned(obj._isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	std::cout << "\033[33m[Form]\033[0m Copy constructor called" << std::endl;
}

// // Not the best practice:
// Form::Form(const Form &obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
//	*this = obj;
// }

// ################
// MEMBER FUNCTIONS
// ################

std::string Form::getName() const {
	return (this->_name);
}

int Form::getGradeToSign() const {
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->gradeToExecute);
}

bool Form::isSigned() const {
	return (this->_isSigned);
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << "Form " << other.getName();
	if (other.isSigned())
		os << " is signed";
	else
		os << " is NOT signed";
	os << " with grade to sign " << other.getGradeToSign() << " and grade to execute " << other.getGradeToExecute() << ".";
	return (os);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}
