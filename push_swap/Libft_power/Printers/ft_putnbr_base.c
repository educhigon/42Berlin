/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:30:33 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/23 15:11:57 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	check_base_size(char *base)
{
	int	base_size;

	base_size = 0;
	while (base[base_size])
		base_size++;
	return (base_size);
}

int	is_invalid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (i < check_base_size(base))
	{
		j = i + 1;
		while (j < check_base_size(base))
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	convert(int nbr, char *base)
{
	int		arr[40];
	int		i;
	int		base_size;
	char	temp;

	i = 0;
	base_size = check_base_size(base);
	while (nbr / base_size != 0)
	{
		arr[i] = nbr % base_size;
		if (arr[i] < 0)
			arr[i] *= -1;
		nbr /= base_size;
		i++;
	}
	arr[i] = nbr % base_size;
	if (arr[i] < 0)
		arr[i] *= -1;
	while (i >= 0)
	{
		temp = base[arr[i]];
		write(1, &temp, 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;

	base_size = check_base_size(base);
	if (base_size < 2)
		return ;
	if (is_invalid_base(base))
		return ;
	else
	{
		if (nbr < 0)
			write(1, "-", 1);
		convert(nbr, base);
	}
}
