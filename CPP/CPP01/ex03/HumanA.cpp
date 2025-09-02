/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:00:30 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/02 16:35:30 by edugonza         ###   ########.fr       */
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
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
