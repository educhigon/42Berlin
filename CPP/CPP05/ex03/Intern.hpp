/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

typedef struct tuple_s{
	std::string keyword;
	AForm* (*FormCreator) (std::string target);
} tuple_t;

class Intern {

	private:

	protected:

	public:
		Intern();
		~Intern();
		Intern& operator=(const Intern& other);
		Intern(const Intern &obj);

		AForm *makeForm(std::string formName, std::string target);

};

#endif
