/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:07:57 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/21 12:24:34 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argv, char **argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argv)
	{
		j = 0;
		while (argc[i][j])
		{
			write (1, &argc[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}
