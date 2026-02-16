/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"

// ##############
// CANONICAL FORM
// ##############

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "\033[32m[Bureaucrat]\033[0m Constructor called on '" << this->_name << "'" << std::endl;
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[32m[Bureaucrat]\033[0m Destructor called on '" << this->_name << "'" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "\033[32m[Bureaucrat]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

// Better construction - best practice
Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade)
{
	std::cout << "\033[32m[Bureaucrat]\033[0m Copy constructor called" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################


std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if(this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if(this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::operator<<(const Bureaucrat& other) {
	std::cout << other._name << ", bureaucrat grade " << other._grade << "." << std::endl;
}
