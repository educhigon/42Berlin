/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 18:32:43 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-17 18:32:43 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapper(int **arr)
{
	int	helper;

	helper = (*arr)[0];
	(*arr)[0] = (*arr)[1];
	(*arr)[1] = helper;
	return ;
}

void	sa(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (*arr_b && size_a && size_b)
		swapper(arr_a);
	write(1, "sa\n", 3);
	return ;
}

void	sb(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (*arr_a && size_a && size_b)
		swapper(arr_b);
	write(1, "sb\n", 3);
	return ;
}

void	ss(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	sa(arr_a, arr_b, size_a, size_b);
	sb(arr_a, arr_b, size_a, size_b);
	return ;
}
