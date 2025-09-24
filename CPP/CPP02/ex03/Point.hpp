/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:54:48 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/23 22:47:25 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(Fixed x_f, Fixed y_f);
		~Point();
		Point(const Point &obj);
		Point& operator=(const Point& other);
		Fixed const get_x() const;
		Fixed const get_y() const;

	private:
		const Fixed x;
		const Fixed y;
	protected:
};


	bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
