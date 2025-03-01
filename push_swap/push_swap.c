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
	int	*arrays[2];
	int	sizes[2];

	arrays[0] = malloc((ac + 1) * sizeof(int));
	arrays[1] = malloc((ac + 1) * sizeof(int));
	if (arrays[0] == NULL || arrays[1] == NULL)
		return ;
	sizes[0] = ac;
	sizes[1] = 0;
	i = 0;
	while (i < ac)
	{
		arrays[0][i] = ft_atoi_here(av[i]);
		i++;
	}
	sort(arrays, sizes);
	free(arrays[0]);
	free(arrays[1]);
	return ;
}

int	main(int ac, char *av[])
{
	char	**input;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (ft_strncmp(av[1], "", 1) == 0)
			return (write(2, "Error\n", 6));
		ac = 0;
		input = ft_split(av[1], ' ');
		while (input[ac] != NULL)
			ac++;
		if (verify_input(ac, input, 0) != 6)
			set_arr(ac, input);
		free_mem(input, ac);
		return (0);
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
