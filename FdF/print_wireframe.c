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

void	print_points(t_img *img, t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			x = map->matrix[i][j].r_p
				* cos(map->matrix[i][j].theta_p) * 10 + 900 / 2;
			y = map->matrix[i][j].r_p
				* sin(map->matrix[i][j].theta_p) * 10 + 900 / 2;
			put_pixel(img, x, y, 0xffffff);
			j++;
		}
		i++;
	}
	return ;
}

void	draw_line(int *pts, t_img *img)
{
	double	delta;
	int		dy;
	int		dx;

	if (pts[2] == pts[0])
	{
		dy = 0;
		while (pts[1] + dy != pts[3])
		{
			dy += 1 - 2 * (pts[1] + dy >= pts[3]);
			put_pixel(img, pts[0], pts[1] + dy, 0xffffff);
		}
	}
	else
	{
		delta = ((double)(pts[3] - pts[1]) / (double)(pts[2] - pts[0]));
		dx = 0;
		while (pts[0] + dx != pts[2])
		{
			dx += 1 - 2 * (pts[0] + dx >= pts[2]);
			put_pixel(img, pts[0] + dx, pts[1] + delta * abs(dx), 0xffffff);
		}
	}
	return ;
}

void	print_lines(t_img *img, t_map *map)
{
	int	i;
	int	j;
	int	points[4];

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			build_point(map->matrix[i][j], points);
			if (j + 1 != map->cols)
				build_point(map->matrix[i][j + 1], points + 2);
			if (j + 1 != map->cols)
				draw_line(points, img);
			if (i > 0)
				build_point(map->matrix[i - 1][j], points + 2);
			if (i > 0)
				draw_line(points, img);
			j++;
		}
		i++;
	}
	return ;
}
