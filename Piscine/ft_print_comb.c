/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:43:51 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/06 15:17:37 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	printing(char i, char j, char k)
{
	int	comma;
	int	space;

	comma = 44;
	space = 32;
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i == '7' && j == '8' && k == '9')
	{
		return (0);
	}
	write(1, &comma, 1);
	write(1, &space, 1);
	return (0);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = '0';
	while (i <= '9')
	{
		j = i + 1;
		while (j <= '9')
		{
			k = j + 1;
			while (k <= '9')
			{
				printing(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

// int main(){ ft_print_comb();}
