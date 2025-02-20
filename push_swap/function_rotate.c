/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 18:33:32 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-17 18:33:32 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotator(int **arr, int size)
{
	int	i;
	int	external_num;

	external_num = (*arr)[0];
	i = 0;
	while (i < size)
	{
		(*arr)[i] = (*arr)[i + 1];
		i++;
	}
	(*arr)[i-1] = external_num;
	return;
}

void	ra(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (arr_b && size_b)
		rotator(arr_a, *size_a);
	return;
}

void	rb(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (arr_a && size_a)
		rotator(arr_b, *size_b);
	return;
}

void	rr(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	ra(arr_a, arr_b, size_a, size_b);
	rb(arr_a, arr_b, size_a, size_b);
	return;
}