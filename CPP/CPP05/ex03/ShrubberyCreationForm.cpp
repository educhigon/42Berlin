/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ShrubberyCreationForm.hpp"
#include <fstream>

// ##############
// CANONICAL FORM
// ##############

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "\033[36m[ShrubberyCreationForm]\033[0m Default Constructor called on '" << this->getName() << " with target: " << this->_target << "'" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[36m[ShrubberyCreationForm]\033[0m Destructor called on '" << this->getName() << "'" << std::endl;
	// Destruction should not delete the file, as the form is only responsible for creating it.
	// std::string file_name = this->getName() + "_shrubbery";
	// std::ifstream file(file_name.c_str());
	// if(file.good())
	// {
	// 	if (std::remove(file_name.c_str()) != 0)
	// 		std::cerr << "Error deleting file\n";
	// }
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "\033[36m[ShrubberyCreationForm]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

// Better construction - best practice
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target)
{
	std::cout << "\033[36m[ShrubberyCreationForm]\033[0m Copy constructor called" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################


void ShrubberyCreationForm::executeAction() const
{
	std::string file_name = this->_target + "_shrubbery";
	std::ofstream file(file_name.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error creating file\n";
		return ;
	}
	file << "         *\n        /|\\\n       /*|O\\\n      /*/|\\*\\\n     /X/O|*\\X\\\n    /*/X/|\\X\\*\\\n   /O/*/X|*\\O\\X\\\n  /*/O/X/|\\X\\O\\*\\\n /X/O/*/X|O\\X\\*\\O\\\n/O/X/*/O/|\\X\\*\\O\\X\\\n        |X|\n        |X|\n";
	file << "\n\n";
	file << "         *\n        /|\\\n       /*|O\\\n      /*/|\\*\\\n     /X/O|*\\X\\\n    /*/X/|\\X\\*\\\n   /O/*/X|*\\O\\X\\\n  /*/O/X/|\\X\\O\\*\\\n /X/O/*/X|O\\X\\*\\O\\\n/O/X/*/O/|\\X\\*\\O\\X\\\n        |X|\n        |X|\n";
	file.close();
}
