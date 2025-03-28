/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wireframe_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 12:38:41 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-27 12:38:41 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	offset;
	// ft_printf("I also got here\n");
	if (x > 0 && x < 900 && y > 0 && y < 900)
	{
		offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
		*((unsigned int *)(offset + img->img_pxl_ptr)) = color;
	}
	return ;	
}

void	build_point(t_pxl pxl, int *points, double screen_scale)
{
	// ft_printf("I got here\n");
	*points = (int)(pxl.r_p * cos(pxl.theta_p) * screen_scale  + 900 / 2);
	*(points + 1) = (int)(pxl.r_p * sin(pxl.theta_p) * screen_scale  + 900 / 2);
	return ;
}
