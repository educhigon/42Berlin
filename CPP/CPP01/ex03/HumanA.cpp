/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:00:30 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 12:06:01 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{
	_name = name;
	std::cout << "HumanA: '" << _name << "' with weapon '" << _weapon.getType() << "' was created" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA: '" << _name << "' destroyed" << std::endl;
}

void HumanA::attack() const
{
	if(this->_weapon.getType() == "\0")
	{
		std::cout << _name << " attacks with their bare hands" << std::endl;
		return ;
	}
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
