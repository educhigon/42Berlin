/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbode <gbode@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:49:48 by gbode             #+#    #+#             */
/*   Updated: 2024/10/06 17:18:17 by gbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	check_condition(int x, int y, int col, int row);
void	final_row(int col, int x);
void	first_row(int col, int x);
void	middle_rows(int col, int x);

void	rush(int x, int y)
{
	int	col;
	int	row;

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

void	check_condition(int x, int y, int col, int row)
{
	if (row == 1)
	{
		first_row(col, x);
	}
	else if (row > 1 && row < y)
	{
		middle_rows(col, x);
	}
	else
	{
		final_row(col, x);
	}
}

void	first_row(int col, int x)
{
	if (col == 1)
	{
		ft_putchar('A');
	}
	else if (col > 1 && col < x)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar('C');
	}
}

void	middle_rows(int col, int x)
{
	if (col == 1 || col == x)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	final_row(int col, int x)
{
	if (col == 1)
	{
		ft_putchar('C');
	}
	else if (col > 1 && col < x)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar('A');
	}
}
