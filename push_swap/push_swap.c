/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:09:59 by edugonza          #+#    #+#             */
/*   Updated: 2025/02/05 17:27:51 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_arr(int ac, char **av)
{
	int	i;
	int	*arr_a;
	int	*arr_b;
	int	size_a;
	int	size_b;

	arr_a = malloc((ac + 1) * sizeof(int));
	arr_b = malloc((ac + 1) * sizeof(int));
	if (arr_a == NULL || arr_b == NULL)
		return ;
	size_a = ac;
	size_b = 0;
	i = 0;
	while (i < ac)
	{
		arr_a[i] = ft_atoi_here(av[i]);
		i++;
	}
	sort(&arr_a, &arr_b, &size_a, &size_b);
	free(arr_a);
	free(arr_b);
	return ;
}

int	main(int ac, char *av[])
{
	char	**input;
	int i = 0;

	if (ac == 2)
	{
		if ((*av)[1] == '\0')
			return (write(2, "Error\n", 6));
		ac = 0;
		input = ft_split(av[1], ' ');
		while (input[ac] != NULL)
			ac++;
		if (verify_input(ac, input, 0) == 6)
		{
			free(input);
			return (0);
		}
		set_arr(ac, input);
		while (i < ac)
			free(input[i++]);
		free(input);
	}
	else
	{
		if (verify_input(ac, av, 1) == 6)
			return (0);
		set_arr(ac - 1, &av[1]);
	}
	return (1);
}

/*
print_array(*arr_a,*arr_b, *size_a, *size_b);
sa(arr_a, arr_b, size_a, size_b);
write(1,"--> SA\n",7);
print_array(*arr_a,*arr_b, *size_a, *size_b);
ra(arr_a, arr_b, size_a, size_b);
write(1,"--> RA\n",7);
print_array(*arr_a,*arr_b, *size_a, *size_b);
pb(arr_a, arr_b, size_a, size_b);
write(1,"--> PB\n",7);
print_array(*arr_a,*arr_b, *size_a, *size_b);
pb(arr_a, arr_b, size_a, size_b);
write(1,"--> PB\n",7);
print_array(*arr_a,*arr_b, *size_a, *size_b);
pa(arr_a, arr_b, size_a, size_b);
write(1,"--> PA\n",7);
print_array(*arr_a,*arr_b, *size_a, *size_b);
rra(arr_a, arr_b, size_a, size_b);
write(1,"--> RRA\n",8);
print_array(*arr_a,*arr_b, *size_a, *size_b);
pb(arr_a, arr_b, size_a, size_b);
write(1,"--> PA\n",7);
print_array(*arr_a,*arr_b, *size_a, *size_b);
rrr(arr_a, arr_b, size_a, size_b);
write(1,"--> RRR\n",8);
print_array(*arr_a,*arr_b, *size_a, *size_b);
*/
