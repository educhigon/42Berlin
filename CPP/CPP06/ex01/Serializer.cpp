/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:53:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/10/07 11:47:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
