/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:02:21 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/21 12:24:21 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argv, char **argc)
{
	int	i;

	i = 0;
	while (argc[0][i] != '\0')
	{
		write (1, &argc[0][i], 1);
		if (argv)
			i++;
	}
}
