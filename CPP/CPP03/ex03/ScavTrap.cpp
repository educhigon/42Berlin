/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:09:04 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:29:44 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// ##############
// CANONICAL FORM
// ##############

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "\033[31m[ScavTrap]\033[0m Default Constructor called on '" << this->_name << "'" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}
ScavTrap::~ScavTrap()
{
	std::cout << "\033[31m[ScavTrap]\033[0m Destructor called on '" << this->_name << "'" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "\033[31m[ScavTrap]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

// Better construction - best practice
ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "\033[31m[ScavTrap]\033[0m Copy constructor called" << std::endl;
}

// // Not the best practice:
// ScavTrap::ScavTrap(const ScavTrap &obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
//	*this = obj;
// }

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[31m[ScavTrap]\033[0m Constructor called on '" << this->_name << "'" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

// ################
// MEMBER FUNCTIONS
// ################

void ScavTrap::attack(const std::string& target)
{
	if(this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << "\033[31m[ScavTrap]\033[0m " << this->_name << " has no energy points or hit points left" << std::endl;
		return;
	}
	std::cout << "\033[31m[ScavTrap]\033[0m " << this->_name << " has '" << this->_energyPoints << "' energy points. ==> ";
	std::cout << "\033[31m[ScavTrap]\033[0m " << this->_name << " has '" << this->_attackDamage << "' points of damage and attacks '";
	std::cout << target << "', so '" << target << "' loses '" << this->_attackDamage << "' points"<< std::endl;
	this->_energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << "\033[31m[ScavTrap]\033[0m " << this->_name << " is now in Gate keeper mode." << std::endl;
}
