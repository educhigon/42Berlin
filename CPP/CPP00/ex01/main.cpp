/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:39:01 by edugonza          #+#    #+#             */
/*   Updated: 2025/08/27 19:23:33 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook PB;
    std::string option;

	while(1)
	{
		std::cout << "Select your function: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, option);
		if (option == "ADD")
			PB.addContact();
		else if (option == "SEARCH")
			PB.searchContact();
		else if (option == "EXIT")
		{
			PB.exit();
			break;
		}
		else
			std::cout << "Unable to execute" << std::endl;
	}
	return 0;
}
