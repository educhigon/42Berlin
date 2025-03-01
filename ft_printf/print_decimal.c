/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:39:00 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/21 11:49:22 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(va_list args)
{
	unsigned int	counter;
	int				value;

	value = (int)va_arg(args, int);
	if (!value && value != 0)
		return (0);
	counter = (ft_putnbr_fd2((int)value, 1));
	return (counter);
}
