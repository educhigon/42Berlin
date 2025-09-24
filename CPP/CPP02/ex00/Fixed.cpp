/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:08:23 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/23 15:54:16 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixed_point = other.getRawBits();
	return (*this);
}

// // Better construction - best practice
// Fixed::Fixed(const Fixed &obj) : _fixed_point(obj.getRawBits())
// {
// 	std::cout << "Copy constructor called" << std::endl;
// }

// Equal to subject:
Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point);
}

void Fixed::setRawBits( int const raw)
{
	_fixed_point = raw;
	return;
}
