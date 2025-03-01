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

int	main(int ac, char *av[])
{
	char	**input;

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
			free_mem(input, ac);
			return (0);
		}
		set_arr(ac, input);
		free_mem(input, ac);
	}
	else
	{
		if (verify_input(ac, av, 1) == 6)
			return (0);
		set_arr(ac - 1, &av[1]);
	}
	return (1);
}
