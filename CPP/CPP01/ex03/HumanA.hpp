/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:00:22 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/02 17:19:53 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void attack() const;
	private:
		std::string _name;
		Weapon& _weapon;

	protected:

};

#endif
