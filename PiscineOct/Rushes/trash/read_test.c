/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehussein <ehussein@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:33:40 by ehussein          #+#    #+#             */
/*   Updated: 2024/10/19 12:52:26 by ehussein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int is_space(int c)
{
	return (c == ' ');
}

int is_colon(int c)
{
	return (c == ':');
}

int skip_spaces(int i, char *str)
{
	while (is_space(str[i]))
		i++;
	return (i);
}

int skip_colon(int i, char *str)
{
	while (is_colon(str[i]))
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	fh;
	int	cn;
	char	*pathname;
	char	buffer[21];
	int	i;
	char	save_num[40];
	char	num;

	num = *argv[1];
	pathname = "./test_numbers.dict";
	fh = open(pathname,O_RDONLY);
	while ((cn = read(fh, buffer, 20)))
	{
		buffer[cn] = '\0';
		// printf("'%s'\n", buffer);
		i = 0;
		while (buffer[i])

	if(argv[1][0] == '1' && argv[1][1] != '\0')
	{
			{
				if (buffer[i] == num)


	}





	pathname = "./test_numbers.dict";
	fh = open(pathname,O_RDONLY);
	while ((cn = read(fh, buffer, 20)))
	{
		buffer[cn] = '\0';
		// printf("'%s'\n", buffer);
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == num)
			{
				printf("buffer[i]: '%c'\n", buffer[i]);
				i++;
				printf("buffer[i+1]: '%s'\n", buffer+i);
				i = skip_spaces(i, buffer);
				i = skip_colon(i, buffer);
				i = skip_spaces(i, buffer);
				while(buffer[i] != '\0' && buffer[i] != '\n')
				{
					write(1, &buffer[i] ,1);
					i++;
				}
				if (buffer[i] == '\n')
					return (0);
				else
				{
					cn = read(fh, buffer, 20);
					buffer[cn] = '\0';
					i = 0;
					i = skip_spaces(i, buffer);
					i = skip_colon(i, buffer);
					i = skip_spaces(i, buffer);
					while(buffer[i] != '\n')
					{
						write(1,&buffer[i],1);
						i++;
					}
					return (0);
				}
			}
			i++;
		}
		//printf("%s", buffer);
	}
	close(fh);
	return (0);
}
