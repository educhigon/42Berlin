/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:55:10 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/20 15:39:11 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	nullify_num(char *num)
{
	num[0] = '\0';
	num[1] = '\0';
	num[2] = '\0';
	num[3] = '\0';
}

void	reduce_number(char *nbr)
{
	if (nbr[0] == '0')
	{
		if (nbr[1] == '0')
		{
			nbr[0] = nbr[2];
			nbr[1] = '\0';
			nbr[2] = '\0';
		}
		else
		{
			nbr[0] = nbr[1];
			nbr[1] = nbr[2];
			nbr[2] = '\0';
		}
	}
}

void	zero_file_control(int *file_control, int nbr_lines)
{
	int	i;

	i = 0;
	while (i < nbr_lines)
	{
		file_control[i] = 0;
		i++;
	}
}

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

void	write_num(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i] != 0)
	{
		write (1, &(nbr[i]), 1);
		i++;
	}
	write (1, " ", 1);
}
