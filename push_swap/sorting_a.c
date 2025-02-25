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

static int	count_moves_back(int *a_a, int *a_b, int size_a, int size_b, int i)
{
	int				j_a;
	unsigned int	d;
	int				j;
	int				j_smallest;

	j = 0;
	j_a = -1;
	d = 0;
	j_smallest = 0;
	while (j < size_a && size_b)
	{
		if (a_a[j] > a_b[i] && (d == 0 || (unsigned int)(a_a[j] - a_b[i]) < d))
		{
			j_a = j;
			d = (unsigned int)(a_a[j] - a_b[i]);
		}
		if (a_a[j_smallest] > a_a[j] && size_b != 0)
			j_smallest = j;
		j++;
	}
	if (j_a == -1)
		j_a = j_smallest;
	if (size_a - j_a < j_a)
		return (size_a - j_a + 1);
	return (j_a + 1);
}

static int	choose_b_to_move(int *arr_a, int *arr_b, int size_a, int size_b)
{
	int	i;
	int	move_count_min;
	int	i_b;
	int	i_b_move;

	i = 0;
	move_count_min = 0;
	while (i < size_b && size_a)
	{
		if (size_b - i < i) // careful here
			i_b_move = size_b - i;
		else
			i_b_move = i;
		if (move_count_min == 0 || count_moves_back(arr_a, arr_b, size_a, size_b, i) + i_b_move < move_count_min)
		{
			move_count_min = count_moves_back(arr_a, arr_b, size_a, size_b, i) + i_b_move;
			i_b = i_b_move;
		}
		i++;
	}
	return (i_b);
}

static void	fill_helper_num_back(int *arr_a, int *arr_b, int size_a, int size_b, int *hn)
{
	hn[3] = choose_b_to_move(arr_a, arr_b, size_a, size_b);
	hn[0] = count_moves_back(arr_a, arr_b, size_a, size_b, hn[3]) - 1;
	if (hn[0] == 0)
		hn[1] = 0;
	else
	{
		if (arr_b[hn[2]] < arr_a[hn[0]] &&
			arr_b[hn[2]] > arr_a[size_a - hn[0]])
			hn[1] = hn[0];
		else if (arr_b[hn[2]] < arr_a[size_a - hn[0]] &&
			arr_b[hn[2]] > arr_a[hn[0]])
			hn[1] = size_a - hn[0];
		else if (arr_b[hn[2]] - arr_a[hn[0]] >
			arr_b[hn[2]] - arr_a[size_a - hn[0]])
			hn[1] = hn[0];
		else
			hn[1] = size_a - hn[0];
	}
	if (i_ate(size_b, hn[3]))
		hn[2] = size_b - hn[3];
	else
		hn[2] = hn[3];
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
		fill_helper_num_back(*arr_a, *arr_b, *size_a, *size_b, hn);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);

		// ft_printf("a_moves: %d\n", hn[0]);
		// ft_printf("a_to_move: %d\n", hn[1]);
		// ft_printf("b_moves: %d\n", hn[2]);
		// ft_printf("b_to_move: %d\n", hn[3]);
		// ft_printf("count_a_moves: %d\n", hn[4]);
		// ft_printf("count_b_moves: %d\n", hn[5]);
		if (hn[4] == 0 && hn[0] == 0 && hn[5] == 0 && hn[2] == 0)
		{
			pa(arr_a, arr_b, size_a, size_b);
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
		// {
		// 	while ((hn[0] - hn[4] != 0 || hn[2] - hn[5] != 0))
		// 	{
		// 		if (i_ate(*size_a, hn[1]) && hn[1] != 0)
		// 		{
		// 			rra(arr_a, arr_b, size_a, size_b);
		// 			hn[4]++;
		// 		}
		// 		else if (hn[1] != 0)
		// 		{
		// 			ra(arr_a, arr_b, size_a, size_b);
		// 			hn[4]++;
		// 		}
		// 	}
		// }
		pa(arr_a, arr_b, size_a, size_b);
	}
	return ;
}
