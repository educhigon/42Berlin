/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:11:07 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 20:01:03 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	std::cout << "-- TESTS --" << std::endl;
	std::cout << "-- Creating Animals --" << std::endl;
	std::cout << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << "Type of i: " << i->getType() << " " << std::endl;
	std::cout << "Type of j: " << j->getType() << " " << std::endl;
	std::cout << "i making sound: ";
	i->makeSound(); //will output the cat sound!
	std::cout << "j making sound: ";
	j->makeSound();
	std::cout << "meta making sound: ";
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "-- Creating Animals --" << std::endl;
	std::cout << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongCat();
	std::cout << std::endl;
	std::cout << "Type of j: " << j2->getType() << " " << std::endl;
	std::cout << "j2 making sound: ";
	j2->makeSound();
	std::cout << "meta2 making sound: ";
	meta2->makeSound();

	std::cout << std::endl;
	std::cout << "-- END OF TESTS --" << std::endl;
	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;
	delete j2;
	delete meta2;

	return 0;
}
