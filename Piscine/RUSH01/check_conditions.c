/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conditions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:31:32 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/13 19:20:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"

int	check_left_row_visibility(int **grid, int row, int *expected)
{
	int	count;
	int	max_height;
	int	i;

	count = 1;
	max_height = grid[row][0];
	i = 1;
	while (i < 4)
	{
		if (grid[row][i] > max_height)
		{
			count++;
			max_height = grid[row][i];
		}
		i++;
	}
	return (count == expected[row]);
}

int	check_right_row_visibility(int **grid, int row, int *expected)
{
	int	count;
	int	max_height;
	int	i;

	count = 1;
	max_height = grid[row][3];
	i = 1;
	while (i < 4)
	{
		if (grid[row][3 - i] > max_height)
		{
			count++;
			max_height = grid[row][3 - i];
		}
		i++;
	}
	return (count == expected[row]);
}

int	check_top_col_visibility(int **grid, int col, int *expected)
{
	int	count;
	int	max_height;
	int	i;

	count = 1;
	max_height = grid[0][col];
	i = 1;
	while (i < 4)
	{
		if (grid[i][col] > max_height)
		{
			count++;
			max_height = grid[i][col];
		}
		i++;
	}
	return (count == expected[col]);
}

int	check_bottom_col_visibility(int **grid, int col, int *expected)
{
	int	count;
	int	max_height;
	int	i;

	count = 1;
	max_height = grid[3][col];
	i = 1;
	while (i < 4)
	{
		if (grid[3 - i][col] > max_height)
		{
			count++;
			max_height = grid[3 - i][col];
		}
		i++;
	}
	return (count == expected[col]);
}

int	is_valid_placement(int **grid, t_sid *constraints)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_top_col_visibility(grid, i, constraints->top))
		{
			return (0);
		}
		if (!check_bottom_col_visibility(grid, i, constraints->bottom))
		{
			return (0);
		}
		if (!check_left_row_visibility(grid, i, constraints->left))
		{
			return (0);
		}
		if (!check_right_row_visibility(grid, i, constraints->right))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
