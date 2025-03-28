/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:50:14 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/28 17:08:48 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	build_image(t_vars *mlx_data)
{
	ft_memset(mlx_data->img.img_pxl_ptr, 0, 900 * mlx_data->img.line_len);
	rotate_z(mlx_data);
	spin(mlx_data);
	print_points(mlx_data);
	print_lines(mlx_data);
	ft_printf("mlx_data.theta: %d\n", mlx_data->theta);
	ft_printf("mlx_data.phi: %d\n", mlx_data->phi - 180);
	printf("mlx_data.screen_scale: %.2f\n", mlx_data->screen_scale);
	printf("mlx_data.height_scale: %.2f\n", mlx_data->height_scale);
	mlx_put_image_to_window(mlx_data->ptr, mlx_data->win,
		mlx_data->img.img_ptr, (920 - 900) / 2, (920 - 900) / 2);
	reverse_rotation(mlx_data);
	return ;
}

int	init_mlx(t_vars *mlx_data)
{
	mlx_data->ptr = mlx_init();
	if (mlx_data->ptr == NULL)
		return (0);
	mlx_data->win = mlx_new_window(mlx_data->ptr, 920, 920, "Main");
	if (mlx_data->win == NULL)
		return (free_mlx(mlx_data));
	mlx_data->img.img_ptr = mlx_new_image(mlx_data->ptr, 900, 900);
	mlx_data->img.img_pxl_ptr = mlx_get_data_addr(mlx_data->img.img_ptr,
			&mlx_data->img.bits_per_pixel,
			&mlx_data->img.line_len,
			&mlx_data->img.endian);
	if (mlx_data->img.img_ptr == NULL)
		return (free_mlx(mlx_data));
	calculate_scales(mlx_data);
	return (1);
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

int	main(int ac, char *av[])
{
	t_vars	mlx_data;

	if (!input_checker(ac, av, &mlx_data))
		return (0);
	if (!init_mlx(&mlx_data))
		return (0);
	mlx_data.theta = (int)(-45);
	mlx_data.phi = (int)(180 + asin(1 / sqrt(3)) * 180.0 / PI);
	mlx_data.dragging = 0;
	build_image(&mlx_data);
	mlx_key_hook(mlx_data.win, handle_input, &mlx_data);
	mlx_hook(mlx_data.win, 17, 1L << 3, free_mlx, &mlx_data);
	mlx_mouse_hook(mlx_data.win, mouse_input, &mlx_data);
	mlx_hook(mlx_data.win, 6, 1L << 6, mouse_motion, &mlx_data);
	mlx_loop(mlx_data.ptr);
	free_mlx(&mlx_data);
	return (1);
}
