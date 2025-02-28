/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:27:25 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/15 10:10:32 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"
#include <stdlib.h>
#include <unistd.h>

int		fill_missing_numbers(int **grid, int row);
int		check_row(int **grid, t_sid *constraints, int row);
int		is_valid_placement(int **grid, t_sid *constraints);
void	print_matrix(int **matrix);

void	new_matrix(int **matrix)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		*(matrix[i / 4] + (i % 4)) = 0;
		i++;
	}
}

int	check_col(int **grid, int row, int col, t_sid *constraints)
{
	int	num;
	int	i;

	if (col == 4)
		return (check_row(grid, constraints, row + 1));
	num = 1;
	while (num <= 4)
	{
		i = 0;
		while (i < 4 && grid[row][i] != num && grid[i][col] != num)
			i++;
		if (i == 4)
		{
			grid[row][col] = num;
			if (check_col(grid, row, col + 1, constraints))
				return (1);
		}
		num++;
	}
	grid[row][col] = 0;
	return (0);
}

int	check_row(int **grid, t_sid *constraints, int row)
{
	if (row == 4)
	{
		return (is_valid_placement(grid, constraints));
	}
	return (check_col(grid, row, 0, constraints));
}

int	solve_grid(int **grid, t_sid *constraints)
{
	return (check_row(grid, constraints, 0));
}

void	matrix_initializer(t_sid *rules)
{
	int	i;
	int	**matrix;

	matrix = (int **)malloc(4 * sizeof(int *));
	i = 0;
	while (i < 4)
	{
		matrix[i] = (int *)malloc(4 * sizeof(int));
		i++;
	}
	new_matrix(matrix);
	if (!solve_grid(matrix, rules))
	{
		write(1, "Erro!\n", 6);
	}
	else
		print_matrix(matrix);
}
