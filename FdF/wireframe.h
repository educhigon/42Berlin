/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:50:31 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/19 22:29:03 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIREFRAME_H
# define WIREFRAME_H

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>

// # include <mlx.h>
# include "Libft_power/ft_printf/ft_printf.h"
# include "libft.h"

typedef struct	s_img {
	void	*img_ptr;
	void	*img_pxl_ptr;
	char	bits_per_pixel;
	int	endian;
	int	line_len;
}				t_img;

typedef struct	s_vars {
	void	*ptr;
	void	*win;
	t_img	img;
}				t_vars;

//Main
int	main(int ac, char *av[]);

#endif
