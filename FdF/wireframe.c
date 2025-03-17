/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:50:14 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/17 15:37:31 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

int	main(void)
{
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (0);

	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return(1);
}