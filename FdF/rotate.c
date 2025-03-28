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

void	spin(t_vars *mlx_data)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	phi;

	phi = (mlx_data->phi) * PI / 180.0;
	i = 0;
	while (i < mlx_data->map->rows)
	{
		j = 0;
		while (j < mlx_data->map->cols)
		{
			x = mlx_data->map->matrix[i][j].r_p * cos(mlx_data->map->matrix[i][j].theta_p);
			y = mlx_data->map->matrix[i][j].r_p * sin(mlx_data->map->matrix[i][j].theta_p);
			y = y * cos(phi) + mlx_data->map->matrix[i][j].value * mlx_data->height_scale * sin(phi);
			mlx_data->map->matrix[i][j].r_p = sqrt(x * x + y * y);
			mlx_data->map->matrix[i][j].theta_p = atan2(y, x);
			j++;
		}
		i++;
	}
	return ;
}

void reverse_rotation(t_map *map, t_vars *mlx_data)
{
    int i, j;
    double x1, y1, y2;

    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->cols)
        {
            x1 = map->matrix[i][j].r_p * cos(map->matrix[i][j].theta_p);
            y2 = map->matrix[i][j].r_p * sin(map->matrix[i][j].theta_p);
            y1 = (y2 - map->matrix[i][j].value * mlx_data->height_scale * sin(mlx_data->phi * PI / 180.0)) / cos(mlx_data->phi * PI / 180.0);
            map->matrix[i][j].r_p = sqrt(x1 * x1 + y1 * y1);
            map->matrix[i][j].theta_p = atan2(y1, x1) - mlx_data->theta * PI / 180.0;
            j++;
        }
        i++;
    }
}
