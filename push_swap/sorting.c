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
		if (arr_b[j_biggest] < arr_b[j])
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
		if (*size_a - i < i_a_move)
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

void filling_b(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	a_to_move;
	int	b_to_move;
	int	a_moves;
	int	b_moves;
	int	count_a_move;
	int	count_b_move;

	
	while(*size_a > 3)
	{
		a_to_move = choose_a_to_move(arr_a, arr_b, size_a, size_b);
		// write(1,"a_to_move: ",11);
		// ft_putnbr_fd(a_to_move, 1);
		// write(1,"\n",1);

		b_moves = count_moves(*arr_a, *arr_b, *size_a, *size_b, a_to_move) - 1;
		// write(1,"b_moves: ",9);
		// ft_putnbr_fd(b_moves, 1);
		// write(1,"\n",1);
		
		if (b_moves == 0)
			b_to_move = 0;
		else
		{
			if ((*arr_a)[a_to_move] < (*arr_b)[b_moves] && (*arr_a)[a_to_move] > (*arr_b)[*size_b - b_moves])
				b_to_move = *size_b - b_moves;
			else if ((*arr_a)[a_to_move] < (*arr_b)[*size_b - b_moves] && (*arr_a)[a_to_move] > (*arr_b)[b_moves])
				b_to_move = b_moves;
			else if ((*arr_a)[a_to_move] - (*arr_b)[b_moves] > (*arr_a)[a_to_move] - (*arr_b)[*size_b - b_moves]) 
				b_to_move = *size_b - b_moves;
			else
				b_to_move = b_moves;
		}
	
		// write(1,"b_to_move: ",11);
		// ft_putnbr_fd(b_to_move, 1);
		// write(1,"\n",1);

		if(i_ATE(*size_a, a_to_move))
			a_moves = *size_a - a_to_move;
		else
			a_moves = a_to_move;

		// write(1,"a_moves: ",9);
		// ft_putnbr_fd(a_moves, 1);
		// write(1,"\n",1);

		count_b_move = 0;	
		count_a_move = 0;
		while (1)
		{
			if (i_ATE(*size_a, a_to_move) && i_ATE(*size_b, b_to_move) && a_to_move != 0 && b_to_move != 0)
			{
				rrr(arr_a, arr_b, size_a, size_b);
				count_b_move++;
				count_a_move++;
			}
			else if (!i_ATE(*size_a, a_to_move) && !i_ATE(*size_b, b_to_move)&& a_to_move != 0 && b_to_move != 0)
			{
				rr(arr_a, arr_b, size_a, size_b);
				count_b_move++;
				count_a_move++;
			}
			else
			{
				if (i_ATE(*size_b, b_to_move) && b_to_move != 0)
				{
					rrb(arr_a, arr_b, size_a, size_b);
					count_b_move++;
				}
				else if (b_to_move != 0)
				{
					rb(arr_a, arr_b, size_a, size_b);
					count_b_move++;
				}
				if (i_ATE(*size_a, a_to_move) && a_to_move != 0)
				{
					rra(arr_a, arr_b, size_a, size_b);
					count_a_move++;
				}
				else if (a_to_move != 0)
				{
					ra(arr_a, arr_b, size_a, size_b);
					count_a_move++;
				}
			}
			// write(1,"count_b_move: ",14);
			// ft_putnbr_fd(count_b_move, 1);
			// write(1,"\n",1);
			// write(1,"count_a_move: ",14);
			// ft_putnbr_fd(count_a_move, 1);
			// write(1,"\n",1);
			if (count_a_move == a_moves && count_b_move == b_moves)
				break;
		}
		pb(arr_a, arr_b, size_a, size_b);
		print_array(*arr_a,*arr_b, *size_a, *size_b);
	}
}
void refilling_a(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if ((arr_a && arr_b && size_a && size_b))
	{
		return;
		/* code */
	}
	return;
	
	// int	a_to_move;
	// int	b_to_move;

	// while(*size_b > 0)
	// {
	// 	a_to_move = choose_a_to_move(arr_a, arr_b, size_a, size_b)
	// 	b_to_move = count_moves(*arr_a,*arr_b, *size_a, *size_b, a_to_move) - 1
	// 	move_a_and_b_to_position(arr_a, arr_b, size_a, size_b);
	// 	pa(arr_a, arr_b, size_a, size_b);
	// }
}