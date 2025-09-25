/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/25 21:48:48 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ##############
// CANONICAL FORM
// ##############

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\033[32m[ClapTrap]\033[0m Constructor called on '" << this->_name << "'" << std::endl;
}
ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\033[32m[ClapTrap]\033[0m Default Constructor called on '" << this->_name << "'" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "\033[32m[ClapTrap]\033[0m Destructor called on '" << this->_name << "'" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "\033[32m[ClapTrap]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

// Better construction - best practice
ClapTrap::ClapTrap(const ClapTrap &obj) : _name(obj._name), _hitPoints(obj._hitPoints), _energyPoints(obj._energyPoints), _attackDamage(obj._attackDamage)
{
	std::cout << "\033[32m[ClapTrap]\033[0m Copy constructor called" << std::endl;
}

// // Not the best practice:
// ClapTrap::ClapTrap(const ClapTrap &obj)
// {
// 	std::cout << "Copy constructor called" << std::endl;
//	*this = obj;
// }

// ################
// MEMBER FUNCTIONS
// ################

void ClapTrap::attack(const std::string& target)
{
	if(this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << "\033[32m[ClapTrap]\033[0m " << this->_name << " has no energy points or hit points left" << std::endl;
		return;
	}
	std::cout << "\033[32m[ClapTrap]\033[0m " << this->_name << " has '" << this->_energyPoints << "' energy points. ==> ";
	std::cout << "\033[32m[ClapTrap]\033[0m " << this->_name << " has '" << this->_attackDamage << "' points of damage and attacks '";
	std::cout << target << "', so '" << target << "' loses '" << this->_attackDamage << "' points"<< std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_hitPoints <= 0)
	{
		std::cout << "\033[32m[ClapTrap]\033[0m " << this->_name << " cannot takes any more damage, its hitPoints are:" << this->_hitPoints << std::endl;
		return;
	}
	std::cout << "\033[32m[ClapTrap]\033[0m " << this->_name << " takes damage of '" << amount << "', so its hitPoints go from:" << this->_hitPoints;
	this->_hitPoints -= amount;
	std::cout << " to " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << "\033[32m[ClapTrap]\033[0m " << this->_name << " has no energy points or hit points left" << std::endl;
		return;
	}
	std::cout << "\033[32m[ClapTrap]\033[0m " << this->_name << " has '" << this->_energyPoints << "' energy points. ==> ";
	std::cout << "\033[32m[ClapTrap]\033[0m " << this->_name << " repairs itself with " << amount << ", so its hitPoints go from:" << this->_hitPoints;
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << " to " << this->_hitPoints << std::endl;
}
