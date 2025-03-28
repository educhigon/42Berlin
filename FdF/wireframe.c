/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:50:14 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/19 23:00:40 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	build_image(t_vars *mlx_data, t_map *map)
{
	ft_printf("theta: %d\n", mlx_data->theta);
	ft_printf("phi: %d\n", mlx_data->phi);
	ft_printf("\nBuildImage!!\n");
	ft_memset(mlx_data->img.img_pxl_ptr, 0, 900 * mlx_data->img.line_len);
	rotate_z(map, mlx_data->theta);
	spin(map, mlx_data->phi);
	print_points(&mlx_data->img, map);
	print_lines(&mlx_data->img, map);
	mlx_put_image_to_window(mlx_data->ptr, mlx_data->win,
		mlx_data->img.img_ptr, 0, 0);
	return ;
}

int	init_mlx(t_vars *mlx_data)
{
	mlx_data->ptr = mlx_init();
	if (mlx_data->ptr == NULL)
		return (0);
	mlx_data->win = mlx_new_window(mlx_data->ptr, 1100, 1100, "Main");
	if (mlx_data->win == NULL)
		return (free_mlx(mlx_data));
	mlx_data->img.img_ptr = mlx_new_image(mlx_data->ptr, 900, 900);
	mlx_data->img.img_pxl_ptr = mlx_get_data_addr(mlx_data->img.img_ptr,
			&mlx_data->img.bits_per_pixel,
			&mlx_data->img.line_len,
			&mlx_data->img.endian);
	if (mlx_data->img.img_ptr == NULL)
		return (free_mlx(mlx_data));
	return (1);
}

int	main(int ac, char *av[])
{
	t_vars	mlx_data;
	
	if (!input_checker(ac, av, &mlx_data))
		return (0);
	if (!init_mlx(&mlx_data))
		return (0);
	// ft_printf("Line_len: %d \n SIDE_LEN: 300 \n bpp: %d \n endian: %d\n",
//  mlx_data.img.line_len, mlx_data.img.bits_per_pixel, mlx_data.img.endian);
	mlx_data.theta = (int)-30;
	mlx_data.phi = (int)(180+45);
	mlx_data.dragging = 0;

	build_image(&mlx_data, mlx_data.map);

	sleep(1);
	mlx_data.theta = (int)30;
	mlx_data.phi = (int)(-45);
	build_image(&mlx_data, mlx_data.map);

	// sleep(1);
	// mlx_data.theta = (int)-10;
	// mlx_data.phi = (int)0;
	// build_image(&mlx_data, mlx_data.map);

	// sleep(1);
	// mlx_data.theta = (int)-10;
	// mlx_data.phi = (int)0;
	// build_image(&mlx_data, mlx_data.map);

	// sleep(1);
	// mlx_data.theta = (int)0;
	// mlx_data.phi = (int)-60;
	// build_image(&mlx_data, mlx_data.map);

	// sleep(1);
	// mlx_data.theta = (int)45;
	// mlx_data.phi = (int)0;
	// build_image(&mlx_data, mlx_data.map);

	mlx_key_hook(mlx_data.win, handle_input, &mlx_data);
	mlx_hook(mlx_data.win, 17, 1L << 3, free_mlx, &mlx_data);
	
	mlx_mouse_hook(mlx_data.win, mouse_input, &mlx_data);
	mlx_hook(mlx_data.win, 6, 1L << 6, mouse_motion, &mlx_data);
	
	mlx_loop(mlx_data.ptr);
	free_mlx(&mlx_data);
	return (1);
}
