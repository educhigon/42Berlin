/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> // atof
#include <ctime> // date check
#include <cstring> // date check

class BitcoinExchange {

	private:
		std::map<std::string, float> exchange;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);
		BitcoinExchange(const BitcoinExchange &obj);

		void load_exchange(std::string db);
		void check_prices(std::string db);
		void find_match(std::string date, float value);
};


#endif
