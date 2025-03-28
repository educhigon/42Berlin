/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-20 13:09:52 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-20 13:09:52 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

int	mouse_input(int button, int x, int y, t_vars *mlx_data)
{
	ft_printf("button: '%d'\n", button);
	if (button == 1 && mlx_data->dragging == 0)
	{
		mlx_data->dragging = 1;
		mlx_data->last_x = x;
		mlx_data->last_y = y;
	}
	else if (button == 4)
	{
		mlx_data->screen_scale *= 1.1;
		build_image(mlx_data);
	}
	else if (button == 5)
	{
		mlx_data->screen_scale /= 1.1;
		build_image(mlx_data);
	}
	else
		mlx_data->dragging = 0;
	return (0);
}

int	mouse_motion(int x, int y, t_vars *mlx_data)
{
	int	dx;
	int	dy;

	if (mlx_data->dragging == 1)
	{
		dx = x - mlx_data->last_x;
		if (dx / 10 != 0)
		{
			mlx_data->theta -= (int)(dx / 10);
			mlx_data->phi += 0;
			mlx_data->last_x = x;
			build_image(mlx_data);
		}
		dy = y - mlx_data->last_y;
		if (dy / 10 != 0)
		{
			mlx_data->theta += 0;
			mlx_data->phi += (int)(dy / 10);
			mlx_data->last_y = y;
			build_image(mlx_data);
		}
	}
	return (0);
}

int	handle_input(int keysym, t_vars *mlx_data)
{
	int	step;

	step = 5;
	if (keysym == XK_Escape)
		return (free_mlx(mlx_data));
	else
	{
		if (keysym == 65361)
			mlx_data->theta += -step;
		else if (keysym == 65362)
			mlx_data->phi += -step;
		else if (keysym == 65363)
			mlx_data->theta += step;
		else if (keysym == 65364)
			mlx_data->phi += step;
		build_image(mlx_data);
	}
	return (1);
}

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->rows)
	{
		if (map->matrix[i])
			free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	free(map);
	return ;
}

int	free_mlx(t_vars *mlx_data)
{
	if (mlx_data->img.img_ptr)
		mlx_destroy_image(mlx_data->ptr, mlx_data->img.img_ptr);
	if (mlx_data->win)
		mlx_destroy_window(mlx_data->ptr, mlx_data->win);
	if (mlx_data->ptr)
	{
		mlx_destroy_display(mlx_data->ptr);
		free(mlx_data->ptr);
	}
	if (mlx_data->map)
		free_map(mlx_data->map);
	exit(1);
	return (0);
}
