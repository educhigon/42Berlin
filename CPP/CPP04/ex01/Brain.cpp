/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Brain.hpp"

// ##############
// CANONICAL FORM
// ##############

Brain::Brain()
{
	std::cout << "\033[36m[Brain]\033[0m Default Constructor called on '" << "'" << std::endl;
	int i = 0;
	while(i < 100)
		ideas[i++] = "";
}
Brain::~Brain()
{
	std::cout << "\033[36m[Brain]\033[0m Destructor called on '" << "'" << std::endl;
}
Brain& Brain::operator=(const Brain& other)
{
	std::cout << "\033[36m[Brain]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
			int i = -1;
			while(++i < 100)
				this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

// Better construction - best practice
Brain::Brain(const Brain &obj)
{
	std::cout << "\033[36m[Brain]\033[0m Copy constructor called" << std::endl;
	int i = -1;
	while(++i < 100)
		this->ideas[i] = obj.ideas[i];
}


// ################
// MEMBER FUNCTIONS
// ################

int Brain::createIdea(std::string text)
{
	int i = -1;
	while(++i < 100)
	{
		if (ideas[i] == "")
		{
			ideas[i] = text;
			return i;
		}
	}
	return -1;
}

std::string Brain::getLastIdea()
{
	int i = -1;
	std::string text;

	while(++i < 100)
	{
		if (ideas[i] == "")
			return text;
		text = ideas[i];
	}
	return text;
}
