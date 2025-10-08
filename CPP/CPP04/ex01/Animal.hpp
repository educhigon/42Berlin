/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

	public:
		Animal();
		virtual ~Animal();
		Animal& operator=(const Animal& other);
		Animal(const Animal &obj);

		Animal(std::string type);
		virtual void makeSound() const;
		std::string getType() const;
		virtual void haveIdea(std::string text);
		virtual std::string checkLastIdea();

	private:

	protected:
		std::string	_type;

};

#endif
