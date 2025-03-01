/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:28:15 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/21 11:12:14 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

unsigned long	ft_strlen2(const char *str);
int				ft_printf(const char *str, ...);
int				print_char(va_list args);
int				print_string(va_list args);
int				print_void(va_list args);
int				print_decimal(va_list args);
int				print_integer(va_list args);
int				print_unsigned_decimal(va_list args);
int				print_hexa_lower(va_list args);
int				print_hexa_upper(va_list args);
int				ft_putchar_fd2(char c, int fd);
int				ft_putnbr_fd2(int n, int fd);
int				ft_putnbr_fd_unsigned(unsigned int n, int fd);

#endif
