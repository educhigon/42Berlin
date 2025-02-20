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

void reverse_rotator(int **arr, int size)
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
		// (*arr)[i] = (*arr)[i - 1];
		// i++;
	}
	// (*arr)[0] = external_num;
	return;
}

void	rra(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (arr_b && size_b)
		reverse_rotator(arr_a, *size_a);
	return;
}

void	rrb(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (arr_a && size_a)
		reverse_rotator(arr_b, *size_b);
	return;
}

void	rrr(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	rra(arr_a, arr_b, size_a, size_b);
	rrb(arr_a, arr_b, size_a, size_b);
	return;
}