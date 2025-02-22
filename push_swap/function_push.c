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
	/*
	arr_s[i] = NULL; // Careful here
	*/
	return ;
}

void	pa(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (*size_b > 0)
	{
		(*size_a)++;
		pusher(arr_b, arr_a, size_a, size_b);
		(*size_b)--;
		write(1, "pa\n", 3);
	}
	return ;
}

void	pb(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if (*size_a > 0)
	{
		(*size_b)++;
		pusher(arr_a, arr_b, size_b, size_a);
		(*size_a)--;
		write(1, "pb\n", 3);
	}
	return ;
}
