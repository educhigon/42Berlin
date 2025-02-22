/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-20 12:51:00 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-20 12:51:00 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_moves(int *a_a, int *a_b, int size_a, int size_b, int i)
{
	int				j_b;
	int				j;
	int				j_biggest;
	unsigned int	d;

	j = 0;
	j_b = -1;
	d = 0;
	j_biggest = 0;
	while (j < size_b && size_a)
	{
		if (a_a[i] > a_b[j] && (d == 0 || (unsigned int)(a_a[i] - a_b[j]) < d))
		{
			j_b = j;
			d = (unsigned int)(a_a[i] - a_b[j]);
		}
		if (a_b[j_biggest] < a_b[j] && size_b != 0)
			j_biggest = j;
		j++;
	}
	if (j_b == -1)
		j_b = j_biggest;
	if (size_b - j_b < j_b)
		return (size_b - j_b + 1);
	return (j_b + 1);
}

static int	choose_a_to_move(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	i;
	int	move_count_min;
	int	i_a;
	int	i_a_move;

	i = 0;
	move_count_min = 0;
	while (i < *size_a)
	{
		if (*size_a - i < i) // careful here
			i_a_move = *size_a - i;
		else
			i_a_move = i;
		if (move_count_min == 0 || count_moves(*arr_a, *arr_b, *size_a, *size_b, i) + i_a_move < move_count_min)
		{
			move_count_min = count_moves(*arr_a, *arr_b, *size_a, *size_b, i) + i_a_move;
			i_a = i_a_move;
		}
		i++;
	}
	return (i_a);
}

static void	fill_helper_num(int **arr_a, int **arr_b, int *size_a, int *size_b, int *hn)
{
	hn[1] = choose_a_to_move(arr_a, arr_b, size_a, size_b);
	hn[2] = count_moves(*arr_a, *arr_b, *size_a, *size_b, hn[1]) - 1;
	if (hn[2] == 0)
		hn[3] = 0;
	else
	{
		if ((*arr_a)[hn[1]] < (*arr_b)[hn[2]] &&
		(*arr_a)[hn[1]] > (*arr_b)[*size_b - hn[2]])
			hn[3] = *size_b - hn[2];
		else if ((*arr_a)[hn[1]] < (*arr_b)[*size_b - hn[2]] &&
		(*arr_a)[hn[1]] > (*arr_b)[hn[2]])
			hn[3] = hn[2];
		else if ((*arr_a)[hn[1]] - (*arr_b)[hn[2]] >
		(*arr_a)[hn[1]] - (*arr_b)[*size_b - hn[2]])
			hn[3] = *size_b - hn[2];
		else
			hn[3] = hn[2];
	}
	if (i_ate(*size_a, hn[1]))
		hn[0] = *size_a - hn[1];
	else
		hn[0] = hn[1];
	hn[4] = 0;
	hn[5] = 0;
	return ;
}

void	filling_b(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	hn[6];

	create_helper_num(hn, 6);
	// a_moves, a_to_move, b_moves, b_to_move, count_a_move, count_b_move
	while (*size_a > 3)
	{
		fill_helper_num(arr_a, arr_b, size_a, size_b, hn);
		if (hn[4] == 0 && hn[0] == 0 && hn[5] == 0 && hn[2] == 0)
		{
			pb(arr_a, arr_b, size_a, size_b);
			continue ;
		}
		else
		{
			while ((hn[0] - hn[4] != 0 || hn[2] - hn[5] != 0))
			{
				if (i_ate(*size_a, hn[1]) && i_ate(*size_b, hn[3]) && hn[0] - hn[4] != 0 && hn[2] - hn[5] != 0)
				{
					rrr(arr_a, arr_b, size_a, size_b);
					hn[5]++;
					hn[4]++;
				}
				else if (!i_ate(*size_a, hn[1]) && !i_ate(*size_b, hn[3]) && hn[0] - hn[4] != 0 && hn[2] - hn[5] != 0)
				{
					rr(arr_a, arr_b, size_a, size_b);
					hn[5]++;
					hn[4]++;
				}
				else
				{
					if (i_ate(*size_b, hn[3]) && hn[2] - hn[5] != 0)
					{
						rrb(arr_a, arr_b, size_a, size_b);
						hn[5]++;
					}
					else if (hn[3] != 0 && hn[2] - hn[5] != 0)
					{
						rb(arr_a, arr_b, size_a, size_b);
						hn[5]++;
					}
					if (i_ate(*size_a, hn[1]) && hn[0] - hn[4] != 0)
					{
						rra(arr_a, arr_b, size_a, size_b);
						hn[4]++;
					}
					else if (hn[1] != 0 && hn[0] - hn[4] != 0)
					{
						ra(arr_a, arr_b, size_a, size_b);
						hn[4]++;
					}
				}
			}
		}
		pb(arr_a, arr_b, size_a, size_b);
	}
	return ;
}
