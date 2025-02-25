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

static int	find_b_to_a(int *a_a, int *a_b, int size_a, int size_b, int i)
{
	int				j_b;
	int				j;
	int				j_biggest;
	unsigned int	d;

	j_b = -1;
	j = 0;
	j_biggest = 0;
	d = 0;
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
		return (j_biggest);
	return (j_b);
}

static int	count_movements(int size_a, int size_b, int i_a, int i_b)
{
	if (!i_ate(size_a, i_a) && !i_ate(size_b, i_b))
	{
		if (i_a > i_b)
			return (i_a + 1);
		return (i_b + 1);
	}
	else if (i_ate(size_a, i_a) && i_ate(size_b, i_b))
	{
		if (size_a - i_a > size_b - i_b)
			return (size_a - i_a + 1);
		return (size_b - i_b + 1);
	}
	else
	{
		if (i_ate(size_a, i_a) && !i_ate(size_b, i_b))
			return (size_a - i_a + i_b + 1);
		else
			return (size_b - i_b + i_a + 1);
	}
}


static void	choose_a_and_b_to_move(int **arr_a, int **arr_b, int *size_a, int *size_b, int *hn)
{
	int	i;
	int	move_count_min;
	int	count_moves;
	int b_index;

	i = 0;
	move_count_min = 0;
	while (i < *size_a)
	{
		b_index = find_b_to_a(*arr_a, *arr_b, *size_a, *size_b, i);
		count_moves = count_movements(*size_a, *size_b, i, b_index);
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

static void	fill_helper_num(int **arr_a, int **arr_b, int *size_a, int *size_b, int *hn)
{
	choose_a_and_b_to_move(arr_a, arr_b, size_a, size_b, hn);
	if (!i_ate(*size_a, hn[1]))
		hn[0] = hn[1];
	else
		hn[0] = *size_a - hn[1];
	if (!i_ate(*size_b, hn[3]))
		hn[2] = hn[3];
	else
		hn[2] = *size_b - hn[3];
	hn[4] = 0;
	hn[5] = 0;
	return ;
}

void	filling_b(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	hn[6];

	create_helper_num(hn, 6);
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
