/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:53:55 by edugonza          #+#    #+#             */
/*   Updated: 2025/02/28 11:40:08 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "get_next_line_utils.c"
#include <stdio.h>

char	*answer_line(char **main_buffer)
{
	char	*new_buffer;
	char	*cleaning_buffer;
	int		bl_pos;
	int		main_len;

	main_len = ft_strlen2(*main_buffer);
	bl_pos = (unsigned long)ft_strchr2(*main_buffer, '\n');
	if (ft_strchr2(*main_buffer, '\n') == -1)
	{
		new_buffer = *main_buffer;
		*main_buffer = NULL;
	}
	else
	{
		new_buffer = ft_substr(*main_buffer, 0, bl_pos + 1);
		cleaning_buffer = ft_substr(*main_buffer, bl_pos + 1,
				main_len - bl_pos - 1);
		free(*main_buffer);
		*main_buffer = cleaning_buffer;
		cleaning_buffer = NULL;
	}
	return (new_buffer);
}

int	go_to_end_of_line(char **main_buffer, int fd)
{
	char	*line;
	char	*new_buffer;
	int		bytes;
	int		i;

	i = 0;
	bytes = -1;
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (0);
	while (i++ < BUFFER_SIZE)
		line[i] = '\0';
	bytes = read(fd, line, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(line);
		return (bytes);
	}
	new_buffer = ft_strjoin(*main_buffer, line);
	free(line);
	free(*main_buffer);
	(*main_buffer) = new_buffer;
	new_buffer = NULL;
	return (1);
}

int	prepare_main_buffer(char **main_buffer, int fd, int bytes)
{
	int			i;

	i = -1;
	if (!(*main_buffer))
	{
		(*main_buffer) = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!(*main_buffer))
			return (0);
		while (i++ < BUFFER_SIZE)
			(*main_buffer)[i] = '\0';
	}
	while (ft_strchr2((*main_buffer), '\n') == -1)
	{
		bytes = go_to_end_of_line(main_buffer, fd);
		if (bytes == 0)
			break ;
		else if (bytes < 0)
		{
			free(*main_buffer);
			(*main_buffer) = NULL;
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*main_buffer;
	char		*ans_buffer;
	int			bytes;

	ans_buffer = NULL;
	if (fd < 0)
		return (NULL);
	bytes = 0;
	if (!prepare_main_buffer(&main_buffer, fd, bytes))
		return (NULL);
	if (main_buffer && *main_buffer != '\0')
		ans_buffer = answer_line(&main_buffer);
	else
	{
		free(main_buffer);
		main_buffer = NULL;
	}
	return (ans_buffer);
}
