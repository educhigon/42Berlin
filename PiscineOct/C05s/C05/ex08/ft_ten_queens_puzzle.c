/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:17:30 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/17 11:48:42 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int place_queens(int matrix[10][10], int c, int r);

void print_matrix(int matrix[10][10])
{
	int	row;
	char	print;
	int col;

	row = 0;
	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			print = *(matrix[row][col] + '0');
			write(1, &print,1);
			col++;
		}
		write(1, "\0", 1);
		row++;
	}
}

void zero_matrix(int matrix[10][10])
{
	int	row;
	int col;

	row = 0;
	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			matrix[row][col] = 0;
			col++;
		}
		row++;
	}
}

int check_available_squares(int matrix[10][10])
{
	int	i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if(matrix[i][j] == 0) 
				return(1);
			j++;
		}
		i++;
	}
	return(0);
}

void mark_places_covered(int matrix[10][10], int row, int col)
{
	int p;
	int col_t;
	int row_t;

	p = 0;
	while(p < 10)
	{
		matrix[row][p] = 1;
		matrix[p][col] = 1;
		// while(col >= 0 && col <= 10 && row >=0 && row <=10)
		p++;
	}
	row_t = row;
	col_t = col;
	while(col >= 0 && row >=0)
		matrix[row--][col--] = 1;
	row = row_t;
	col = col_t;
	while(col <= 10 && row >=0)
		matrix[row--][col++] = 1;
	row = row_t;
	col = col_t;
	while(col >= 0 && row <=10)
		matrix[row++][col--] = 1;
	row = row_t;
	col = col_t;
	while(col <= 10 && row <=10)
		matrix[row++][col++] = 1;
	print_matrix(matrix);
}
void revert_places_covered(int matrix[10][10], int row, int col)
{
	int i;
	int j;

	matrix[row][col] = 0;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (matrix[i][j] == 1)
				matrix[i][j] = 0;
		j++;
		}
	i++;
	}

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (matrix[i][j] == 2)
				mark_places_covered(matrix, i, j);
		j++;
		}
	i++;
	}


}

int place_one_queen(int matrix[10][10], int col, int row)
{
	if(col == 10)
		col = 0;
	while (row < 10)
	{
		while (col < 10)
		{
			if(matrix[row][col] == 0) 
			{
				mark_places_covered(matrix, row, col);
				matrix[row][col] = 2;
				if(!place_queens(matrix, col, row))
					revert_places_covered(matrix, row, col);
			}
			col++;
		}
		row++;
	}
	return(0);
}


int place_queens(int matrix[10][10], int c, int r)
{
	int i;
	int j;
	int print;

	i = 0;
	if(place_one_queen(matrix, c, r))
		place_queens(matrix, c, r);
	else
		while(i < 10)
		{
			j = 0;
			while(j < 10)
			{
				if (matrix[i][j] == 2)
				{
					print = i + '0';
					write(1, &print, 1);
				}
				j++;
			}
			i++;
		}
	write(1, "\n", 1);
	return(0);

}

int ft_ten_queens_puzzle(void)
{
	int matrix[10][10];


	zero_matrix(matrix);
	place_queens(matrix, 0, 0);
	return(0);
}

int main()
{
	ft_ten_queens_puzzle();
	return(0);
}