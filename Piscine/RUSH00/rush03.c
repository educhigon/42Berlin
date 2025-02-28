/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:50:35 by jambatt           #+#    #+#             */
/*   Updated: 2024/10/06 15:50:40 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	check_condition(int x, int y, int col, int row)
{
	if (row == 1 || row == y)
	{
		if (col == 1)
		{
			ft_putchar('A');
		}
		else if (col == x)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
	}
	else if (col == 1 || col == x)
	{
		ft_putchar('B');
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
