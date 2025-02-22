/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 18:33:53 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-17 18:33:53 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotator(int **arr, int size)
{
	int	i;
	int	external_num;
	int	helper;

	external_num = (*arr)[size -1];
	i = 0;
	while (i < size)
	{
		helper = (*arr)[i];
		(*arr)[i] = external_num;
		external_num = helper;
		i++;
	}
	return ;
}

void	rra(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (arr_b && size_b)
		reverse_rotator(arr_a, *size_a);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (arr_a && size_a)
		reverse_rotator(arr_b, *size_b);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	reverse_rotator(arr_a, *size_a);
	reverse_rotator(arr_b, *size_b);
	write(1, "rrr\n", 4);
	return ;
}
