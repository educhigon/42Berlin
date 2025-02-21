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

int count_moves_back(int *arr_a, int *arr_b, int size_a, int size_b)
{
	int	i_a;
	unsigned int	i_a_dist;
	int	i;
	int	i_smallest;

	i = 0;
	i_a = -1;
	i_a_dist = 0;
	i_smallest = 0;
	// write(1,"\nsize_a: ",9);
	// ft_putnbr_fd(size_a, 1);
	// write(1,"\n",1);
	while (i < size_a && size_b)
	{
		if (arr_a[i] > arr_b[0] && (i_a_dist == 0 || (unsigned int)(arr_a[i] - arr_b[0]) < i_a_dist))
		{
			// write(1,"\ni_a: ",6);
			// ft_putnbr_fd(i_a, 1);
			// write(1,"\n",1);
			i_a = i;
			i_a_dist = (unsigned int)(arr_a[i] - arr_b[0]);
		}
		if (arr_a[i_smallest] > arr_a[i] && size_b != 0)
			i_smallest = i;
		i++;		
	}
	if (i_a == -1)
		i_a = i_smallest;
	// write(1,"\ni_a: ",6);
	// ft_putnbr_fd(i_a, 1);
	// write(1,"\n",1);
	if (size_a - i_a < i_a)
		return(size_a - i_a + 1);
	return(i_a + 1);
}
void	fill_helper_num_back(int **arr_a, int **arr_b, int *size_a, int *size_b, int *helper_num)
{
	helper_num[2] = 0;
	helper_num[3] = 0;
	helper_num[0] = count_moves_back(*arr_a, *arr_b, *size_a, *size_b) - 1;
	if (helper_num[0] == 0)
		helper_num[1] = 0;
	else
	{
		if ((*arr_b)[helper_num[2]] < (*arr_a)[helper_num[0]] && (*arr_b)[helper_num[2]] > (*arr_a)[*size_a - helper_num[0]])
			helper_num[1] = helper_num[0];
		else if ((*arr_b)[helper_num[2]] < (*arr_a)[*size_a - helper_num[0]] && (*arr_b)[helper_num[2]] > (*arr_a)[helper_num[0]])
			helper_num[1] = *size_a - helper_num[0];
		else if ((*arr_b)[helper_num[2]] - (*arr_a)[helper_num[0]] > (*arr_b)[helper_num[2]] - (*arr_a)[*size_a - helper_num[0]]) 
			helper_num[1] = helper_num[0];
		else
			helper_num[1] = *size_a - helper_num[0];
	}
	helper_num[4] = 0;
	helper_num[5] = 0;
	return;
}

void refilling_a(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	// write(1,"here\n",5);
	int helper_num[] = {0,0,0,0,0,0}; // a_moves, a_to_move, b_moves, b_to_move, count_a_move, count_b_move
	int limit = 0;
	while(*size_b > 0)
	{
		fill_helper_num_back(arr_a, arr_b, size_a, size_b, helper_num);
		// write(1,"helper_num[0]: ",15);
		// ft_putnbr_fd(helper_num[0], 1);
		// write(1,"\n",1);
		// write(1,"helper_num[1]: ",15);
		// ft_putnbr_fd(helper_num[1], 1);
		// write(1,"\n",1);
		// write(1,"helper_num[2]: ",15);
		// ft_putnbr_fd(helper_num[2], 1);
		// write(1,"\n",1);
		// write(1,"helper_num[3]: ",15);
		// ft_putnbr_fd(helper_num[3], 1);
		// write(1,"\n",1);
		// write(1,"helper_num[4]: ",15);
		// ft_putnbr_fd(helper_num[4], 1);
		// write(1,"\n",1);
		// write(1,"helper_num[5]: ",15);
		// ft_putnbr_fd(helper_num[5], 1);
		// write(1,"\n",1);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);


		while (1)
		{
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
			if ((helper_num[4] == helper_num[0] && helper_num[5] == helper_num[2]) && limit < 10)
				break;
		}
		pa(arr_a, arr_b, size_a, size_b);
		// print_array(*arr_a,*arr_b, *size_a, *size_b);

	}
	return;
}

	// int	a_to_move;
	// int	b_to_move;

	// while(*size_b > 0)
	// {
	// 	a_to_move = choose_a_to_move(arr_a, arr_b, size_a, size_b)
	// 	b_to_move = count_moves(*arr_a,*arr_b, *size_a, *size_b, a_to_move) - 1
	// 	move_a_and_b_to_position(arr_a, arr_b, size_a, size_b);
	// 	pa(arr_a, arr_b, size_a, size_b);
	// }

	// write(1,"a_to_move: ",11);
	// ft_putnbr_fd(a_to_move, 1);
	// write(1,"\n",1);
