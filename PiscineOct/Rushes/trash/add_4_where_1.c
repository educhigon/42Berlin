/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_4_where_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:59:02 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/13 14:47:15 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void run_row_add_4_where_1(int **str, int *row_nbr, int row_add)
{
	int	i;

	i = 0;
	while(i < 4)
	{
		if (row_nbr[i] == 1)
			str[row_add][i] = 4;
	}
}

void run_col_add_4_where_1(int **str, int *col_nbr, int col_add)
{
	int	i;

	i = 1;
	while(i < 4)
	{
		if (col_nbr[i] == 1)
			str[i][col_add] = 4;
	}
}

void	 add_4_where_1(int **str, sid *rules)
{
	run_row_add_4_where_1(str, rules->top, 0);
	run_row_add_4_where_1(str, rules->bottom, 3);
	run_col_add_4_where_1(str, rules->left, 0);
	run_col_add_4_where_1(str, rules->right, 3);
}