/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:20:29 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/28 17:15:42 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_special_print(char c, va_list args)
{
	if (c == 'c')
		return (print_char(args));
	if (c == 's')
		return (print_string(args));
	if (c == 'p')
		return (print_void(args));
	if (c == 'd')
		return (print_decimal(args));
	if (c == 'i')
		return (print_integer(args));
	if (c == 'u')
		return (print_unsigned_decimal(args));
	if (c == 'x')
		return (print_hexa_lower(args));
	if (c == 'X')
		return (print_hexa_upper(args));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		str_len;
	int		i;
	int		char_count;

	char_count = 0;
	str_len = ft_strlen2(str);
	va_start(args, str);
	i = 0;
	while (i < str_len)
	{
		if (str[i] == '%')
			char_count += find_special_print(str[++i], args);
		else
		{
			write(1, &str[i], 1);
			char_count++;
		}
		i++;
	}
	return (char_count);
}
