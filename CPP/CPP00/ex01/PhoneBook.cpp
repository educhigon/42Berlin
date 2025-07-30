/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:34:50 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/29 20:58:13 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	// Constructor implementation
};

PhoneBook::~PhoneBook() {
	// Destructor implementation
};

void PhoneBook::addContact() {

	newContact = setContactDetails(firstName, lastName, nickname, phoneNumber, darkestSecret);
	// Method to add a contact
};

void PhoneBook::searchContact() const {
	// Method to search for a contact by index
};

void PhoneBook::displayContacts() const {
	// Method to display all contacts
};

Contact::Contact() {
	// Constructor implementation
};

Contact::~Contact() {
	// Destructor implementation
};

Contact::setContactDetails() {
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
	Contact newContact;


};
