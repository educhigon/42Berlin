/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"MateriaSource.hpp"
#include	"AMateria.hpp"

// ##############
// CANONICAL FORM
// ##############

MateriaSource::MateriaSource() : IMateriaSource()
{
	std::cout << "\033[35m[MateriaSource]\033[0m Default Constructor called on " << std::endl;
	for(int i = 0; i<4; i++)
		_learnedBook[i] = NULL;
}
MateriaSource::~MateriaSource()
{
	std::cout << "\033[35m[MateriaSource]\033[0m Destructor called on " << std::endl;
	for(int i = 0; i<4; i++)
		delete _learnedBook[i];
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "\033[35m[MateriaSource]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for(int i = 0; i<4; i++)
		{
			delete _learnedBook[i];
			if (other._learnedBook[i] != NULL)
				_learnedBook[i] = other._learnedBook[i]->clone();
			else
				_learnedBook[i] = NULL;
			// Be careful with shallow copies. We are copying the pointers here not creating a new object for the constructor
			// Don't do this:
			// for(int i = 0; i<4; i++)
			// _learnedBook[i] = other._learnedBook[i];

		}
	}
	return (*this);
}

// Better construction - best practice
MateriaSource::MateriaSource(const MateriaSource &obj)
{
	std::cout << "\033[35m[MateriaSource]\033[0m Copy constructor called" << std::endl;
	for(int i = 0; i<4; i++)
	{
		if (obj._learnedBook[i] != NULL)
			_learnedBook[i] = obj._learnedBook[i]->clone();
		else
			_learnedBook[i] = NULL;
	}

	// Be careful with shallow copies. We are copying the pointers here not creating a new object for the constructor
	// Don't do this:
	// for(int i = 0; i<4; i++)
	// 	_learnedBook[i] = obj._learnedBook[i];

}

// ################
// MEMBER FUNCTIONS
// ################

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	while(i < 4)
	{
		if (this->_learnedBook[i] == NULL)
			break;
		i++;
	}
	// Be careful with shallow copies. We are copying the pointers here not creating a new object for the constructor
	// Don't do this:
	// this->_learnedBook[i] = m;

	if (i < 4)
		this->_learnedBook[i] = m->clone();
	else
		std::cout << "\033[35m[MateriaSource]\033[0m Learning Book is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while(i < 4)
	{
		if (this->_learnedBook[i] != NULL && this->_learnedBook[i]->getType() == type)
			break;
		i++;
	}
	if (i < 4)
		return (this->_learnedBook[i]->clone());
	else
		std::cout << "\033[35m[MateriaSource]\033[0m " << type << " not found in Learning Book"<< std::endl;
	return NULL;
}
