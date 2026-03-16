/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 15:42:24 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct Data {
	std::string str;
	int age;
} Data;

class Serializer {

	private:
		Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif
