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

static void	sort_a_3(int **arrays, int *sizes)
{
	if (arrays[0][0] > arrays[0][1] && arrays[0][0] > arrays[0][2])
		ra(arrays, sizes);
	if (arrays[0][1] > arrays[0][0] && arrays[0][1] > arrays[0][2])
		rra(arrays, sizes);
	if (arrays[0][0] > arrays[0][1])
		sa(arrays, sizes);
	return ;
}

static void	slide_arr(int **arrays, int *sizes, int i_biggest)
{
	if (i_ate(sizes[0], i_biggest))
	{
		while (i_biggest < sizes[0] - 1)
		{
			rra(arrays, sizes);
			i_biggest++;
		}
	}
	else
	{
		while (i_biggest >= 0)
		{
			ra(arrays, sizes);
			i_biggest--;
		}
	}
	return ;
}

static void	if_sorted_slide_than_sort(int **arrays, int *sizes)
{
	int	i;
	int	i_biggest;

	i = 0;
	i_biggest = 0;
	if (sizes[1] != 0)
		return ;
	if (sizes[0] == 2 && arrays[0][0] > arrays[0][1])
	{
		ra(arrays, sizes);
		return ;
	}
	while (i < sizes[0])
	{
		if (arrays[0][i_biggest] < arrays[0][i])
			i_biggest = i;
		i++;
	}
	i = 0;
	while (i + 1 < sizes[0])
	{
		if (arrays[0][i] > arrays[0][i + 1] && i != i_biggest)
			return ;
		i++;
	}
	slide_arr(arrays, sizes, i_biggest);
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

int	sort(int **arrays, int *sizes)
{
	while ((!is_a_sorted(arrays[0], sizes[0])) || sizes[1] != 0)
	{
		if_sorted_slide_than_sort(arrays, sizes);
		if (sizes[0] == 3 && !is_a_sorted(arrays[0], sizes[0]))
			sort_a_3(arrays, sizes);
		if (sizes[1] == 0 && !is_a_sorted(arrays[0], sizes[0]))
		{
			pb(arrays, sizes);
			if (sizes[0] == 3)
				continue ;
			pb(arrays, sizes);
			continue ;
		}
		if (!is_a_sorted(arrays[0], sizes[0]))
			filling_b(arrays, sizes);
		if (is_a_sorted(arrays[0], sizes[0]) && sizes[1] != 0)
			refilling_a(arrays, sizes);
	}
	return (1);
}
