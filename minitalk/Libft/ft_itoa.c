/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:45:51 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/07 15:35:45 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	assing_num(int i, long ncpy, char *new_num)
{
	while ((i >= 0 && ncpy >= 0) || (i > 0 && ncpy < 0))
	{
		if (ncpy < 0)
			new_num[i] = (char)(-ncpy % 10 + '0');
		else
			new_num[i] = (char)(ncpy % 10 + '0');
		ncpy /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*new_num;
	int		i;
	long	ncpy;

	ncpy = n;
	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	new_num = malloc((i + 1) * sizeof(char));
	if (!new_num)
		return (0);
	new_num[i] = '\0';
	i--;
	assing_num(i, ncpy, new_num);
	if (n < 0)
		new_num[0] = '-';
	return (new_num);
}
