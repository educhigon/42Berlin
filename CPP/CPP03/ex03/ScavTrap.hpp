/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:07:57 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 16:55:09 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
		// Orthodox Canonical Form
		ScavTrap();
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& other);
		ScavTrap(const ScavTrap &obj);

		ScavTrap(std::string name);
		void attack(const std::string& target);
		void guardGate();

	private:

	protected:

};

#endif
