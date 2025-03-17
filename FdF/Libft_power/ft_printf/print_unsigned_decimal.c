/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:39:38 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/21 11:28:36 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_decimal(va_list args)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	if (!value && value != 0)
		return (0);
	return (ft_putnbr_fd_unsigned(value, 1));
}
