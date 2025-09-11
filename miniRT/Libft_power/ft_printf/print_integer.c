/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:39:17 by edugonza          #+#    #+#             */
/*   Updated: 2025/03/17 15:00:44 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list args)
{
	int	value;

	value = va_arg(args, int);
	if (!value && value != 0)
		return (0);
	return (ft_putnbr_fd2((int)value, 1));
}
