/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 13:28:45 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-25 13:28:45 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_helper_num(int *sizes, int *hn)
{
	if (!i_ate(sizes[0], hn[1]))
		hn[0] = hn[1];
	else
		hn[0] = sizes[0] - hn[1];
	if (!i_ate(sizes[1], hn[3]))
		hn[2] = hn[3];
	else
		hn[2] = sizes[1] - hn[3];
	hn[4] = 0;
	hn[5] = 0;
	return ;
}

int	count_movements(int *sizes, int i_a, int i_b)
{
	if (!i_ate(sizes[0], i_a) && !i_ate(sizes[1], i_b))
	{
		if (i_a > i_b)
			return (i_a + 1);
		return (i_b + 1);
	}
	else if (i_ate(sizes[0], i_a) && i_ate(sizes[1], i_b))
	{
		if (sizes[0] - i_a > sizes[1] - i_b)
			return (sizes[0] - i_a + 1);
		return (sizes[1] - i_b + 1);
	}
	else
	{
		if (i_ate(sizes[0], i_a) && !i_ate(sizes[1], i_b))
			return (sizes[0] - i_a + i_b + 1);
		else
			return (sizes[1] - i_b + i_a + 1);
	}
}

int	mutual_rotations(int **arrays, int *sizes, int *hn)
{
	if (i_ate(sizes[0], hn[1]) && i_ate(sizes[1], hn[3])
		&& hn[0] - hn[4] != 0 && hn[2] - hn[5] != 0)
	{
		do_function("rrr", arrays, sizes);
		hn[5]++;
		hn[4]++;
		return (1);
	}
	else if (!i_ate(sizes[0], hn[1]) && !i_ate(sizes[1], hn[3])
		&& hn[0] - hn[4] != 0 && hn[2] - hn[5] != 0)
	{
		do_function("rr", arrays, sizes);
		hn[5]++;
		hn[4]++;
		return (1);
	}
	return (0);
}

void	unique_rotations(int **arrays, int *sizes, int *hn)
{
	if (i_ate(sizes[1], hn[3]) && hn[2] - hn[5] != 0)
	{
		do_function("rrb", arrays, sizes);
		hn[5]++;
	}
	else if (hn[3] != 0 && hn[2] - hn[5] != 0)
	{
		do_function("rb", arrays, sizes);
		hn[5]++;
	}
	if (i_ate(sizes[0], hn[1]) && hn[0] - hn[4] != 0)
	{
		do_function("rra", arrays, sizes);
		hn[4]++;
	}
	else if (hn[1] != 0 && hn[0] - hn[4] != 0)
	{
		do_function("ra", arrays, sizes);
		hn[4]++;
	}
}

void	do_function(char *name, int **arrays, int *sizes)
{
	if (name[0] == 'r' && name[1] == 'r' && name[2] == 'a')
		rra(arrays, sizes);
	else if (name[0] == 'r' && name[1] == 'r' && name[2] == 'b')
		rrb(arrays, sizes);
	else if (name[0] == 'r' && name[1] == 'r' && name[2] == 'r')
		rrr(arrays, sizes);
	else if (name[0] == 's' && name[1] == 'a')
		sa(arrays, sizes);
	else if (name[0] == 's' && name[1] == 'b')
		sb(arrays, sizes);
	else if (name[0] == 's' && name[1] == 's')
		ss(arrays, sizes);
	else if (name[0] == 'p' && name[1] == 'a')
		pa(arrays, sizes);
	else if (name[0] == 'p' && name[1] == 'b')
		pb(arrays, sizes);
	else if (name[0] == 'r' && name[1] == 'a')
		ra(arrays, sizes);
	else if (name[0] == 'r' && name[1] == 'b')
		rb(arrays, sizes);
	else if (name[0] == 'r' && name[1] == 'r')
		rr(arrays, sizes);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
	return ;
}
