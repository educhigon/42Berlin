/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:40:18 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/21 11:27:28 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_upper(va_list args)
{
	unsigned long	value;
	unsigned long	power;
	int				counter;
	char			*letters;

	letters = "0123456789ABCDEF";
	value = (unsigned int)va_arg(args, unsigned int);
	counter = 0;
	if (!value && value != 0)
		return (counter);
	power = 1;
	while (value / power >= 16)
		power *= 16;
	while (power > 0)
	{
		write(1, &letters[value / power], 1);
		value %= power;
		power /= 16;
		counter++;
	}
	return (counter);
}
