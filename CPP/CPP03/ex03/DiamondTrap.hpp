/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:22:43 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 17:32:43 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& other);
		DiamondTrap(const DiamondTrap &obj);

		DiamondTrap(std::string name);

		void attack(const std::string& target);
		void whoAmI(void);

	private:
		std::string _name;
	protected:

};

#endif
