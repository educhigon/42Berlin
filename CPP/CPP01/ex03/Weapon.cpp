/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:58:31 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/02 16:05:44 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
	std::cout << "Weapon '"<< _type <<"' created" << std::endl;
}
Weapon::~Weapon()
{
	std::cout << "Weapon destroyed" << std::endl;
}

std::string Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(std::string new_value)
{
	std::cout << "Changing Weapon type" << std::endl;
	_type = new_value;
}
