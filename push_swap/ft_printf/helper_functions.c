/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:09:28 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/21 11:25:48 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long	ft_strlen_2(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	define_printer(int n, int power, int fd)
{
	char	printer;

	if (n < 0)
		printer = (char)(-(n / power) + '0');
	else
		printer = (char)(n / power + '0');
	write(fd, &printer, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

int	ft_putnbr_fd_2(int n, int fd)
{
	long	power;
	int		counter;

	power = 1;
	counter = 0;
	if (!n && n != 0)
		return (0);
	if (n == 0)
		return (write(fd, "0", 1));
	if (n < 0)
		counter = write(fd, "-", 1);
	while (n / power != 0)
		power *= 10;
	power /= 10;
	while (power >= 1)
	{
		counter++;
		define_printer(n, power, fd);
		n %= power;
		power /= 10;
	}
	return (counter);
}

int	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	unsigned long	power;
	char			printer;
	int				counter;

	power = 1;
	counter = 0;
	if (!n && n != 0)
		return (0);
	if (n == 0)
		return (write(fd, "0", 1));
	while (n / power >= 10)
		power *= 10;
	while (power > 0)
	{
		counter++;
		printer = (char)(n / power + '0');
		write(fd, &printer, 1);
		n %= power;
		power /= 10;
	}
	return (counter);
}
