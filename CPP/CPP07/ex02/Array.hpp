/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2026/03/16 21:44:35 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <iostream>

template <typename T>
class Array {

	private:
		size_t _size;
		T *_data;

	public:
		Array();
		Array(unsigned int n);

		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](const unsigned int index);
		~Array();
		size_t size() const;
};

#include "Array.tpp"

#endif
