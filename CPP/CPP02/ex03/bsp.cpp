/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:06:16 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/24 19:59:22 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool p_inside(Point const a, Point const b, Point const c, Point const point)
{
	if (a.get_x() - b.get_x() == 0)
	{
		if (c.get_x() > a.get_x() && point.get_x() > a.get_x())
			return true;
		else if (c.get_x() < a.get_x() && point.get_x() < a.get_x())
			return true;
		else
			return false;
	}
	else
	{
		Fixed m((a.get_y() - b.get_y()) / (a.get_x() - b.get_x()));
		Fixed t(b.get_y() - m * (b.get_x()));

		if ((c.get_y() - m * c.get_x() - t) * (point.get_y() - m * point.get_x() - t) > 0)
			return true;
		return false;
	}

}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

	if (p_inside(a,b,c,point) && p_inside(a,c,b,point) && p_inside(b,c,a,point))
		return true;
	return false;
}
