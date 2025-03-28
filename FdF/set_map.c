/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-21 13:02:16 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-21 13:02:16 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

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

int	fill_rows(int fd, t_map *map)
{
	int		i;
	int		j;
	char	**line_split;

	i = 0;
	while (i < map->rows)
	{
		line_split = get_clean_split(fd);
		map->matrix[i] = malloc(map->cols * sizeof(t_pxl));
		if (map->matrix[i] == NULL)
			return (0);
		j = 0;
		while (j < map->cols)
		{
			fill_row_details(line_split, map, i, j);
			j++;
		}
		ft_split_free(line_split);
		i++;
	}
	get_clean_split(fd);
	return (1);
}

void	check_cols(int fd, t_map *map)
{
	int		i;
	int		j;
	char	**line_split;

	i = 0;
	map->cols = -1;
	while (i < map->rows)
	{
		line_split = get_clean_split(fd);
		j = 0;
		while (line_split[j] != NULL)
			j++;
		ft_split_free(line_split);
		if (map->cols != -1 && map->cols != j)
			map->cols = 0;
		else
			map->cols = j;
		i++;
		if (i % 10 == 0)
			ft_printf("[%d] map->cols: %d\n", i, map->cols);
	}
	get_clean_split(fd);
	return ;
}

int	build_map_stats(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	map->rows = count_lines(fd);
	close(fd);
	ft_printf("map->rows created: DONE || vallue: %d\n", map->rows);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	check_cols(fd, map);
	close(fd);
	ft_printf("map->cols created: DONE || vallue: %d\n", map->cols);
	if (map->rows == 0 || map->cols == 0)
		return (0);
	return (1);
}

int	build_map(char *filename, t_map *map)
{
	int		fd;

	map->matrix = NULL;
	if (!build_map_stats(filename, map))
		return (0);
	ft_printf("map stats created: DONE\n");
	ft_printf("map->rows: %d\n", map->rows);
	ft_printf("map->cols: %d\n", map->cols);
	map->matrix = malloc(map->rows * sizeof(t_pxl *));
	if (map->matrix == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!fill_rows(fd, map))
	{
		free_map(map);
		return (0);
	}
	close(fd);
	return (1);
}
