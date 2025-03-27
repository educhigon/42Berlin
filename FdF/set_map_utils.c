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

void	fill_row_details(char **line_split, t_map *map, int i, int j)
{
	char	**num_split;

	if (ft_strchr(line_split[j], ',') != 0)
	{
		num_split = ft_split(line_split[j], ',');
		map->matrix[i][j].value = ft_atoi(num_split[0]);
		map->matrix[i][j].color = ft_atoi_base(
				ft_strlowcase(num_split[1] + 2), "0123456789abcdef");
		ft_split_free(num_split);
	}
	else
	{
		map->matrix[i][j].value = ft_atoi(line_split[j]);
		map->matrix[i][j].color = 0xffffff;
	}
	map->matrix[i][j].r_p = sqrt(pow((j + 0.5 - map->cols / 2), 2)
			+ pow((i + 0.5 - map->rows / 2), 2));
	map->matrix[i][j].theta_p
		= atan2((map->rows / 2 - i - 0.5), (j + 0.5 - map->cols / 2));
	return ;
}
