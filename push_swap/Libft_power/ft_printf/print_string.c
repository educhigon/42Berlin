/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:33:30 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/21 11:28:17 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list args)
{
	char			*str;
	unsigned int	i;

	str = (char *)va_arg(args, char *);
	if (!str)
		return ((int)write(1, "(null)", 6));
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}
