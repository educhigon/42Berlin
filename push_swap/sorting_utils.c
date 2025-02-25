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
