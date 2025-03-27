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

int	handle_input(int keysym, t_vars *mlx_data)
{
	if (keysym == XK_Escape)
		return (free_mlx(mlx_data));
	ft_printf("You pressed %d\n", keysym);
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
	exit(1);
	return (0);
}

int	input_checker(int ac, char *av[], t_map *map)
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
	if (!build_map(av[1], map))
	{
		if (map->matrix != NULL)
			free_map(map);
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
