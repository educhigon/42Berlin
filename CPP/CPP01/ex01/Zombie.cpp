/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:28:06 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/01 20:45:37 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name)
{
	_name = name;
}
Zombie::Zombie(void)
{
}

Zombie::~Zombie()
{
	std::cout << "Zombie '" << _name << "' destroyed" << std::endl;
}

void Zombie::announce (void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

void Zombie::setName(const std::string &name)
{
	_name = name;
}
