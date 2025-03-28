/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 11:13:08 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-27 11:13:08 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

char	**get_clean_split(int fd)
{
	char	*line;
	char	*line2;
	char	**line_split;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	line2 = ft_strtrim(line, "\n, ");
	line_split = ft_split(line2, ' ');
	free(line);
	free(line2);
	return (line_split);
}

void	define_height_scale(t_vars *m, int min_val, int max_val)
{
	if (max_val - min_val == 0)
		m->height_scale = (double)(900 * 0.9 * 0.01);
	else
		m->height_scale = ((900 * 0.9 * 0.01) / (double)(max_val - min_val));
	if (m->height_scale > 1)
		m->height_scale = sqrt(m->height_scale);
	else
		while (m->height_scale > 0.2)
			m->height_scale = pow((m->height_scale), 1.2);
	return ;
}

void	find_height_scale(t_vars *mlx_data)
{
	int	i;
	int	j;
	int	min_val;
	int	max_val;

	min_val = mlx_data->map->matrix[0][0].value;
	max_val = min_val;
	i = 0;
	while (i < mlx_data->map->rows)
	{
		j = 0;
		while (j < mlx_data->map->cols)
		{
			if (mlx_data->map->matrix[i][j].value < min_val)
				min_val = mlx_data->map->matrix[i][j].value;
			if (mlx_data->map->matrix[i][j].value > max_val)
				max_val = mlx_data->map->matrix[i][j].value;
			j++;
		}
		i++;
	}
	define_height_scale(mlx_data, min_val, max_val);
	return ;
}

void	calculate_scales(t_vars *mlx_data)
{
	double	diagonal;

	mlx_data->screen_scale = 1;
	mlx_data->height_scale = 1;
	diagonal = sqrt(mlx_data->map->cols * mlx_data->map->cols
			+ mlx_data->map->rows * mlx_data->map->rows);
	mlx_data->screen_scale = 900 * 0.9 / diagonal;
	find_height_scale(mlx_data);
	return ;
}
