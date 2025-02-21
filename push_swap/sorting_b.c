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

void sort_a_3(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if ((*arr_a)[0] > (*arr_a)[1] && (*arr_a)[0] > (*arr_a)[2])
		ra(arr_a, arr_b, size_a, size_b);
	if ((*arr_a)[1] > (*arr_a)[0] && (*arr_a)[1] > (*arr_a)[2])
		rra(arr_a, arr_b, size_a, size_b);
	if ((*arr_a)[0] > (*arr_a)[1])
		sa(arr_a, arr_b, size_a, size_b);
	return;
}

int count_moves(int *arr_a, int *arr_b, int size_a, int size_b, int i)
{
	int	j_b;
	unsigned int	j_b_dist;
	int	j;
	int	j_biggest;

	j = 0;
	j_b = -1;
	j_b_dist = 0;
	j_biggest = 0;
	while (j < size_b && size_a)
	{
		if (arr_a[i] > arr_b[j] && (j_b_dist == 0 || (unsigned int)(arr_a[i] - arr_b[j]) < j_b_dist))
		{
			j_b = j;
			j_b_dist = (unsigned int)(arr_a[i] - arr_b[j]);
		}
		if (arr_b[j_biggest] < arr_b[j] && size_b != 0)
			j_biggest = j;
		j++;		
	}
	if (j_b == -1)
		j_b = j_biggest;
	if (size_b - j_b < j_b)
		return(size_b - j_b + 1);
	return(j_b + 1);
}

int	choose_a_to_move(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	i = 0;
	int	move_count_min = 0;
	int	i_a = 0;
	int	i_a_move = 0;
	
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

void	fill_helper_num(int **arr_a, int **arr_b, int *size_a, int *size_b, int *helper_num)
{
	helper_num[1] = choose_a_to_move(arr_a, arr_b, size_a, size_b);
	helper_num[2] = count_moves(*arr_a, *arr_b, *size_a, *size_b, helper_num[1]) - 1;
	if (helper_num[2] == 0)
		helper_num[3] = 0;
	else
	{
		if ((*arr_a)[helper_num[1]] < (*arr_b)[helper_num[2]] && (*arr_a)[helper_num[1]] > (*arr_b)[*size_b - helper_num[2]])
			helper_num[3] = *size_b - helper_num[2];
		else if ((*arr_a)[helper_num[1]] < (*arr_b)[*size_b - helper_num[2]] && (*arr_a)[helper_num[1]] > (*arr_b)[helper_num[2]])
			helper_num[3] = helper_num[2];
		else if ((*arr_a)[helper_num[1]] - (*arr_b)[helper_num[2]] > (*arr_a)[helper_num[1]] - (*arr_b)[*size_b - helper_num[2]]) 
			helper_num[3] = *size_b - helper_num[2];
		else
			helper_num[3] = helper_num[2];
	}
	if(i_ATE(*size_a, helper_num[1]))
		helper_num[0] = *size_a - helper_num[1];
	else
		helper_num[0] = helper_num[1];
	helper_num[4] = 0;
	helper_num[5] = 0;
	return;
}

void filling_b(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int helper_num[] = {0,0,0,0,0,0}; // a_moves, a_to_move, b_moves, b_to_move, count_a_move, count_b_move

	while(*size_a > 3)
	{
		fill_helper_num(arr_a, arr_b, size_a, size_b, helper_num);
		while (1)
		{
			if (i_ATE(*size_a, helper_num[1]) && i_ATE(*size_b, helper_num[3]) && helper_num[1] != 0 && helper_num[3] != 0)
			{
				rrr(arr_a, arr_b, size_a, size_b);
				helper_num[5]++;
				helper_num[4]++;
			}
			else if (!i_ATE(*size_a, helper_num[1]) && !i_ATE(*size_b, helper_num[3])&& helper_num[1] != 0 && helper_num[3] != 0)
			{
				rr(arr_a, arr_b, size_a, size_b);
				helper_num[5]++;
				helper_num[4]++;
			}
			else
			{
				if (i_ATE(*size_b, helper_num[3]) && helper_num[3] != 0)
				{
					rrb(arr_a, arr_b, size_a, size_b);
					helper_num[5]++;
				}
				else if (helper_num[3] != 0)
				{
					rb(arr_a, arr_b, size_a, size_b);
					helper_num[5]++;
				}
				if (i_ATE(*size_a, helper_num[1]) && helper_num[1] != 0)
				{
					rra(arr_a, arr_b, size_a, size_b);
					helper_num[4]++;
				}
				else if (helper_num[1] != 0)
				{
					ra(arr_a, arr_b, size_a, size_b);
					helper_num[4]++;
				}
			}
			if (helper_num[4] == helper_num[0] && helper_num[5] == helper_num[2])
				break;
		}
		pb(arr_a, arr_b, size_a, size_b);
	}
	return;
}
