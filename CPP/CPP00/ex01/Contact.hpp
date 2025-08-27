/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:55:53 by edugonza          #+#    #+#             */
/*   Updated: 2025/08/27 19:06:53 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
public:
		Contact();
		Contact(
			const std::string &firstName,
			const std::string &lastName,
			const std::string &nickname,
			const std::string &phoneNumber,
			const std::string &darkestSecret);
		~Contact();

		void displayContact() const;
		void displayContactSummary() const;

private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;


protected:
};

#endif
