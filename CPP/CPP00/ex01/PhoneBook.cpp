/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:34:50 by edugonza          #+#    #+#             */
/*   Updated: 2025/08/01 19:31:11 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	// Constructor implementation
};

PhoneBook::~PhoneBook() {
	// Destructor implementation
};

Contact::Contact(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber, const std::string &darkestSecret) {
	// const std::string &firstName = firstName;
	// const std::string &lastName = lastName;
	// const std::string &nickname = nickname;
	// const std::string &phoneNumber = phoneNumber;
	// const std::string &darkestSecret = darkestSecret;
};

Contact::~Contact() {
	// Destructor implementation
};

void PhoneBook::addContact() {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	std::cout << "Adding a new contact..." << std::endl;
	std::cout << "Please write the firstName of the contact " << std::endl;
	std::getline(std::cin, firstName);
	std::cout << "Please write the lastName of the contact " << std::endl;
	std::getline(std::cin, lastName);
	std::cout << "Please write the nickname of the contact " << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Please write the phoneNumber of the contact " << std::endl;
	std::getline(std::cin, phoneNumber);
	std::cout << "Please write the darkestSecret of the contact " << std::endl;
	std::getline(std::cin, darkestSecret);
	Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	
	if (contactCount < 8)
	{
		contacts[nextIndex] = newContact;
		contactCount++;
		nextIndex++;
	}
	else
	{
		if (nextIndex == 8)
			nextIndex = 0;
		contacts[nextIndex] = newContact;
		nextIndex++;
	}

};

void PhoneBook::searchContact() const {
	// Method to search for a contact by index
};

void PhoneBook::displayContacts() const {
	// Method to display all contacts
};
