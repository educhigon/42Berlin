/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wireframe_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 12:38:41 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-27 12:38:41 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x > 0 && x < 900 && y > 0 && y < 900)
	{
		offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
		*((unsigned int *)(offset + img->img_pxl_ptr)) = color;
	}
	return ;
}

void	build_point(t_pxl pxl, int *points, double screen_scale)
{
	*points = (int)(pxl.r_p * cos(pxl.theta_p) * screen_scale + 920 / 2);
	*(points + 1) = (int)(pxl.r_p * sin(pxl.theta_p) * screen_scale + 920 / 2);
	*(points + 2) = (int)(pxl.color);
	return ;
}

void	fill_helper(int *helper, int *pts)
{
	int	steps;

	helper[0] = abs(pts[3] - pts[0]);
	helper[1] = abs(pts[4] - pts[1]);
	helper[2] = 1 - 2 * (pts[0] > pts[3]);
	helper[3] = 1 - 2 * (pts[1] > pts[4]);
	helper[4] = helper[0] - helper[1];
	helper[6] = pts[0];
	helper[7] = pts[1];
	if (helper[0] > helper[1])
		steps = helper[0] + 1;
	else
		steps = helper[1] + 1;
	helper[8] = (pts[5] - pts[2]) / steps;
	return ;
}

/*helper = [dx \\ dy \\ sx \\ sy \\ err \\ e2 \\ x0 \\ y0 \\ c_step]*/
void	draw_line(int *pts, t_img *img)
{
	int	helper[9];
	int	step;

	fill_helper(helper, pts);
	step = 0;
	while (helper[6] != pts[3] || helper[7] != pts[4])
	{
		put_pixel(img, helper[6], helper[7], pts[2] + (int)(helper[8] * step));
		helper[5] = 2 * helper[4];
		if (helper[5] > -helper[1])
		{
			helper[4] = helper[4] - helper[1];
			helper[6] += helper[2];
		}
		if (helper[5] < helper[0])
		{
			helper[4] = helper[4] + helper[0];
			helper[7] += helper[3];
		}
		step++;
	}
}

void	get_points_and_draw(t_vars *mlx_data, int i, int j, int *points)
{
	build_point(mlx_data->map->matrix[i][j], points, mlx_data->screen_scale);
	if (j + 1 != mlx_data->map->cols)
	{
		build_point(mlx_data->map->matrix[i][j + 1], points + 3,
			mlx_data->screen_scale);
		draw_line(points, &mlx_data->img);
	}
	if (i > 0)
	{
		build_point(mlx_data->map->matrix[i - 1][j], points + 3,
			mlx_data->screen_scale);
		draw_line(points, &mlx_data->img);
	}
	return ;
}
