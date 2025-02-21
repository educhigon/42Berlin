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

void pusher(int **arr_sending, int **arr_receiving, int *size_rec, int *size_send)
{
	int	i;
	int	external_num;
	int	helper;

	external_num = (*arr_sending)[0];
	i = 0;
	while (i < *size_rec)
	{
		helper = (*arr_receiving)[i];
		(*arr_receiving)[i] = external_num;
		external_num = helper;
		i++;
	}
	i = 0;
	while (i < *size_send)
	{
		(*arr_sending)[i] = (*arr_sending)[i + 1];
		i++;
	}
	arr_sending[i] = NULL;

	return;
}

void	pa(int **arr_a, int **arr_b,  int *size_a, int *size_b)
{
	(*size_a)++;
	pusher(arr_b, arr_a, size_a, size_b);
	(*size_b)--;
	write(1, "pa ", 3);
	return;
}

void	pb(int **arr_a, int **arr_b,  int *size_a, int *size_b)
{
	(*size_b)++;
	pusher(arr_a, arr_b, size_b, size_a);
	(*size_a)--;
	write(1, "pb ", 3);
	return;
}

