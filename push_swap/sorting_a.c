/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-21 12:07:26 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-21 12:07:26 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_moves_back(int *a_a, int *a_b, int size_a, int size_b)
{
	int				i_a;
	unsigned int	d;
	int				i;
	int				i_smallest;

	i = 0;
	i_a = -1;
	d = 0;
	i_smallest = 0;
	while (i < size_a && size_b)
	{
		if (a_a[i] > a_b[0] && (d == 0 || (unsigned int)(a_a[i] - a_b[0]) < d))
		{
			i_a = i;
			d = (unsigned int)(a_a[i] - a_b[0]);
		}
		if (a_a[i_smallest] > a_a[i] && size_b != 0)
			i_smallest = i;
		i++;
	}
	if (i_a == -1)
		i_a = i_smallest;
	if (size_a - i_a < i_a)
		return (size_a - i_a + 1);
	return (i_a + 1);
}

static void	fill_helper_num_back(int **arr_a, int **arr_b, int *size_a, int *size_b, int *hn)
{
	hn[2] = 0;
	hn[3] = 0;
	hn[0] = count_moves_back(*arr_a, *arr_b, *size_a, *size_b) - 1;
	if (hn[0] == 0)
		hn[1] = 0;
	else
	{
		if ((*arr_b)[hn[2]] < (*arr_a)[hn[0]] &&
			(*arr_b)[hn[2]] > (*arr_a)[*size_a - hn[0]])
			hn[1] = hn[0];
		else if ((*arr_b)[hn[2]] < (*arr_a)[*size_a - hn[0]] &&
			(*arr_b)[hn[2]] > (*arr_a)[hn[0]])
			hn[1] = *size_a - hn[0];
		else if ((*arr_b)[hn[2]] - (*arr_a)[hn[0]] >
			(*arr_b)[hn[2]] - (*arr_a)[*size_a - hn[0]])
			hn[1] = hn[0];
		else
			hn[1] = *size_a - hn[0];
	}
	hn[4] = 0;
	hn[5] = 0;
	return ;
}

void	refilling_a(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	hn[6];

	create_helper_num(hn, 6);
	// a_moves, a_to_move, b_moves, b_to_move, count_a_move, count_b_move
	while (*size_b > 0)
	{
		fill_helper_num_back(arr_a, arr_b, size_a, size_b, hn);
		while (1)
		{
			if (i_ate(*size_a, hn[1]) && hn[1] != 0)
			{
				rra(arr_a, arr_b, size_a, size_b);
				hn[4]++;
			}
			else if (hn[1] != 0)
			{
				ra(arr_a, arr_b, size_a, size_b);
				hn[4]++;
			}
			if ((hn[4] == hn[0] && hn[5] == hn[2]))
				break ;
		}
		pa(arr_a, arr_b, size_a, size_b);
	}
	return ;
}
