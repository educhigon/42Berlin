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

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->rows)
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	return;
}

void check_cols(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	*line2;
	char	**line_split;

	i = 0;
	map->cols = -1;
	while (i < map->rows)
	{
		line = get_next_line(fd);
		line2 = ft_strtrim(line, "\n, ");
		line_split = ft_split(line2, ' ');
		free(line);
		free(line2);
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
	line = get_next_line(fd);
	free(line);
	return;
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

int	fill_rows(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	*line2;
	char	**line_split;
	char	**num_split;
	
	i = 0;
	while (i < map->rows)
	{
		line = get_next_line(fd);
		line2 = ft_strtrim(line, "\n, ");
		line_split = ft_split(line2, ' ');
		free(line);
		free(line2);
		map->matrix[i] = malloc(map->cols * sizeof(t_pxl));
		if (map->matrix[i] == NULL)
			return (0);
		j = 0;
		while (j < map->cols)
		{
			if (ft_strchr(line_split[j], ',') != 0)
			{
				num_split = ft_split(line_split[j], ',');
				map->matrix[i][j].value = ft_atoi(num_split[0]);
				map->matrix[i][j].color = ft_atoi_base(ft_strlowcase(num_split[1]+2), "0123456789abcdef");
				ft_split_free(num_split);
			}
			else
			{
				map->matrix[i][j].value = ft_atoi(line_split[j]);
				map->matrix[i][j].color = 0x00000f;
			}
			ft_printf("map->matrix[%d][%d]: %d \n", i, j, map->matrix[i][j].value);
			ft_printf("map->matrix[%d][%d]: %d \n", i, j, map->matrix[i][j].color);
			j++;
		}
		ft_split_free(line_split);
		i++;
	}
	line = get_next_line(fd);
	free(line);
	return (1);
}

void	print_matrix(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while(i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			ft_printf("%d ", map->matrix[i][j].value);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return;
}


int	build_map(char *filename, t_map *map)
{
	int		fd;

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
		/*free everything and return */
	}
	close(fd);
	print_matrix(map);

	return (1);
}