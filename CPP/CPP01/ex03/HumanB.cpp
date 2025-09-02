/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:00:28 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/02 17:14:38 by edugonza         ###   ########.fr       */
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
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}
