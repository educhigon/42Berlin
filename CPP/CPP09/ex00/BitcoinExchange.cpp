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
#include <cstdlib> // atof
// #include <iomanip> // set_precision float
#include <ctime> // date check
#include <cstring> // date check


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


bool not_valid_date(const std::string &s) {
	struct tm tm;
	std::memset(&tm, 0, sizeof(tm));
	char *res = strptime(s.c_str(), "%Y-%m-%d", &tm);
	if (!res) return 1;
	time_t t = mktime(&tm);
	if (t == (time_t)-1) return 1;
	char buf[11];
	if (std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tm) == 0) return 1;
	// return std::string(buf) == s;
	return 0;
}

void check_input(std::string date, float value)
{
	if(not_valid_date(date))
		throw std::logic_error("Error: bad input (not a valid date) => " + date);
	if (value < 0)
		throw std::logic_error("Error: not a positive number.");
	if (value > 1000)
		throw std::logic_error("Error: too large a number");

}

void BitcoinExchange::find_match(std::string date, float value)
{
	check_input(date, value);
	std::map<std::string, float>::iterator it = this->exchange.lower_bound(date);

	// Define expected behavior: If in the past, throw exception or use first number regardless the distance (just comment the exception if)
	if (it == this->exchange.begin())
		it = it;
	// if (it == this->exchange.begin())
	// 	throw std::logic_error("Error: Date too early => " + date);

	// Define expected behavior: If in the future, throw exception or use latest number regardless the distance (just comment the exception if)
	// if (it == this->exchange.end())
	// 	throw std::logic_error("Error: Date too late => " + date);
	else if(it == this->exchange.end() || it->first > date)
		it--;
	// std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(1) << value * it->second << std::endl;
	std::cout << date << " => " << value << " = "  << value * it->second << std::endl;
}

char find_separator(std::string line)
{
	for (size_t i = 0; i < line.size(); ++i) {
		char c = line[i];
		if (std::isalnum(static_cast<unsigned char>(c)) == 0 && c != '-' && c != ' ')
			return c;
	}
	return 0;
}

std::string trim(std::string str)
{
	int start = 0;
	int lenght = str.size();
	bool word = false;

	for (size_t i = 0; i < str.size(); ++i) {
		char c = str[i];
		if (std::isspace(c) && !word)
			start++;
		else if (std::isspace(c) && word)
			lenght--;
		else
			word = true;
	}
	return str.substr(start, lenght);
}

std::map<std::string, float> parse_line(std::string line)
{
	char separator = find_separator(line);
	if (!separator)
		throw std::logic_error("Error: bad input (parsing fail) => " + line);
	size_t comma_pos = line.find(separator);
	std::map<std::string, float> res;

	if (comma_pos == std::string::npos)
		throw std::logic_error("Error: bad input (parsing fail) => " + line);

	std::string date = line.substr(0, comma_pos);
	date = trim(date);
	float value = 0;
	if (date != "date")
	{
		// std::cout << "date: '" << date << "'" << std::endl;
		std::string value_s = line.substr(comma_pos + 1, line.size());
		// std::cout << "value_s: '" << value_s << "'" << std::endl;
		for (size_t i = 0; i < value_s.size(); ++i) {
			char c = value_s[i];
			if (std::isdigit(static_cast<unsigned char>(c)) == 0 && c != '.' && c != ' ' && c != '-')
				throw std::logic_error("Error: bad input (parsing fail) => " + line);
		}
		value = atof(value_s.c_str());
	}
	res[date] = value;
	return(res);
}


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
		std::map<std::string, float> item = parse_line(line);
		if (item.begin()->first == "date")
			continue;
		this->exchange[item.begin()->first] = item.begin()->second;
	}
	std::map<std::string, float>::iterator it = this->exchange.end();
	--it; // Move the iterator back to the last element
	std::cout << "\033[33m -- Last data: [" << it->first << "] = " << it->second << " \033[0m" << std::endl;

	std::cout << "\033[33m -- File sucessfully uploaded \033[0m" << std::endl;
	std::cout << std::endl;
	// Close the file
	inputFile.close();

}

void BitcoinExchange::check_prices(std::string input)
{
	std::ifstream inputFile(input.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error opening file." << std::endl;
		throw std::invalid_argument("Error opening file");
		return;
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		try
		{
			if (line.find("date") != std::string::npos)
				continue;
			std::map<std::string, float> item = parse_line(line);
			this->find_match(item.begin()->first, item.begin()->second);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << std::endl;
	std::cout << "\033[32mPrices sucessfully checked  \033[0m" << std::endl;
	// Close the file
	inputFile.close();

}
