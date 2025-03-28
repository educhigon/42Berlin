/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-26 11:33:02 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-26 11:33:02 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	rotate_z(t_map *map, int angle)
{
	int		i;
	int		j;

	i = 0;

	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			map->matrix[i][j].theta_p += angle * PI / 180;
			j++;
		}
		i++;
	}
	return ;
}

void	spin(t_map *map, int angle)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	phi;

	phi = (angle) * M_PI / 180.0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			x = map->matrix[i][j].r_p * cos(map->matrix[i][j].theta_p);
			y = map->matrix[i][j].r_p * sin(map->matrix[i][j].theta_p);
			y = y * cos(phi) + map->matrix[i][j].value * sin(phi);
			map->matrix[i][j].r_p = sqrt(x * x + y * y);
			map->matrix[i][j].theta_p = atan2(y, x);
			j++;
		}
		i++;
	}
	return ;
}
