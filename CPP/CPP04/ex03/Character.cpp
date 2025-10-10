/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Character.hpp"
#include	"AMateria.hpp"

// ##############
// CANONICAL FORM
// ##############

Character::Character() : ICharacter(), _name("")
{
	std::cout << "\033[31m[Character]\033[0m Default Constructor called on '" << this->_name << "'" << std::endl;
	for(int i = 0; i<4; i++)
		_inventory[i] = NULL;
}
Character::~Character()
{
	std::cout << "\033[31m[Character]\033[0m Destructor called on '" << this->_name << "'" << std::endl;
	for(int i = 0; i<4; i++)
		delete _inventory[i];
}
Character& Character::operator=(const Character& other)
{
	std::cout << "\033[31m[Character]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		for(int i = 0; i<4; i++)
		{
			delete _inventory[i];
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
			// Be careful with shallow copies. We are copying the pointers here not creating a new object for the constructor
			// Don't do this:
			// for(int i = 0; i<4; i++)
			// _inventory[i] = other._inventory[i];

		}
	}
	return (*this);
}

// Better construction - best practice
Character::Character(const Character &obj) : _name(obj._name)
{
	std::cout << "\033[31m[Character]\033[0m Copy constructor called" << std::endl;
	for(int i = 0; i<4; i++)
	{
		if (obj._inventory[i] != NULL)
			_inventory[i] = obj._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}

	// Be careful with shallow copies. We are copying the pointers here not creating a new object for the constructor
	// Don't do this:
	// for(int i = 0; i<4; i++)
	// 	_inventory[i] = obj._inventory[i];
}

Character::Character(std::string name) : ICharacter(), _name(name)
{
	std::cout << "\033[31m[Character]\033[0m Constructor called on '" << this->_name << "'" << std::endl;
	for(int i = 0; i<4; i++)
		_inventory[i] = NULL;
}

// ################
// MEMBER FUNCTIONS
// ################

std::string const & Character::getName() const
{
	return(this->_name);
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while(i < 4)
	{
		if (this->_inventory[i] == NULL)
			break;
		i++;
	}
	if (i < 4)
	{
		std::cout << "\033[31m[Character]\033[0m Materia equipped" << std::endl;
		this->_inventory[i] = m;
	}
	else
		std::cout << "\033[31m[Character]\033[0m Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 4 || (this->_inventory[idx] == NULL))
		std::cout << "\033[31m[Character]\033[0m Could not find the item in inventory" << std::endl;
	else
	{
		this->_inventory[idx] = NULL;
		std::cout << "\033[31m[Character]\033[0m Item removed from inventory" << std::endl;
		// Now what do I do with the Materia that was there? Where can i save this not to have memory leaks?
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || (this->_inventory[idx] == NULL))
		std::cout << "\033[31m[Character]\033[0m Could not use the item - NOT in inventory" << std::endl;
	else
	{
		this->_inventory[idx]->use(target);
		std::cout << "\033[31m[Character]\033[0m Item used on target: " << target.getName() << std::endl;
		// Now what do I do with the Materia that was there? Where can i save this not to have memory leaks?
	}
}
