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
	int	last_element;

	last_element = (*arr)[size - 1];
	i = size - 1;
	while (i > 0)
	{
		(*arr)[i] = (*arr)[i - 1];
		i--;
	}
	(*arr)[0] = last_element;
	return ;
}

void	rra(int **arrays, int *sizes)
{
	if (arrays[0] && sizes[0] > 1)
		reverse_rotator(&arrays[0], sizes[0]);
	return ;
}

void	rrb(int **arrays, int *sizes)
{
	if (arrays[1] && sizes[1] > 1)
		reverse_rotator(&arrays[1], sizes[1]);
	return ;
}

void	rrr(int **arrays, int *sizes)
{
	reverse_rotator(&arrays[0], sizes[0]);
	reverse_rotator(&arrays[1], sizes[1]);
	return ;
}
