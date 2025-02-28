/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:12:06 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/13 19:52:10 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_01.h"
#include <unistd.h>

void	matrix_initializer(t_sid *rules);

int	cus_atoi(char *arg, int i)
{
	int	digit;

	digit = 0;
	if (arg[i] >= '1' && arg[i] <= '4')
		digit = arg[i] - '0';
	else
	{
		return (0);
	}
	return (digit);
}

void	separator(char *in, int *out)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	j = 0;
	while (in[i])
	{
		if (in[i] >= '1' && in[i] <= '4')
		{
			value = cus_atoi(in, i);
			out[j] = value;
			j++;
		}
		i++;
	}
	return ;
}

int	checker(char *in)
{
	int	i;
	int	j;
	int	space;

	i = 0;
	j = 0;
	space = 1;
	while (in[i])
	{
		if (in[i] == ' ')
			space++;
		else if (in[i] >= '1' && in[i] <= '4' && space == 1)
		{
			space--;
			j++;
		}
		else
			return (1);
		i++;
	}
	if (j == 16 && space == 0)
		return (0);
	return (1);
}

void	regrouper(int *sides, t_sid *side_by_side)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		if (i == 4 || i == 8 || i == 12)
			j = 0;
		if (i < 4)
			side_by_side->top[j] = sides[i];
		else if (i >= 4 && i < 8)
			side_by_side->bottom[j] = sides[i];
		else if (i >= 8 && i < 12)
			side_by_side->left[j] = sides[i];
		else if (i >= 12 && i < 16)
			side_by_side->right[j] = sides[i];
		i++;
		j++;
	}
}

int	main(int ac, char *av[])
{
	int		valid;
	int		sides[16];
	t_sid	side_by_side;

	if (ac != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	valid = checker(av[1]);
	if (valid != 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	separator(av[1], sides);
	regrouper(sides, &side_by_side);
	matrix_initializer(&side_by_side);
}
