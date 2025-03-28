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

void	print_points(t_img *img, t_vars *mlx_data)
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
				* cos(mlx_data->map->matrix[i][j].theta_p) * mlx_data->screen_scale + 920 / 2;
			y = mlx_data->map->matrix[i][j].r_p
				* sin(mlx_data->map->matrix[i][j].theta_p) * mlx_data->screen_scale + 920 / 2;
			put_pixel(img, x, y, mlx_data->map->matrix[i][j].color);
			j++;
		}
		i++;
	}
	return ;
}

/*[dx \\ dy \\ sx \\ sy \\ err \\ e2 \\ x0 \\ y0]*/
void	draw_line(int *pts, t_img *img)
{
	int	helpers[8];
	int	steps;
	int	color_step;
	int	step_num;

	helpers[0] = abs(pts[3] - pts[0]);
	helpers[1] = abs(pts[4] - pts[1]);
	helpers[2] = 1 - 2 * (pts[0] > pts[3]);
	helpers[3] = 1 - 2 * (pts[1] > pts[4]);
	helpers[4] = helpers[0] - helpers[1];
	helpers[6] = pts[0];
	helpers[7] = pts[1];
	steps = (helpers[0] > helpers[1] ? helpers[0] : helpers[1]) + 1;
	color_step = (pts[5] - pts[2]) / steps;
	step_num = 0;
	while (helpers[6] != pts[3] || helpers[7] != pts[4])
	{
		put_pixel(img, helpers[6], helpers[7], pts[2] + (int)(color_step * step_num));
		helpers[5] = 2 * helpers[4];
		if (helpers[5] > -helpers[1])
		{
			helpers[4] = helpers[4] - helpers[1];
			helpers[6] += helpers[2];
		}
		if (helpers[5] < helpers[0])
		{
			helpers[4] = helpers[4] + helpers[0];
			helpers[7] += helpers[3];
		}
		step_num++;
	}
}

void	print_lines(t_img *img, t_vars *mlx_data)
{
	int	i;
	int	j;
	int	points[6];

	(void)img;
	i = 0;
	while (i < mlx_data->map->rows)
	{
		j = 0;
		while (j < mlx_data->map->cols)
		{
			build_point(mlx_data->map->matrix[i][j], points, mlx_data->screen_scale);
			if (j + 1 != mlx_data->map->cols)
			{
				build_point(mlx_data->map->matrix[i][j + 1], points + 3, mlx_data->screen_scale);
				draw_line(points, img);
			}
			if (i > 0)
			{
				build_point(mlx_data->map->matrix[i - 1][j], points + 3, mlx_data->screen_scale);
				draw_line(points, img);
			}
			j++;
		}
		i++;
	}
	return ;
}
