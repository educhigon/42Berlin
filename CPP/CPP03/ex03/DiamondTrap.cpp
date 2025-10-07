/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:22:46 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 17:34:44 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :  ClapTrap(), FragTrap(), ScavTrap(), _name("")
{
	std::cout << "\033[36m[DiamondTrap]\033[0m Default constructor called on '" << this->_name << "'" << std::endl;
	ClapTrap::_name = this->_name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[36m[DiamondTrap]\033[0m Destructor called on '" << this->_name << "'" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "\033[36m[DiamondTrap]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->ClapTrap::_name = other.ClapTrap::_name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		this->_name = other._name;
	}
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
	std::cout << "\033[36m[DiamondTrap]\033[0m Copy constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "\033[36m[DiamondTrap]\033[0m Constructor called on '" << this->_name << "'" << std::endl;
	ClapTrap::_name = this->_name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

void DiamondTrap::attack(const std::string& target)
{
	std::cout << "\033[36m[DiamondTrap]\033[0m Attacking!! '" << this->_name << "'" << std::endl;
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
		std::cout << "\033[36m[DiamondTrap]\033[0m " << "My name is: " << this->_name << " AKA: " << this->ClapTrap::_name << std::endl;
}
