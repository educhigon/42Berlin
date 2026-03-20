/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargolo <amargolo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:54:07 by amargolo          #+#    #+#             */
/*   Updated: 2024/10/02 15:54:16 by amargolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./recursive_check.c"

int	cus_atoi(char *arg, int i)
{
	int	digit;

	digit = 0;
	if (arg[i] >= '1' && arg[i] <= '4')
		digit = arg[i] - '0';
	else
	{
		write(1, "Invalid input.\n", 15);
		return (0);
	}
	return (digit);
}

int	separator(char *in, int *out)
{
	int	i;
	int	j;
	int	value;
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
			value = cus_atoi(in, i);
			out[j] = value;
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

int	main(int ac, char *av[])
{
	int	valid;
	int	sides[16];
	int	i;

	i = 0;
	if (ac != 2)
	{
		write(1, "Invalid input.\n", 15);
		return (0);
	}
	valid = separator(av[1], sides);
	if (valid == 1)
	{
		write(1, "Invalid input.\n", 15);
		return (1);
	}
	while (i < 16)
	{
		printf("%i ", sides[i]);
		i++;
	}
	printf("\n");
}
