/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-22 08:15:21 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-22 08:15:21 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(char **input, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
		free(input[i++]);
	free(input);
	return ;
}

int	is_a_sorted(int *arr_a, int size_a)
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

static int	check_int(char *str)
{
	int	j;

	j = 0;
	if (str[j] == '-')
	{
		if (str[j + 1] == '\0')
			return (0);
		j++;
	}
	while (j < (int)ft_strlen(str))
	{
		if (str[j] < '0' || str[j] > '9')
			return (0);
		j++;
	}
	return (1);
}

static int	check_big_int(char *str)
{
	if (ft_atoi_here(str) > 2147483647 || ft_atoi_here(str) < -2147483648)
		return (0);
	return (1);
}

int	verify_input(int ac, char **input, int i)
{
	int	j;

	while (i < ac)
	{
		if (!check_int(input[i]))
			return (write(2, "Error\n", 6));
		if (!check_big_int(input[i]))
			return (write(2, "Error\n", 6));
		j = i + 1;
		while (j < ac)
		{
			if (ft_strncmp(input[j], "", 1) == 0)
				return (write(2, "Error\n", 6));
			if (ft_atoi_here(input[j]) == ft_atoi_here(input[i]))
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (1);
}
