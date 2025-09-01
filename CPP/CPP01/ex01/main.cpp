/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/01 20:32:12 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie* zumb = new Zombie("Joe");
	int N = 7;
	Zombie* zumbHord = zombieHorde(N, "Ellie");

	zumb->announce();
	for (int i = 0; i < N; i++)
		zumbHord[i].announce();

	delete zumb;
	delete[] zumbHord;
}
