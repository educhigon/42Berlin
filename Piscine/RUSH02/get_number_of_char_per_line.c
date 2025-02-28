/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_char_per_line.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:54:19 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/20 19:57:44 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	zero_file_control(int *file_control, int nbr_lines);
int		is_number(char c);
int		count_lines(char *pathname);
char	*get_nbr_name(char *str);
void	write_num(char *nbr);
int		print_error(void);

char	*get_line_with_number(char *buffer, char *to_find, int buff_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < buff_size)
	{
		j = 0;
		if (buffer[i] == to_find[0])
		{
			while (to_find[j] != '\0')
			{
				if (buffer[i + j] != to_find[j])
					break ;
				else if (to_find[j + 1] == '\0' && is_number(buffer[i + j + 1]))
					break ;
				j++;
			}
			if (to_find[j] == '\0')
				return (buffer);
		}
		i++;
	}
	return (0);
}

int	*build_file_control(int nbr_lines, char *filepath)
{
	char	ch;
	int		fh;
	int		*file_control;
	int		i;

	file_control = malloc(sizeof(int) * (1 + nbr_lines));
	zero_file_control(file_control, nbr_lines);
	file_control[0] = nbr_lines;
	fh = open(filepath, O_RDONLY);
	i = 1;
	while (read(fh, &ch, 1))
	{
		if (ch != '\n')
			file_control[i]++;
		else
			i++;
	}
	close(fh);
	return (file_control);
}

void	null_termination_on_buffer(int *file_control, char *buffer, int i)
{
	int	j;

	j = 0;
	while (j < file_control[i] + 1)
	{
		if (buffer[j] == '\n')
			buffer[j] = '\0';
		j++;
	}
}

void	find_number(int *file_control, char *to_find, char *filepath)
{
	char	*buffer;
	int		i;
	int		fh;

	i = 1;
	fh = open(filepath, O_RDONLY);
	if (fh == -1)
		return ;
	while (i <= file_control[0])
	{
		buffer = malloc(sizeof(char) * (file_control[i] + 1));
		if (!buffer)
		{
			print_error();
			return ;
		}
		read(fh, buffer, file_control[i] + 1);
		null_termination_on_buffer(file_control, buffer, i);
		if (get_line_with_number(buffer, to_find, file_control[i]))
		{
			write_num(get_nbr_name(buffer));
			free(buffer);
			close(fh);
			return ;
		}
		free(buffer);
		i++;
	}
	close(fh);
	return ;
}

int	number_finder(char *to_find, char *pathname)
{
	int		line_count;
	int		*file_control;

	if (to_find)
	{
		line_count = count_lines(pathname);
		file_control = build_file_control(line_count, pathname);
		find_number(file_control, to_find, pathname);
		return (0);
	}
	print_error();
	return (1); 
}
