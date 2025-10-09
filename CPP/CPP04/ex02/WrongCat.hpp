/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/09 14:11:07 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal {

	public:
		WrongCat();
		virtual ~WrongCat();
		WrongCat& operator=(const WrongCat& other);
		WrongCat(const WrongCat &obj);

		void makeSound() const;
		void haveIdea(std::string text);
		std::string checkLastIdea();

	private:
		Brain *brain;
	protected:

};

#endif
