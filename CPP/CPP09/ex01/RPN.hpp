/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <deque>

class RPN {

	private:
		std::deque<char> _items;

	protected:

	public:
		RPN();
		~RPN();
		RPN& operator=(const RPN& other);
		RPN(const RPN &obj);

		RPN(std::deque<char> items);
		double evaluate();
};

RPN* check_save_input(std::string input);

#endif
