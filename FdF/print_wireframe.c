/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wireframe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 11:47:35 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-27 11:47:35 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	print_points(t_vars *mlx_data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < mlx_data->map->rows)
	{
		j = 0;
		while (j < mlx_data->map->cols)
		{
			x = mlx_data->map->matrix[i][j].r_p
				* cos(mlx_data->map->matrix[i][j].theta_p)
				* mlx_data->screen_scale + 920 / 2;
			y = mlx_data->map->matrix[i][j].r_p
				* sin(mlx_data->map->matrix[i][j].theta_p)
				* mlx_data->screen_scale + 920 / 2;
			put_pixel(&mlx_data->img, x, y, mlx_data->map->matrix[i][j].color);
			j++;
		}
		i++;
	}
	return ;
}

void	print_lines(t_vars *mlx_data)
{
	int	i;
	int	j;
	int	points[6];

	i = 0;
	while (i < mlx_data->map->rows)
	{
		j = 0;
		while (j < mlx_data->map->cols)
		{
			get_points_and_draw(mlx_data, i, j, points);
			j++;
		}
		i++;
	}
	return ;
}
