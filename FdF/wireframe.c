/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:50:14 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/19 15:58:52 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

int	handle_input(int keysym, t_vars *mlx_data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(mlx_data->ptr, mlx_data->win);
		mlx_destroy_display(mlx_data->ptr);
		free(mlx_data->ptr);
		exit(1);
	}
	ft_printf("You pressed %d\n", keysym);
	return(1);	
}
int	main(void)
{
	t_vars mlx_data;

	mlx_data.ptr = mlx_init();
	if (mlx_data.ptr == NULL)
		return (0);

	mlx_data.win = mlx_new_window(mlx_data.ptr, 500, 400, "Main");
	if (mlx_data.win == NULL)
	{
		mlx_destroy_display(mlx_data.ptr);
		free(mlx_data.ptr);
		return (0);
	}

	mlx_key_hook(mlx_data.win, handle_input, &mlx_data);
	mlx_loop(mlx_data.ptr);
	mlx_destroy_window(mlx_data.ptr, mlx_data.win);
	mlx_destroy_display(mlx_data.ptr);
	free(mlx_data.ptr);
	return(1);
}