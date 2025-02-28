/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:18:43 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/21 12:24:41 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argv, char **argc)
{
	int	i;
	int	j;

	i = argv - 1;
	j = 0;
	while (i > 0)
	{
		j = 0;
		while (argc[i][j])
		{
			write (1, &argc[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
}
