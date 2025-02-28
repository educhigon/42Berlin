/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:13:09 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/13 19:51:20 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_matrix(int **matrix)
{
	int		row;
	int		columns;
	char	digit;

	row = 0;
	while (row < 4)
	{
		columns = 0;
		while (columns < 4)
		{
			digit = matrix[row][columns] + '0';
			write (1, &digit, 1);
			if (columns != 3)
				write (1, " ", 1);
			columns++;
		}
		write(1, "\n", 1);
		row++;
	}
}
