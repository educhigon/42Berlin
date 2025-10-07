/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:45:09 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 17:32:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap();
		~FragTrap();
		FragTrap& operator=(const FragTrap& other);
		FragTrap(const FragTrap &obj);

		FragTrap(std::string name);
		void attack(const std::string& target);
		void highFivesGuys(void);

	private:

	protected:

};

#endif
