/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:00:23 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/02 16:39:22 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		~HumanB();

		void attack() const;
		void setWeapon(Weapon& weapon);
	private:
		std::string _name;
		Weapon* _weapon;

	protected:

};


#endif
