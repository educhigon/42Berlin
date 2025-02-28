/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:09:59 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/06 15:50:54 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	check_condition(int x, int y, int col, int row)
{
	if (col == 1 || col == x)
	{
		if (row == 1 || row == y)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('|');
		}
	}
	else if (row == 1 || row == y)
	{
		ft_putchar('-');
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
