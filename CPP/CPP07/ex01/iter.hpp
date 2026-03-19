/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2026/03/16 21:44:35 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

// Explicit template instantiations
template <typename T>
void iter(T* arr, const size_t size, void (*ptr)(T&)) {
	for (size_t i = 0; i < size; i++)
		ptr(arr[i]);
}

template <typename T>
void iter(T* arr, const size_t size, void (*ptr)(const T&)) {
	for (size_t i = 0; i < size; i++)
		ptr(arr[i]);
}

// Overloads for function objects (functors)
template <typename T, typename Func>
void iter2(T* arr, const size_t size, Func ptr) {
	for (size_t i = 0; i < size; i++)
		ptr(arr[i]);
}

#endif
