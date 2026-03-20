/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_akash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:32:31 by akakumar          #+#    #+#             */
/*   Updated: 2024/10/13 16:24:40 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	check_row(int grid[4][4], int *constraints, int row);
int solve_grid(int grid[4][4], int *constraints);
void	print_grid(int grid[4][4])
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
	write(1, "\n", 1);

}


int	check_left_row_visibility(int grid[4][4], int row, int expected)
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
	return (count == expected);
}

int	check_right_row_visibility(int grid[4][4], int row, int expected)
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
	return (count == expected);
}

int	check_top_col_visibility(int grid[4][4], int col, int expected)
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
	return (count == expected);
}

int	check_bottom_col_visibility(int grid[4][4], int col, int expected)
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
	return (count == expected);
}

int	is_valid_placement(int grid[4][4], int *constraints)
{
	int	i;
	//printf("entering constraints check\n");
	// sleep(1);
	
	i = 0;
	while (i < 4)
	{
		if (!check_top_col_visibility(grid, i, constraints[i]))
		{
			//printf("Check top failed\n");
			return (0);
		}
		if (!check_bottom_col_visibility(grid, i, constraints[i + 4]))
		{
			//printf("Check bottom failed\n");
			return (0);
		}
		if (!check_left_row_visibility(grid, i, constraints[i + 8]))
		{
			//printf("Check left failed\n");
			return (0);
		}
		if (!check_right_row_visibility(grid, i, constraints[i + 12]))
		{
			//printf("Check right failed\n");
			return (0);
		}
		i++;
	}
	//printf("All checks passed\n");
	return (1);
}

int	check_col(int grid[4][4], int row, int col, int *constraints)
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
	print_grid(grid);
	sleep(1);
	grid[row][col] = 0;
	return (0);
}

int	check_row(int grid[4][4], int *constraints, int row)
{
	if (row == 4)
	{
		//printf("row = 4 NOW WE CHECK CONSTRAINTS\n");
		int i = is_valid_placement(grid, constraints);
		//printf("Result of check CONSTRAINTS: %d\n", i);
		return (i);
	}
	return (check_col(grid, row, 0, constraints));
}

int solve_grid(int grid[4][4], int *constraints)
{
	//printf("Starting solve grid\n");
	int i = check_row(grid, constraints, 0);
	//printf("Result of check row: %d\n", i);
	return (i);
}

int	*parse_input(char *str)
{
	int	*constraints;
	int	i;

	constraints = (int *)malloc(16 * sizeof(int));
	i = 0;
	while (i < 16)
	{
		if (str[i * 2] < '1' || str[i * 2] > '4')
		{
			free(constraints);
			return (NULL);
		}
		constraints[i] = str[i * 2] - '0';
		i++;
	}
	return (constraints);
}

void	initialize_grid(int grid[4][4])
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			grid[x][y] = 0;
			y++;
		}
		x++;
	}
}


int	con_constraints(char *input, int **constraints)
{
	*constraints = parse_input(input);
	if (!(*constraints))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		*constraints;
	int		grid[4][4];

	if (!con_constraints(argv[1], &constraints) && argc != 2)
	{
		return (1);
	}
	initialize_grid(grid);
	if (!solve_grid(grid, constraints))
	{
		free(constraints);
		return (1);
	}
	print_grid(grid);
	free(constraints);
	return (0);
}