/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:50:31 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/28 14:51:51 by edugonza         ###   ########.fr       */
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
	t_map	*map;
	int		dragging;
	int		last_x;
	int		last_y;
	int		theta;
	int		phi;
	double		screen_scale;
	double		height_scale;
}				t_vars;



// Main
int		main(int ac, char *av[]);
void	build_image(t_vars *mlx_data);

// Utils
int		handle_input(int keysym, t_vars *mlx_data);
int		mouse_motion(int x, int y, t_vars *vars);
int		mouse_input(int button, int x, int y, t_vars *vars);

void	free_map(t_map *map);
int		free_mlx(t_vars *mlx_data);
int		input_checker(int ac, char *av[], t_vars *mlx_data);

void	print_matrix(t_map *map);

// Print Wireframe
void	print_points(t_img *img, t_vars *mlx_data);
void	print_lines(t_img *img, t_vars *mlx_data);

// Print Wireframe Utils
void	put_pixel(t_img *img, int x, int y, int color);
void	build_point(t_pxl pxl, int *points, double screen_scale);

// Set Map Utils
char	**get_clean_split(int fd);
void	fill_row_details(char **line_split, t_map *map, int i, int j);
void 	calculate_scales(t_vars *mlx_data);

// Set Map
int		build_map(char *filename, t_map *map);
void	free_map(t_map *map);

// Rotate
void	spin(t_vars *mlx_data);
void	rotate_z(t_vars *mlx_data);
void	reverse_rotation(t_map *map, t_vars *mlx_data);

#endif
