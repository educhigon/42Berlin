/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:28:29 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/01 20:45:01 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
public:
		Zombie(const std::string &name);
		Zombie();
		~Zombie();

		void announce (void)	const;
		void setName(const std::string &name);
private:
	std::string _name;

protected:
};

Zombie* zombieHorde( int N, std::string name );

#endif
