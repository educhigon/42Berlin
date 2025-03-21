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

void	put_pixel(t_img *img, int x, int y, int color)
{
	int offset;
	// ft_printf("here\n");
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pxl_ptr)) = color;
}

void	print_image(t_img *img)
{
	int x;
	int y;

	y = 10;
	while (y < 300)
	{
		x = 10;
		if (y == 10 || y == 299)
		{
			while (x < 300)
			{
				put_pixel(img, x, y, 0xffffff);
				x++;
			}
		}
		put_pixel(img, x, y, 0xffffff);
		y++;
	}
	return ;
}


void	build_image(t_vars *mlx_data)
{

	// read file and check it's a rectangle
	// build matrix with all the points
	// find the center of the image based on length and width of the map
	
	// Printing
	// print points on screen
	// draw lines for each point

	// Rotate
	// calculate for each point the associated theta
	// multiply the x and y by the cos(theta) and save in the new matrix
	// go to printing


	// char **map_line;
	// int	i;

	// i = 0;
	// while(map_line[i] != NULL || i == 0)
	// {
	// 	map_line[i] = get_next_line(fd);
	// 	ft_printf("this is the line: %s \n", map_line);
	// 	i++;
	// }
	// return ;
	// mlx_data.img.img_ptr = mlx_new_image(mlx_data.ptr, ft_strlen(map_line)*100, i*100);
	print_image(&mlx_data->img);
	mlx_put_image_to_window(mlx_data->ptr, mlx_data->win, mlx_data->img.img_ptr, 0, 0);
	return ;
}


int	main(int ac, char *av[])
{
	t_vars mlx_data;
	t_map	map;

	if(!input_checker(ac, av))
		return(0);
	ft_printf("input check: DONE\n");
	mlx_data.ptr = mlx_init();
	if (mlx_data.ptr == NULL)
		return (0);
	
	ft_printf("mlx data created: DONE\n");
	if (!build_map(av[1], &map))
	{
		free_map(&map);
		free_mlx(&mlx_data);
		return (0);
	}

	mlx_data.win = mlx_new_window(mlx_data.ptr, 700, 600, "Main");
	if (mlx_data.win == NULL)
		return (free_mlx(&mlx_data));
		
	mlx_data.img.img_ptr = mlx_new_image(mlx_data.ptr, 300, 300);
	mlx_data.img.img_pxl_ptr = mlx_get_data_addr(mlx_data.img.img_ptr, 
		&mlx_data.img.bits_per_pixel,
		&mlx_data.img.line_len, 
		&mlx_data.img.endian);
		
	// ft_printf("Line_len: %d \n SIDE_LEN: 300 \n bpp: %d \n endian: %d\n", mlx_data.img.line_len, mlx_data.img.bits_per_pixel, mlx_data.img.endian);
	
	build_image(&mlx_data);
	free_map(&map);
	mlx_key_hook(mlx_data.win, handle_input, &mlx_data);
	mlx_hook(mlx_data.win, 17, 1L<<3, free_mlx, &mlx_data);
	mlx_loop(mlx_data.ptr);
	free_mlx(&mlx_data);
	return(1);
}
