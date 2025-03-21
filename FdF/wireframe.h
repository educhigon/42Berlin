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
	char	*img_pxl_ptr;
	int	bits_per_pixel;
	int	endian;
	int	line_len;
}				t_img;

typedef struct	s_vars {
	void	*ptr;
	void	*win;
	t_img	img;
}				t_vars;

typedef struct s_pxl {
	int value;
	unsigned int color;
} t_pxl;

typedef struct s_map {
	t_pxl **matrix;
	int rows;
	int cols;
} t_map;

// Main
int	main(int ac, char *av[]);

// Utils
int	handle_close(t_vars *mlx_data);
int	handle_input(int keysym, t_vars *mlx_data);
int	free_mlx(t_vars *mlx_data);
int	input_checker(int ac, char *av[]);

// Set Map
int	build_map(char *filename, t_map *map);
void	free_map(t_map *map);

#endif
