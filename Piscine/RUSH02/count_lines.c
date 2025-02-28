/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:54:29 by jkolosow          #+#    #+#             */
/*   Updated: 2024/10/20 19:39:02 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	print_error(void);

int	count_lines(char *pathname)
{
	char	c;
	int		br;
	int		fh;
	int		line_count;

	line_count = 0;
	fh = open(pathname, O_RDONLY);
	if (fh == -1)
		return (print_error());
	br = read(fh, &c, 1);
	while (br > 0)
	{
		if (c == '\n')
			line_count += 1;
		br = read(fh, &c, 1);
	}
	close(fh);
	if (br == -1)
		return (print_error());
	return (line_count);
}

/*
int	main(void)
{
	int		line_count;
	char pathname[] = "./numbers.dict";
	
	line_count = count_lines(pathname);
	printf("There are %d lines in '%s'.\n", line_count, pathname);
	return (0); 
}
*/
