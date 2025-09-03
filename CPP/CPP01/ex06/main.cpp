/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/03 12:35:58 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av) {

	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac == 2)
	{
		int i = 0;
		while(i<4)
		{
			if (av[1] == levels[i])
				break;
			i++;
		}

		switch (i)
		{
		case 0:
 			harl.complain("DEBUG");
			std::cout << std::endl;
			//fall through
		case 1:
			harl.complain("INFO");
			std::cout << std::endl;
			//fall through
		case 2:
			harl.complain("WARNING");
			std::cout << std::endl;
			//fall through
		case 3:
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << std::endl;
		}
	}
	else
	{
		harl.complain("DEBUG");
		std::cout << std::endl;
		harl.complain("INFO");
		std::cout << std::endl;
		harl.complain("WARNING");
		std::cout << std::endl;
		harl.complain("ERROR");
		std::cout << std::endl;
	}

	return 0;
}
