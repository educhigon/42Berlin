/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:00:28 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 12:02:43 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL)
{
	_name = name;
	std::cout << "HumanB: '" << _name << "' with no weapon was created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB: '" << _name << "' destroyed" << std::endl;
}

void HumanB::attack() const
{
	if(this->_weapon == NULL)
	{
		std::cout << _name << " attacks with their bare hands" << std::endl;
		return ;
	}
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
	std::cout << _name << " now has " << _weapon->getType() << std::endl;
}
