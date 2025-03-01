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

void	rotator(int **arr, int size)
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
	(*arr)[i - 1] = external_num;
	return ;
}

void	ra(int **arrays, int *sizes)
{
	if (arrays[0] && sizes[0] > 1)
		rotator(&arrays[0], sizes[0]);
	return ;
}

void	rb(int **arrays, int *sizes)
{
	if (arrays[1] && sizes[1] > 1)
		rotator(&arrays[1], sizes[1]);
	return ;
}

void	rr(int **arrays, int *sizes)
{
	rotator(&arrays[0], sizes[0]);
	rotator(&arrays[1], sizes[1]);
	return ;
}
