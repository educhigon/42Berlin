/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:21:39 by edugonza          #+#    #+#             */
/*   Updated: 2025/08/27 19:29:34 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	// Default constructor implementation
}

Contact::Contact(
	const std::string &firstName,
	const std::string &lastName,
	const std::string &nickname,
	const std::string &phoneNumber,
	const std::string &darkestSecret) {

	first_name = firstName;
	last_name = lastName;
	nick_name = nickname;
	phone_number = phoneNumber;
	darkest_secret = darkestSecret;
}

Contact::~Contact() {
	// Destructor implementation
}

void Contact::displayContact() const {
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nick_name << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

void Contact::displayContactSummary() const {
	std::string summary;
	std::string field;

	field = "";
	if (first_name.length() > 10) {
		field += first_name.substr(0, 9) + ".";
	} else {
		while(field.length() + first_name.length() < 10)
			field += " ";
		field += first_name;
	}
	summary += field;
	summary += "|";

	field = "";
	if (last_name.length() > 10) {
		field += last_name.substr(0, 9) + ".";
	} else {
		while(field.length() + last_name.length() < 10)
			field += " ";
		field += last_name;
	}
	summary += field;
	summary += "|";

	field = "";
	if (nick_name.length() > 10) {
		field += nick_name.substr(0, 9) + ".";
	} else {
		while(field.length() + nick_name.length() < 10)
			field += " ";
		field += nick_name;
	}
	summary += field;
	summary += "|";

	std::cout << summary << std::endl;
}
