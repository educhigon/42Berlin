/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:55:43 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/02 14:39:27 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon();

		std::string getType() const;
		void setType(std::string new_value);
	private:
		std::string _type;

	protected:

};

# endif
