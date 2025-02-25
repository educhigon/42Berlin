/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-22 08:13:18 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-22 08:13:18 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a_3(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	if ((*arr_a)[0] > (*arr_a)[1] && (*arr_a)[0] > (*arr_a)[2])
		ra(arr_a, arr_b, size_a, size_b);
	if ((*arr_a)[1] > (*arr_a)[0] && (*arr_a)[1] > (*arr_a)[2])
		rra(arr_a, arr_b, size_a, size_b);
	if ((*arr_a)[0] > (*arr_a)[1])
		sa(arr_a, arr_b, size_a, size_b);
	return ;
}

static void	slide_arr(int **arr_a, int **arr_b, int *size_a, int *size_b, int i_biggest)
{
	if (i_ate(*size_a, i_biggest))
	{
		while (i_biggest < *size_a - 1)
		{
			rra(arr_a, arr_b, size_a, size_b);
			i_biggest++;
		}
	}
	else
	{
		while (i_biggest >= 0)
		{
			ra(arr_a, arr_b, size_a, size_b);
			i_biggest--;
		}
	}
	return ;
}

static void	if_sorted_slide_than_sort(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	int	i;
	int	i_biggest;

	i = 0;
	i_biggest = 0;
	if (*size_b != 0)
		return ;
	if (*size_a == 2 && (*arr_a)[0] > (*arr_a)[1])
	{
		ra(arr_a, arr_b, size_a, size_b);
		return ;
	}
	while (i < *size_a)
	{
		if ((*arr_a)[i_biggest] < (*arr_a)[i])
			i_biggest = i;
		i++;
	}
	i = 0;
	while (i + 1 < *size_a)
	{
		if ((*arr_a)[i] > (*arr_a)[i + 1] && i != i_biggest)
			return ;
		i++;
	}
	slide_arr(arr_a, arr_b, size_a, size_b, i_biggest);
}

static int	is_a_sorted(int *arr_a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (arr_a[i] > arr_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sort(int **arr_a, int **arr_b, int *size_a, int *size_b)
{
	while ((!is_a_sorted(*arr_a, *size_a)) || *size_b != 0)
	{
		// print_array(*arr_a,*arr_b, *size_a, *size_b);

		if_sorted_slide_than_sort(arr_a, arr_b, size_a, size_b);
		if (*size_a == 3 && !is_a_sorted(*arr_a, *size_a))
			sort_a_3(arr_a, arr_b, size_a, size_b);
		if (*size_b == 0 && !is_a_sorted(*arr_a, *size_a))
		{
			pb(arr_a, arr_b, size_a, size_b);
			if (*size_a == 3)
				continue ;
			pb(arr_a, arr_b, size_a, size_b);
			continue ;
		}
		if (!is_a_sorted(*arr_a, *size_a))
			filling_b(arr_a, arr_b, size_a, size_b);
		if (is_a_sorted(*arr_a, *size_a) && *size_b != 0)
			refilling_a(arr_a, arr_b, size_a, size_b);
	}
	return (1);
}
