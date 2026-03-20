/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_4321_where_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:59:27 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/13 14:47:27 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void run_row_add_4321_where_4(int **str, int *row_nbr, int row_add)
{
	int	i;
	int j;

	i = 0;
	while(i < 4)
	{
		if (row_nbr[i] == 4)
		{
			if (row_add == 0)
			{
				j = 0;
				while(j <= 3)
				{
					str[j][i] = j;
					j++;
				}
			}
			else if (row_add == 3)
			{
				j = 3;
				while(j >= 0)
				{
					str[j][i] = 4 - j;
					j--;
				}
			}
		}
		i++;			
	}
}

void run_col_add_4321_where_4(int **str, int *col_nbr, int col_add)
{
	int	i;
	int j;

	i = 0;
	while(i < 4)
	{
		if (col_nbr[i] == 4)
		{
			if (col_add == 0)
			{
				j = 0;
				while(j <= 3)
				{
					str[i][j] = j;
					j++;
				}
			}
			else if (col_add == 3)
			{
				j = 3;
				while(j >= 0)
				{
					str[i][j] = 4 - j;
					j--;
				}
			}
		}
		i++;			
	}
}
void add_4321_where_4(int **str, sid *rules)
{
	run_row_add_4321_where_4(str, rules->top, 0);
	run_row_add_4321_where_4(str, rules->bottom, 3);
	run_col_add_4321_where_4(str, rules->left, 0);
	run_col_add_4321_where_4(str, rules->right, 3);
}
