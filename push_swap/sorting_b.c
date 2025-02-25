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

static int	find_b_to_a(int **arrays, int *sizes, int i)
{
	int				j_b;
	int				j;
	int				j_biggest;
	unsigned int	d;

	j_b = -1;
	j = 0;
	j_biggest = 0;
	d = 0;
	while (j < sizes[1] && sizes[0])
	{
		if (arrays[0][i] > arrays[1][j] && (d == 0 || (unsigned int)(arrays[0][i] - arrays[1][j]) < d))
		{
			j_b = j;
			d = (unsigned int)(arrays[0][i] - arrays[1][j]);
		}
		if (arrays[1][j_biggest] < arrays[1][j] && sizes[1] != 0)
			j_biggest = j;
		j++;
	}
	if (j_b == -1)
		return (j_biggest);
	return (j_b);
}

static void	choose_a_and_b_to_move(int **arrays, int *sizes, int *hn)
{
	int	i;
	int	move_count_min;
	int	count_moves;
	int	b_index;

	i = 0;
	move_count_min = 0;
	while (i < sizes[0])
	{
		b_index = find_b_to_a(arrays, sizes, i);
		count_moves = count_movements(sizes, i, b_index);
		if (count_moves < move_count_min || move_count_min == 0)
		{
			move_count_min = count_moves;
			hn[1] = i;
			hn[3] = b_index;
		}
		i++;
	}
	return ;
}

void	filling_b(int **arrays, int *sizes)
{
	int	hn[6];

	create_helper_num(hn, 6);
	while (sizes[0] > 3)
	{
		choose_a_and_b_to_move(arrays, sizes, hn);
		fill_helper_num(sizes, hn);
		if (hn[4] == 0 && hn[0] == 0 && hn[5] == 0 && hn[2] == 0)
		{
			pb(arrays, sizes);
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
		pb(arrays, sizes);
	}
	return ;
}
