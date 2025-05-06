/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:38:30 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/21 11:28:58 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_void(va_list args)
{
	unsigned long	value;
	unsigned long	power;
	char			*letters;
	int				counter;

	letters = "0123456789abcdef";
	value = (unsigned long)va_arg(args, void *);
	if (!value)
		return ((int)write(1, "(nil)", 5));
	write(1, "0x", 2);
	counter = 2;
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
