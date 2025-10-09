/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {

	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal& operator=(const AAnimal& other);
		AAnimal(const AAnimal &obj);

		AAnimal(std::string type);
		virtual void makeSound() const = 0;
		std::string getType() const;
		virtual void haveIdea(std::string text);
		virtual std::string checkLastIdea();

	private:

	protected:
		std::string	_type;

};

#endif
