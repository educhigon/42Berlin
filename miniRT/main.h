/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:36:14 by edugonza          #+#    #+#             */
/*   Updated: 2025/09/11 12:34:31 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_h

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "Libft_power/libft.h"
# include "minilibx-linux/mlx.h"


# include <X11/keysym.h>
# include <fcntl.h>

# define PI 3.141592654
// # include <mlx.h>

typedef struct s_obj_A
{

}				t_obj_A;
typedef struct s_obj_C
{

}				t_obj_C;
typedef struct s_obj_L
{

}				t_obj_L;
typedef struct s_obj_sp
{

}				t_obj_sp;
typedef struct s_obj_pl
{

}				t_obj_pl;
typedef struct s_obj_cy
{

}				t_obj_cy;

typedef struct s_map
{
	t_obj_A A;
	t_obj_C C;
	t_obj_L L;
	t_obj_sp *sp_arr;
	t_obj_pl *pl_arr;
	t_obj_cy *cy_arr;
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
	void		*ptr;
	void		*win;
	t_img		img;
	t_map		*map;
	// int			dragging;
	// int			last_x;
	// int			last_y;
	// int			theta;
	// int			phi;
	// double		screen_scale;
	// double		height_scale;
}				t_vars;


int main(int ac, char** av);

int	input_checker(int ac, char *av[]);
int	init_mlx(t_vars *mlx_data);
int	handle_input(int keysym, t_vars *mlx_data);
int	free_mlx(t_vars *mlx_data);






#endif
