/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:54:22 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/09 18:09:48 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexa_converter(char i, char *arr)
{
	int	hex;

	arr[1] = i / 16 + '0';
	hex = i % 16;
	if (hex == 10)
		arr[2] = 'a';
	else if (hex == 11)
		arr[2] = 'b';
	else if (hex == 12)
		arr[2] = 'c';
	else if (hex == 13)
		arr[2] = 'd';
	else if (hex == 14)
		arr[2] = 'e';
	else if (hex == 15)
		arr[2] = 'f';
	else
		arr[2] = hex + '0';
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		j;
	char	arr[3];

	arr[0] = '\\';
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32) || (str[i] > 126))
		{
			hexa_converter(str[i], arr);
			j = 0;
			while (j <= 2)
			{
				write(1, &arr[j], 1);
				j++;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
