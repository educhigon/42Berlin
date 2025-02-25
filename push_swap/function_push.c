/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 18:33:38 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-17 18:33:38 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pusher(int **arr_s, int **arr_r, int *size_rec, int *size_send)
{
	int	i;
	int	external_num;
	int	helper;

	external_num = (*arr_s)[0];
	i = 0;
	while (i < *size_rec)
	{
		helper = (*arr_r)[i];
		(*arr_r)[i] = external_num;
		external_num = helper;
		i++;
	}
	i = 0;
	while (i < *size_send - 1)
	{
		(*arr_s)[i] = (*arr_s)[i + 1];
		i++;
	}
	return ;
}

void	pa(int **arrays, int *sizes)
{
	if (sizes[1] > 0)
	{
		sizes[0]++;
		pusher(&arrays[1], &arrays[0], &sizes[0], &sizes[1]);
		sizes[1]--;
		write(1, "pa\n", 3);
	}
	return ;
}

void	pb(int **arrays, int *sizes)
{
	if (sizes[0] > 0)
	{
		sizes[1]++;
		pusher(&arrays[0], &arrays[1], &sizes[1], &sizes[0]);
		sizes[0]--;
		write(1, "pb\n", 3);
	}
	return ;
}
