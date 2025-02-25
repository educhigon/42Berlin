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

static int	find_a_to_b(int **arrays, int *sizes, int i)
{
	int				j_a;
	int				j;
	int				j_smallest;
	unsigned int	d;

	j_a = -1;
	j = 0;
	j_smallest = 0;
	d = 0;
	while (j < sizes[0] && sizes[1])
	{
		if (arrays[0][j] > arrays[1][i] && (d == 0 || (unsigned int)(arrays[0][j] - arrays[1][i]) < d))
		{
			j_a = j;
			d = (unsigned int)(arrays[0][j] - arrays[1][i]);
		}
		if (arrays[0][j_smallest] > arrays[0][j] && sizes[1] != 0)
			j_smallest = j;
		j++;
	}
	if (j_a == -1)
		return (j_smallest);
	return (j_a);
}

static void	choose_b_and_a_to_move(int **arrays, int *sizes, int *hn)
{
	int	i;
	int	move_count_min;
	int	count_moves;
	int	a_index;

	i = 0;
	move_count_min = 0;
	while (i < sizes[1])
	{
		a_index = find_a_to_b(arrays, sizes, i);
		count_moves = count_movements(sizes, a_index, i);
		if (count_moves < move_count_min || move_count_min == 0)
		{
			move_count_min = count_moves;
			hn[3] = i;
			hn[1] = a_index;
		}
		i++;
	}
	return ;
}

// a_moves, a_to_move, b_moves, b_to_move, count_a_move, count_b_move
void	refilling_a(int **arrays, int *sizes)
{
	int	hn[6];

	create_helper_num(hn, 6);
	while (sizes[1] > 0)
	{
		choose_b_and_a_to_move(arrays, sizes, hn);
		fill_helper_num(sizes, hn);
		if (hn[4] == 0 && hn[0] == 0 && hn[5] == 0 && hn[2] == 0)
		{
			pa(arrays, sizes);
			continue ;
		}
		else
		{
			while ((hn[0] - hn[4] != 0 || hn[2] - hn[5] != 0))
			{
				if (i_ate(sizes[0], hn[1]) && i_ate(sizes[1], hn[3]) && hn[0] - hn[4] != 0 && hn[2] - hn[5] != 0)
				{
					rrr(arrays, sizes);
					hn[5]++;
					hn[4]++;
				}
				else if (!i_ate(sizes[0], hn[1]) && !i_ate(sizes[1], hn[3]) && hn[0] - hn[4] != 0 && hn[2] - hn[5] != 0)
				{
					rr(arrays, sizes);
					hn[5]++;
					hn[4]++;
				}
				else
				{
					if (i_ate(sizes[1], hn[3]) && hn[2] - hn[5] != 0)
					{
						rrb(arrays, sizes);
						hn[5]++;
					}
					else if (hn[3] != 0 && hn[2] - hn[5] != 0)
					{
						rb(arrays, sizes);
						hn[5]++;
					}
					if (i_ate(sizes[0], hn[1]) && hn[0] - hn[4] != 0)
					{
						rra(arrays, sizes);
						hn[4]++;
					}
					else if (hn[1] != 0 && hn[0] - hn[4] != 0)
					{
						ra(arrays, sizes);
						hn[4]++;
					}
				}
			}
		}
		pa(arrays, sizes);
	}
	return ;
}
