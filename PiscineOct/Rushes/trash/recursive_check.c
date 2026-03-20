/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:21:49 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/13 14:49:05 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int check_sudoku_conditions(int num, int **str, int row, int col)
{
	int i;
	printf("row: %d", row);
	printf("col: %d", col);
	printf("num: %d", num);
	i = 0;
	while(i < 4)
	{
		printf("\n str :%d ", str[row][i]);
		if (str[row][i] == num && i != col)
			return(0);
		i++;
	}
	i = 0;
	while(i < 4)
	{
		printf("\n str :%d ", str[i][col]);
		if (str[i][col] == num && i != row)
			return(0);
		i++;
	}
	printf("I gt  here");
	return(1);
}

int check_sides_conditions_bottom(int i, int **str, int *arr, int col)
{
	int visibility;
	int max_h;

	max_h = str[0][col];
	i = 4;
	visibility = 1;
	while(i > 0)
	{
		if (str[i][col] > max_h)
		{
			max_h = str[i][col];
			visibility++; 
		}
		i--;
	}

	if (arr[col] == visibility)
		return(1);
	else
		return(0);
}

int check_sides_conditions_right(int i, int **str, int *arr, int row)
{
	int visibility;
	int max_h;

	max_h = str[row][0];
	i = 4;
	visibility = 1;
	while(i > 0)
	{
		if (str[row][i] > max_h)
		{
			max_h = str[row][i];
			visibility++; 
		}
		i--;
	}

	if (arr[row] == visibility)
		return(1);
	else
		return(0);
}

int check_sides_conditions_left(int i, int **str, int *arr, int row)
{
	int visibility;
	int max_h;

	max_h = str[row][0];
	i = 0;
	visibility = 1;
	while(i < 4)
	{
		if (str[row][i] > max_h)
		{
			max_h = str[row][i];
			visibility++; 
		}
		i++;
	}

	if (arr[row] >= visibility)
	{
		return(1);
	}
	else
		return(0);
}

int check_sides_conditions_top(int i, int **str, int *arr, int col)
{
	int visibility;
	int max_h;

	max_h = str[0][0];
	i = 1;
	visibility = 1;
	while(i < 4)
	{
		if (str[i][col] > max_h)
		{
			max_h = str[i][col];
			visibility++; 
		}
		i++;
	}

	if (arr[col] == visibility)
		return(1);
	else
		return(0);
}

int recursive_check(int **str, Rules rules, int row, int col)
{
	int i;
	int pos[2];
	int check_sudoku;
	int check_left;
	int check_right;
	int check_top;
	int check_bottom;
	pos[0] = row;
	pos[1] = col;

	i = 0;

	int result;
	result = 0;
	i = 1;
	if (row == 3 && col == 3)
		return(1);
	else
	{
		while(i <= 4)
		{
			str[row][col] = i;
			print_matrix(str);
			printf("\n");
			sleep(1);
			check_sudoku = check_sudoku_conditions(i, str, row, col);
			printf("\nSudoku: %d", check_sudoku);
			check_left = check_sides_conditions_left(i, str, rules.col_left, row);
			check_right = check_sides_conditions_right(i, str, rules.col_right, row);
			check_top = check_sides_conditions_top(i, str, rules.row_top, col);
			check_bottom = check_sides_conditions_bottom(i, str, rules.row_bottom, col);
			//printf("\nSudoku: %d, Bottom: %d, Left: %d, Right: %d, Top: %d \n", check_bottom, check_left, check_right, check_top, check_sudoku);
			//if (check_bottom && check_left && check_right && check_top && check_sudoku)
			if (check_sudoku)
			{
				if(col == 3)
				{
					if(row < 3)
						row++;
					col = 0;
				}	
				else
					col++;

				printf("\nstarting recursive on pointer + 1: \n");
				result = recursive_check(str, rules, row, col);
			}
			i++;
		}
	}
	if (result)
		return(1);
	else
	{
		str[pos[0]][pos[1]] = 0;
		return(0);	
	}

}
