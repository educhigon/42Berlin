/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 19:25:10 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-25 19:25:10 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	commands_to_sort(int **arrays, int *sizes)
{
	int	input;
	int	valid;

	valid = 1;
	input = getchar();
	while (input != EOF && valid == 1)
	{
		if (input == 's' && valid == 1)
			valid = check_s(arrays, sizes);
		else if (input == 'p' && valid == 1)
			valid = check_p(arrays, sizes);
		else if (input == 'r' && valid == 1)
			valid = check_r(arrays, sizes);
		else if ((input != '\n' && valid == 1) || valid == 0)
		{
			write(2, "Error\n", 6);
			return ;
		}
		input = getchar();
	}
	if (sizes[1] == 0 && is_a_sorted(arrays[0], sizes[0]))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

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
	commands_to_sort(arrays, sizes);
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
