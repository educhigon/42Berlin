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

int	handle_close(t_vars *mlx_data)
{
	mlx_destroy_window(mlx_data->ptr, mlx_data->win);
	mlx_destroy_display(mlx_data->ptr);
	free(mlx_data->ptr);
	exit(1);
	return (0);
}

int	handle_input(int keysym, t_vars *mlx_data)
{
	if (keysym == XK_Escape)
		return (handle_close(mlx_data));
	ft_printf("You pressed %d\n", keysym);
	return(1);
}

void	build_image(int fd,  t_vars mlx_data)
{
	(void) fd;
	(void) mlx_data;
	// char **map_line;
	// int	i;

	// i = 0;
	// while(map_line[i] != NULL || i == 0)
	// {
	// 	map_line[i] = get_next_line(fd);
	// 	ft_printf("this is the line: %s \n", map_line);
	// 	i++;
	// }
	return ;
	// mlx_data.img.img_ptr = mlx_new_image(mlx_data.ptr, ft_strlen(map_line)*100, );
	// mlx_data.img.img_pxl_ptr =
	// 31m on video

}

int	free_mlx(t_vars *mlx_data)
{
	if (mlx_data->win != NULL)
		mlx_destroy_window(mlx_data->ptr, mlx_data->win);
	mlx_destroy_display(mlx_data->ptr);
	free(mlx_data->ptr);
	return (0);
}

int	input_checker(int ac, char *av[])
{
	char **file_ext;

	if (ac != 2)
		return (0);
	if (!ft_strchr(av[1], '.'))
			return (0);
	file_ext = ft_split(av[1], '.');
	if (file_ext[1] == NULL || ft_strcmp(file_ext[1],"fdf") != 0)
	{
		ft_split_free(file_ext);
		return (0);
	}
	ft_split_free(file_ext);
	return (1);
}
int	main(int ac, char *av[])
{
	t_vars mlx_data;
	int	fd;

	if(!input_checker(ac, av))
		return(0);

	mlx_data.ptr = mlx_init();
	if (mlx_data.ptr == NULL)
		return (0);

	mlx_data.win = mlx_new_window(mlx_data.ptr, 500, 400, "Main");
	if (mlx_data.win == NULL)
		return (free_mlx(&mlx_data));

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);

	build_image(fd, mlx_data);


	mlx_key_hook(mlx_data.win, handle_input, &mlx_data);
	mlx_hook(mlx_data.win, 17, 1L<<3, handle_close, &mlx_data);

	mlx_loop(mlx_data.ptr);
	free_mlx(&mlx_data);
	return(1);
}
