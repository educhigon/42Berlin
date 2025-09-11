/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:30:42 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/11 12:27:33 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int main(int ac, char** av)
{
	t_vars	mlx_data;

	if (input_checker(ac, av))
		return (1);
	if (init_mlx(&mlx_data))
		return (1);
	mlx_key_hook(mlx_data.win, handle_input, &mlx_data);
	mlx_hook(mlx_data.win, 17, 1L << 3, free_mlx, &mlx_data);
	mlx_loop(mlx_data.ptr);
	free_mlx(&mlx_data);
	return (0);
}
