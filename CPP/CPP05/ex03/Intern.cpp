/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ##############
// CANONICAL FORM
// ##############

Intern::Intern()
{
	std::cout << "\033[41m[Intern]\033[0m Default Constructor called on '" << "'" << std::endl;
}
Intern::~Intern()
{
	std::cout << "\033[41m[Intern]\033[0m Destructor called on '" << "'" << std::endl;
}
Intern& Intern::operator=(const Intern& other)
{
	std::cout << "\033[41m[Intern]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

// Better construction - best practice
Intern::Intern(const Intern &obj)
{
	std::cout << "\033[41m[Intern]\033[0m Copy constructor called" << std::endl;
	*this = obj;
}

// // Not the best practice:
// Intern::Intern(const Intern &obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
//	*this = obj;
// }


// ################
// MEMBER FUNCTIONS
// ################

AForm* CSchrub(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* CRobo(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* CPres(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	tuple_t db[] = {
		{"shrubbery creation", CSchrub},
		{"robotomy request", CRobo},
		{"presidential pardon", CPres},
		{"schrub", CSchrub},
		{"robo", CRobo},
		{"pardon", CPres}
	};

	try
	{
		for (size_t i = 0; i < sizeof(db) / sizeof(tuple_t); i++)
		{
			if (db[i].keyword == formName)
			{
				std::cout << "\033[41m[Intern]\033[0m creates " << formName << std::endl;
				return (db[i].FormCreator(target));
			}
		}
		throw std::runtime_error("Form not found");
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[41m[Intern]\033[0m " << e.what() << '\n';
	}

	return (NULL);
}
