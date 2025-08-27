/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:34:50 by edugonza          #+#    #+#             */
/*   Updated: 2025/08/27 19:26:22 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	// Constructor implementation
	contactCount = 0;
	nextIndex = 0;

	std::cout << "PhoneBook created!" << std::endl;
	return;
}

PhoneBook::~PhoneBook() {
	// Destructor implementation
	std::cout << "PhoneBook destroyed!" << std::endl;
	return;
}

void PhoneBook::addContact() {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	std::cout << "Adding a new contact..." << std::endl;

	std::cout << "Please write the firstName of the contact " << std::endl;
	std::getline(std::cin, firstName);
	while(firstName.empty()) {
		std::cout << "First name cannot be empty. Please enter a valid first name: " << std::endl;
		std::getline(std::cin, firstName);
	}

	std::cout << "Please write the lastName of the contact " << std::endl;
	std::getline(std::cin, lastName);
	while(lastName.empty()) {
		std::cout << "Last name cannot be empty. Please enter a valid last name: " << std::endl;
		std::getline(std::cin, lastName);
	}

	std::cout << "Please write the nickname of the contact " << std::endl;
	std::getline(std::cin, nickname);
	while(nickname.empty()) {
		std::cout << "Nickname cannot be empty. Please enter a valid nickname: " << std::endl;
		std::getline(std::cin, nickname);
	}

	std::cout << "Please write the phoneNumber of the contact " << std::endl;
	std::getline(std::cin, phoneNumber);
	while(phoneNumber.empty()) {
		std::cout << "Phone number cannot be empty. Please enter a valid Phone number: " << std::endl;
		std::getline(std::cin, phoneNumber);
	}

	std::cout << "Please write the darkestSecret of the contact " << std::endl;
	std::getline(std::cin, darkestSecret);
	while(darkestSecret.empty()) {
		std::cout << "Darkest Secret cannot be empty. Please enter a valid Darkest Secret: " << std::endl;
		std::getline(std::cin, darkestSecret);
	}

	Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);

	if (contactCount < 8)
	{
		contacts[nextIndex] = newContact;
		contactCount++;
		nextIndex++;
	}
	else
	{
		if (nextIndex % 8 == 0)
			nextIndex = 0;
		contacts[nextIndex] = newContact;
		nextIndex++;
	}

}

void PhoneBook::searchContact() const {
	std::string index;

	std::cout << "     Index|First Name| Last Name|  Nickname|" << std::endl;
	for(int i = 0; i < 8; i++) {
		std::cout << "         " << i << "|";
		contacts[i].displayContactSummary();
	}

	std::cout << "Please select the index of the contact you'd like to see" << std::endl;
	std::getline(std::cin, index);
	while(index.empty() || index.length() > 1 || index[0] < '0' || index[0] > '7') {
		if (index == "EXIT") {
			std::cout << "Exiting search." << std::endl;
			return;
		}
		std::cout << "Invalid index. Please enter a valid index or 'EXIT' to cancel " << std::endl;
		std::getline(std::cin, index);
	}
	contacts[index[0] - '0'].displayContact();
}

void PhoneBook::exit() const {
	std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
}
