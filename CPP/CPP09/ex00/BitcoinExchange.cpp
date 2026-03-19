/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

// ##############
// CANONICAL FORM
// ##############

BitcoinExchange::BitcoinExchange() : exchange()
{
	std::cout << "\033[32m[BitcoinExchange]\033[0m Default Constructor called" << std::endl;
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "\033[32m[BitcoinExchange]\033[0m Destructor called on " << std::endl;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	std::cout << "\033[32m[BitcoinExchange]\033[0m Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->exchange = other.exchange;
		return(*this);
	}
	return (*this);
}

// Better construction - best practice
BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) : exchange(obj.exchange)
{
	std::cout << "\033[32m[BitcoinExchange]\033[0m Copy constructor called" << std::endl;
}

// ################
// MEMBER FUNCTIONS
// ################

void BitcoinExchange::load_exchange(std::string db)
{
	std::ifstream inputFile(db.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error opening file." << std::endl;
		throw std::invalid_argument("Error opening file");
		return;
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		size_t comma_pos = line.find(",");
		if (comma_pos == std::string::npos)
			throw std::logic_error("Error: not a positive number.");

		std::string date = line.substr(0, comma_pos);
		if (date == "date")
			continue;

		float value = atof(line.substr(comma_pos + 1, line.length()).c_str());
		// struct tm tm;
		// memset(&tm, 0, sizeof(tm));
		// if (sscanf(date.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday) != 3)
		// {
		// 	std::cerr << "Error parsing date" << std::endl;
		// 	throw std::invalid_argument("Error parsing date");
		// 	return;
		// }
		// exchange[mktime(&tm), value];
		this->exchange[date] = value;
	}
	std::map<std::string, float>::iterator it = this->exchange.end();
	--it; // Move the iterator back to the last element
	std::cout << "\033[32m -- Last data: [" << it->first << "] = " << it->second << " \033[0m" << std::endl;

	std::cout << "\033[32mFile sucessfully uploaded \033[0m" << std::endl;
	// Close the file
	inputFile.close();

}

void BitcoinExchange::check_prices(char* input)
{
	std::ifstream inputFile(input);
	if (!inputFile.is_open()) {
		std::cerr << "Error opening file." << std::endl;
		throw std::invalid_argument("Error opening file");
		return;
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		try
		{
			size_t comma_pos = line.find(",");
			if (comma_pos == std::string::npos)
				throw std::logic_error("Error: not a positive number.");

			std::string date = line.substr(0, comma_pos);
			if (date == "date")
				continue;
			float value = atof(line.substr(comma_pos + 1, line.length()).c_str());
			this->find_match(date, value);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\033[32mPrices sucessfully checked  \033[0m" << std::endl;
	// Close the file
	inputFile.close();

}

void BitcoinExchange::find_match(std::string date, float value)
{
	std::map<std::string, float>::iterator it = this->exchange.begin();
	while(it != this->exchange.end())
	{
		if (it->first == date)
			break;
		else if (it->first > date)
		{
			it--;
			break;
		}

		it++;
	}
	if (it == this->exchange.end())
		throw std::logic_error("Error: Bad input" + it->first);
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}
