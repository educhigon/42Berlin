/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:50:51 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/23 11:45:32 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		i;
	int		nbr[11];
	char	temp;

	if (nb < 0)
		write(1, "-", 1);
	i = 0;
	while (nb / 10 != 0)
	{
		nbr[i] = nb % 10;
		if (nbr[i] < 0)
			nbr[i] *= -1;
		nb = nb / 10;
		i++;
	}
	nbr[i] = nb % 10;
	if (nbr[i] < 0)
		nbr[i] *= -1;
	while (i >= 0)
	{
		temp = nbr[i] + '0';
		write(1, &temp, 1);
		i--;
	}
}
