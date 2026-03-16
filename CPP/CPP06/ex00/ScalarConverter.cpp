/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <math.h>

std::string define_type(std::string input)
{
	bool has_decimal = false;
	bool has_exp = false;
	bool is_float = false;

	if (input.length() == 1)
	{
		if (std::isdigit(input[0]))
			return ("int");
		return ("char");
	}
	else {
		for (size_t i = 0; i < input.length(); i++)
		{
			if(isdigit(input[i]))
				continue;
			else if (i == 0 && (input[i] == '-' || input[i] == '+'))
				continue;
			else if(input[i] == '.' && !has_decimal && i != input.length() - 1 && i != 0)
				has_decimal = true;
			else if(input[i] == 'e' && !has_exp && i != input.length() - 1 && i != 0)
				has_exp = true;
			else if(input[i] == 'f' && i == input.length() - 1)
				is_float = true;
			else
				return ("invalid");
		}
	}

	if (is_float)
	{
		if (has_decimal)
			return ("float");
		else
			return ("invalid");
	}
	else if (has_decimal || has_exp)
		return ("double");
	else
		return ("int");

}

void print_result(double res)
{
	try
	{
		if (std::isnan(res) || std::isinf(res) || res < 0 || res > 127)
			throw std::runtime_error("IMPOSSIBLE");
		if (!std::isprint(static_cast<char>(res)))
			throw std::runtime_error("Non displayable character");
		std::cout << "\033[32m[ScalarConverter]\033[0m char: '" << static_cast<char>(res) << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[32m[ScalarConverter]\033[0m char: '" << e.what() << "'" << std::endl;
	}

	try
	{
		if (std::isnan(res) || std::isinf(res))
			throw std::runtime_error("IMPOSSIBLE");
		if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max())
			throw std::runtime_error("IMPOSSIBLE"); // Out of limits for INT
		std::cout << "\033[32m[ScalarConverter]\033[0m int: '" << static_cast<int>(res) << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[32m[ScalarConverter]\033[0m int: '" << e.what() << "'" << std::endl;
	}

	try
	{
		if ((res < -std::numeric_limits<float>::max() + 1 || res > std::numeric_limits<float>::max()) && !std::isinf(res))
			throw std::runtime_error("IMPOSSIBLE"); // Out of limits for FLOAT
		std::cout << "\033[32m[ScalarConverter]\033[0m float: '" << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[32m[ScalarConverter]\033[0m float: '"  << e.what() << "'" << std::endl;
	}

	try
	{
		std::cout << "\033[32m[ScalarConverter]\033[0m double: '" << std::fixed << std::setprecision(1) << static_cast<double>(res) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[32m[ScalarConverter]\033[0m double: '"  << e.what() << "'" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& input)
{
	double res;
	std::string type;

	///////////////////////
	////// Check input
	///////////////////////
	if(input.empty())
		type = "invalid";

	for(int i = 0; input[i]; i++)
	{
		// std::cout << "input[" << i << "] = '" << input[i] << "' (ASCII: " << static_cast<int>(input[i]) << ")" << std::endl;
		if (!std::isprint(static_cast<unsigned char>(input[i])))
		{
			std::cout << "\033[32m[ScalarConverter]\033[0m INVALID CHARACTER '" << static_cast<int>(input[i]) << "'" << std::endl;
			return;
		}
	}


	///////////////////////
	////// Define type
	///////////////////////

	if (input == "nanf" || input == "+inff" || input == "-inff" || input == "inff")
	{
		type = "special";
		if (input[0] == 'n')
			res = std::numeric_limits<float>::quiet_NaN();
		else if (input[0] == '+' || input[0] == 'i')
			res = std::numeric_limits<float>::infinity();
		else
			res = -std::numeric_limits<float>::infinity();
	}
	else if (input == "nan" || input == "+inf" || input == "-inf" || input == "inf")
	{
		type = "special";
		if (input[0] == 'n')
			res = std::numeric_limits<double>::quiet_NaN();
		else if (input[0] == '+' || input[0] == 'i')
			res = std::numeric_limits<double>::infinity();
		else
			res = -std::numeric_limits<double>::infinity();
	}
	else
	{
		if (type != "invalid")
		type = define_type(input);
	}

	///////////////////////
	////// Convert depending on type
	///////////////////////

	if (type == "invalid")
	{
		std::cout << "\033[34m[ScalarConverter]\033[0m Invalid input" << std::endl;
		return;
	}
	else if (type == "char")
		res = static_cast<char>(input[0]);
	else
	{
		char *end;
		double value = strtod(input.c_str(), &end);

		if (type == "int")
		{
			if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
				res = value;
			else
				res = static_cast<int>(value);
		}
		else if (type == "float")
			res = static_cast<float>(value);
		else if (type == "double")
			res = value;
	}

	print_result(res);
}
