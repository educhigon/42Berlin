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

void	rotate_z(t_vars *mlx_data)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx_data->map->rows)
	{
		j = 0;
		while (j < mlx_data->map->cols)
		{
			mlx_data->map->matrix[i][j].theta_p += mlx_data->theta * PI / 180;
			j++;
		}
		i++;
	}
	return ;
}

void	spin(t_vars *m)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	phi;

	phi = (m->phi) * PI / 180.0;
	i = 0;
	while (i < m->map->rows)
	{
		j = 0;
		while (j < m->map->cols)
		{
			x = m->map->matrix[i][j].r_p * cos(m->map->matrix[i][j].theta_p);
			y = m->map->matrix[i][j].r_p * sin(m->map->matrix[i][j].theta_p);
			y = y * cos(phi) + m->map->matrix[i][j].value
				* m->height_scale * sin(phi);
			m->map->matrix[i][j].r_p = sqrt(x * x + y * y);
			m->map->matrix[i][j].theta_p = atan2(y, x);
			j++;
		}
		i++;
	}
	return ;
}

void	reverse_rotation(t_vars *m)
{
	int		i;
	int		j;
	double	x1;
	double	y1;
	double	y2;

	i = 0;
	while (i < m->map->rows)
	{
		j = 0;
		while (j < m->map->cols)
		{
			x1 = m->map->matrix[i][j].r_p * cos(m->map->matrix[i][j].theta_p);
			y2 = m->map->matrix[i][j].r_p * sin(m->map->matrix[i][j].theta_p);
			y1 = (y2 - m->map->matrix[i][j].value * m->height_scale
					* sin(m->phi * PI / 180.0)) / cos(m->phi * PI / 180.0);
			m->map->matrix[i][j].r_p = sqrt(x1 * x1 + y1 * y1);
			m->map->matrix[i][j].theta_p = atan2(y1, x1)
				- m->theta * PI / 180.0;
			j++;
		}
		i++;
	}
}
