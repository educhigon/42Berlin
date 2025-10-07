/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:45:09 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 17:12:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "\033[33m[FragTrap]\033[0m Default constructor called on '" << this->_name << "'" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}
FragTrap::~FragTrap()
{
	std::cout << "\033[33m[FragTrap]\033[0m Destructor called on '" << this->_name << "'" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "\033[33m[FragTrap]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "\033[33m[FragTrap]\033[0m Copy constructor called" << std::endl;
}


FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "\033[33m[FragTrap]\033[0m Constructor called on '" << this->_name << "'" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

void FragTrap::attack(const std::string& target)
{
	if(this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout << "\033[33m[FragTrap]\033[0m " << this->_name << " has no energy points or hit points left" << std::endl;
		return;
	}
	std::cout << "\033[33m[FragTrap]\033[0m " << this->_name << " has '" << this->_energyPoints << "' energy points. ==> ";
	std::cout << "\033[33m[FragTrap]\033[0m " << this->_name << " has '" << this->_attackDamage << "' points of damage and attacks '";
	std::cout << target << "', so '" << target << "' loses '" << this->_attackDamage << "' points"<< std::endl;
	this->_energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
		std::cout << "\033[33m[FragTrap]\033[0m " << this->_name << " HIGH FIVE!!" << std::endl;
}
