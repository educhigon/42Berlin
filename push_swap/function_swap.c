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

void	sa(int **arrays, int *sizes)
{
	if (arrays[0] && sizes[0] > 1)
		swapper(&arrays[0]);
	return ;
}

void	sb(int **arrays, int *sizes)
{
	if (arrays[1] && sizes[1] > 1)
		swapper(&arrays[1]);
	return ;
}

void	ss(int **arrays, int *sizes)
{
	sa(arrays, sizes);
	sb(arrays, sizes);
	return ;
}
