/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:57:33 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/23 22:51:12 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(Fixed x_f, Fixed y_f) : x(x_f), y(y_f)
{
	// std::cout << "Default constructor called" << std::endl;
}
Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

// Point& Point::operator=(const Point& other)
// {
// 	std::cout << "Copy assignment operator called" << std::endl;
// 	// if (this != &other)
// 	// {
// 	// 	this->x = other.get_x();
// 	// 	this->y = other.get_y();
// 	// }
// 	return (*this);
// }

// Better construction - best practice
Point::Point(const Point &obj) : x(obj.x), y(obj.y)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed const Point::get_x() const
{
	return this->x;
}

Fixed const Point::get_y() const
{
	return this->y;
}
