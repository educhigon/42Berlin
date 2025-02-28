/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:09:59 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/06 16:13:38 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	check_corners(int x, int y, int col, int row)
{
	if (row == 1 && col == 1)
	{
		ft_putchar('/');
	}
	else if ((row == 1 && col == x) || (row == y && col == 1))
	{
		ft_putchar('\\');
	}
	else if (row == y && col == x)
	{
		ft_putchar('/');
	}
	else
	{
		ft_putchar('*');
	}
}

void	check_condition(int x, int y, int col, int row)
{
	if (col == 1 || col == x)
	{
		check_corners(x, y, col, row);
	}
	else if (row == 1 || row == y)
	{
		ft_putchar('*');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int		col;
	int		row;

	if (x <= 0 || y <= 0)
	{
		write(1, "Please include valid inputs", 28);
		ft_putchar('\n');
	}
	else
	{
		row = 1;
		while (row <= y)
		{
			col = 1;
			while (col <= x)
			{
				check_condition(x, y, col, row);
				col++;
			}
			ft_putchar('\n');
			row++;
		}
	}
}
