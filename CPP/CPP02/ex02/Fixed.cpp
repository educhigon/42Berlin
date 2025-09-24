/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:08:23 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 14:36:53 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int v) : _fixed_point(0)
{
	const int pow = 1 << _num_bits;
	_fixed_point = roundf(v * pow);
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float v) : _fixed_point(0)
{
	const int pow = 1 << _num_bits;
	_fixed_point = roundf(v * pow);
	std::cout << "Float constructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
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
	// std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point);
}

void Fixed::setRawBits( int const raw)
{
	_fixed_point = raw;
	return;
}

float Fixed::toFloat(void) const
{
	const int pow = 1 << _num_bits;
	return((float)this->getRawBits() / pow);
}

int Fixed::toInt(void) const
{
	const int pow = 1 << _num_bits;
	return(roundf((float)this->getRawBits() / pow));
}

// Operations
bool Fixed::operator>(const Fixed& other)
{
	if (this->getRawBits() > other.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator>=(const Fixed& other)
{
	if (this->getRawBits() >= other.getRawBits())
		return (1);
	return (0);

}

bool Fixed::operator<(const Fixed& other)
{
	if (this->getRawBits() < other.getRawBits())
		return (1);
	return (0);

}

bool Fixed::operator<=(const Fixed& other)
{
	if (this->getRawBits() <= other.getRawBits())
		return (1);
	return (0);

}

bool Fixed::operator==(const Fixed& other)
{
	if (this->getRawBits() == other.getRawBits())
		return (1);
	return (0);

}

bool Fixed::operator!=(const Fixed& other)
{
	if (this->getRawBits() != other.getRawBits())
		return (1);
	return (0);

}

Fixed Fixed::operator+(const Fixed& other)
{
	Fixed a;
	a.setRawBits(this->getRawBits() + other.getRawBits());
	return(a);
}

Fixed Fixed::operator-(const Fixed& other)
{
	Fixed a;
	a.setRawBits(this->getRawBits() - other.getRawBits());
	return(a);
}

Fixed Fixed::operator*(const Fixed& other)
{
	const int pow = 1 << _num_bits;
	double res = this->getRawBits() * other.getRawBits() / pow;
	Fixed a;
	a.setRawBits((float)res);
	return(a);
}

Fixed Fixed::operator/(const Fixed& other)
{
	const int pow = 1 << _num_bits;
	Fixed a;
	a.setRawBits(this->toFloat() / other.toFloat() * (float)pow);
	return(a);
}

Fixed& Fixed::operator++()
{
	const int pow = 1 << _num_bits;
	this->_fixed_point += pow;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	const int pow = 1 << _num_bits;
	Fixed a = *this;
	this->_fixed_point += pow;
	return(a);
}

Fixed& Fixed::operator--()
{
	const int pow = 1 << _num_bits;
	this->_fixed_point -= pow;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	const int pow = 1 << _num_bits;
	Fixed a = *this;
	this->_fixed_point -= pow;
	return(a);
}

Fixed& Fixed::min(Fixed& fp1, Fixed& fp2)
{
	if(fp1 < fp2)
		return(fp1);
	return(fp2);
}

const Fixed& Fixed::min(const Fixed& fp1, const Fixed& fp2)
{
	if(fp1.getRawBits() < fp2.getRawBits())
		return(fp1);
	return(fp2);
}

Fixed& Fixed::max(Fixed& fp1, Fixed& fp2)
{
	if(fp1 > fp2)
		return(fp1);
	return(fp2);
}

const Fixed& Fixed::max(const Fixed& fp1, const Fixed& fp2)
{
	if(fp1.getRawBits() > fp2.getRawBits())
		return(fp1);
	return(fp2);
}
