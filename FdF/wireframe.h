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

# include <stdio.h>
# include <math.h>
# define PI 3.141592654
// # include <mlx.h>
# include "Libft_power/ft_printf/ft_printf.h"
# include "libft.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pxl_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_vars
{
	void	*ptr;
	void	*win;
	t_img	img;
}				t_vars;

typedef struct s_pxl
{
	int				value;
	unsigned int	color;
	double			r_p;
	double			theta_p;
}				t_pxl;

typedef struct s_map
{
	t_pxl	**matrix;
	int		rows;
	int		cols;
}				t_map;

// Main
int		main(int ac, char *av[]);

// Utils
int		handle_input(int keysym, t_vars *mlx_data);
void	free_map(t_map *map);
int		free_mlx(t_vars *mlx_data);
int		input_checker(int ac, char *av[], t_map *map);
void	print_matrix(t_map *map);

// Print Wireframe
void	print_points(t_img *img, t_map *map);
void	print_lines(t_img *img, t_map *map);

// Print Wireframe Utils
void	put_pixel(t_img *img, int x, int y, int color);
void	build_point(t_pxl pxl, int *points);

// Set Map Utils
char	**get_clean_split(int fd);
void	fill_row_details(char **line_split, t_map *map, int i, int j);

// Set Map
int		build_map(char *filename, t_map *map);
void	free_map(t_map *map);

// Rotate
void	rotate_z(t_map *map, int angle);
void	spin(t_map *map, int angle);

#endif
