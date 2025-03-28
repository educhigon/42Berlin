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

int mouse_input(int button, int x, int y, t_vars *mlx_data)
{
	if (button == 1)
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

int mouse_motion(int x, int y, t_vars *mlx_data)
{
	int dx;
	int dy;
	// ft_printf("-->x: %d\n", x);
	// ft_printf("-->y: %d\n", y);
	// ft_printf("-->last_x: %d\n", mlx_data->last_x);
	// ft_printf("-->last_y: %d\n", mlx_data->last_y);
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
	int step;

	step = 5;
	ft_printf("You pressed %d\n", keysym);
	if (keysym == XK_Escape)
		return (free_mlx(mlx_data));
	if (keysym == 65361)  // Left arrow
	{
		mlx_data->theta += -step;  // Rotate counterclockwise
		mlx_data->phi += 0;  // Rotate counterclockwise
		build_image(mlx_data);
	}
	else if (keysym == 65362)  // Up arrow
	{
		mlx_data->phi += -step;    // Tilt up
		mlx_data->theta += 0;  // Rotate clockwise
		build_image(mlx_data);
	}
	else if (keysym == 65363)  // Right arrow
	{
		mlx_data->theta += step;  // Rotate clockwise
		mlx_data->phi += 0;  // Rotate counterclockwise
		build_image(mlx_data);
	}
	else if (keysym == 65364)  // Down arrow
	{
		mlx_data->phi += step;    // Tilt down
		mlx_data->theta += 0;  // Rotate clockwise
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

int	input_checker(int ac, char *av[], t_vars *mlx_data)
{
	char	**file_ext;

	if (ac != 2)
		return (0);
	if (!ft_strchr(av[1], '.'))
		return (0);
	file_ext = ft_split(av[1], '.');
	if (file_ext[1] == NULL || ft_strcmp(file_ext[1], "fdf") != 0)
	{
		ft_split_free(file_ext);
		return (0);
	}
	ft_split_free(file_ext);
	mlx_data->map = malloc (sizeof(t_map));
	if (mlx_data->map == NULL)
		return (0);
	if (!build_map(av[1], mlx_data->map))
	{
		if (mlx_data->map->matrix != NULL)
			free_map(mlx_data->map);
		free(mlx_data->map);
		return (0);
	}
	return (1);
}

void	print_matrix(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			printf("| %.2f | %.2f | %d -- ", map->matrix[i][j].theta_p,
				map->matrix[i][j].r_p, map->matrix[i][j].value);
			j++;
		}
		printf("\n\n");
		i++;
	}
	return ;
}
