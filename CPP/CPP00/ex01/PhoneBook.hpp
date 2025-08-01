/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:35:08 by edugonza          #+#    #+#             */
/*   Updated: 2025/08/01 18:31:12 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

class PhoneBook {
public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContact() const;
		void displayContacts() const;
private:
		Contact contacts[8];
		int contactCount;
		int nextIndex;

protected:
};

class Contact {
public:
		Contact(
			const std::string &firstName,
			const std::string &lastName,
			const std::string &nickname,
			const std::string &phoneNumber,
			const std::string &darkestSecret);
		~Contact();
		// Contact setContactDetails(

		void displayContact() const;
		void displayContactSummary() const;

private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;


protected:
};

#endif
