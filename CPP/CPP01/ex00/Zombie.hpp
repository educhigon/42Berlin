/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:28:29 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/01 20:05:49 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
public:
		Zombie(const std::string &name);
		~Zombie();

		void announce (void)	const;

private:
	std::string _name;

protected:
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
