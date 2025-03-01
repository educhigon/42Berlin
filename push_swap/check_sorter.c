/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-01 08:22:25 by edugonza          #+#    #+#             */
/*   Updated: 2025-03-01 08:22:25 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_s(int **arrays, int *sizes)
{
	int	input;

	input = getchar();
	if (input == 'a')
		sa(arrays, sizes);
	else if (input == 'b')
		sb(arrays, sizes);
	else if (input == 's')
		ss(arrays, sizes);
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	check_p(int **arrays, int *sizes)
{
	int	input;

	input = getchar();
	if (input == 'a')
		pa(arrays, sizes);
	else if (input == 'b')
		pb(arrays, sizes);
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	check_rr(int **arrays, int *sizes)
{
	int	input;

	input = getchar();
	if (input == 'a')
		rra(arrays, sizes);
	else if (input == 'b')
		rrb(arrays, sizes);
	else if (input == 'r')
		rrr(arrays, sizes);
	else if (input == '\n')
		rr(arrays, sizes);
	else
		return (0);
	return (1);
}

int	check_r(int **arrays, int *sizes)
{
	int	input;
	int	valid;

	valid = 1;
	input = getchar();
	if (input == 'a')
		ra(arrays, sizes);
	else if (input == 'b')
		rb(arrays, sizes);
	else if (input == 'r')
		valid = check_rr(arrays, sizes);
	else if (valid == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
