/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:11:07 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/08 21:12:34 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	std::cout << "-- TESTS 1 --" << std::endl;
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


	std::cout << "-- TESTS 2 --" << std::endl;
	std::cout << "-- Creating Array of Animals --" << std::endl;
	std::cout << std::endl;
	const int arr_size = 10;
	Animal* horde[arr_size];
	int k = 0;
	while(k < arr_size)
	{
		if(k % 2 == 0)
			horde[k] = new Cat();
		else
			horde[k] = new Dog();
		k++;
	}

	horde[0]->haveIdea("Meow during the night");

	std::cout << std::endl;
	std::cout << "-- Delete everyone --" << std::endl;

	while(k < arr_size)
		delete horde[k++];


	delete i;
	delete j;
	delete meta;
	delete j2;
	delete meta2;

	// Test deep copy
  {
      std::cout << "=== TEST: Deep Copy ===" << std::endl;

      Dog dog1;
			dog1.haveIdea("Bark during the night");

      Dog dog2 = dog1;  // Copy constructor
			dog2.haveIdea("Bark all night long");

      Dog dog3;
      dog3 = dog1;  // Assignment operator

			dog1.checkLastIdea();
			dog2.checkLastIdea();
			dog3.checkLastIdea();
      // Verify dog3 has INDEPENDENT brain
  }

	return 0;
}
