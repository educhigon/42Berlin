/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:53:00 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/11 12:27:25 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


void	free_map(t_map *map)
{
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
	return (0);
}

int validate_map(char **av)
{
// TODO: Map validation for each element
	return(0);
}

int	input_checker(int ac, char *av[])
{
	char	**file_ext;

	if (ac != 2)
	{
		perror("No file found");
		return (1);
	}
	if (!ft_strchr(av[1], '.'))
	{
		perror("File not supported");
		return (1);
	}
	file_ext = ft_split(av[1], '.');
	if (file_ext[1] == NULL || ft_strcmp(file_ext[1], "rt") != 0)
	{
		ft_split_free(file_ext);
		perror("File not supported");
		return (1);
	}
	ft_split_free(file_ext);
	if(validate_map(av[1]))
	{
		perror("Not a valid map");
		return (1);
	}
	return (0);
}
int	init_mlx(t_vars *mlx_data)
{
	mlx_data->ptr = mlx_init();
	if (mlx_data->ptr == NULL)
	{
		perror("mlx not correctly initialized");
		return (1);
	}
	mlx_data->win = mlx_new_window(mlx_data->ptr, 920, 920, "Main");
	if (mlx_data->win == NULL)
	{
		perror("mlx not correctly initialized");
		free_mlx(mlx_data);
		return (1);
	}
	mlx_data->img.img_ptr = mlx_new_image(mlx_data->ptr, 900, 900);
	mlx_data->img.img_pxl_ptr = mlx_get_data_addr(mlx_data->img.img_ptr,
			&mlx_data->img.bits_per_pixel,
			&mlx_data->img.line_len,
			&mlx_data->img.endian);
	if (mlx_data->img.img_ptr == NULL)
	{
		perror("mlx not correctly initialized");
		free_mlx(mlx_data);
		return (1);
	}
	// calculate_scales(mlx_data);
	return (0);
}

int	handle_input(int keysym, t_vars *mlx_data)
{
	ft_printf("\n## New Key Pressed ##\n");
	ft_printf("keysym: '%d'\n", keysym);
	if (keysym == XK_Escape)
		return (free_mlx(mlx_data));
	return (1);
}
