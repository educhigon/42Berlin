/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:28:16 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/13 15:09:32 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	power;
	char	printer;

	power = 1;
	while (n / power != 0)
		power *= 10;
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	power /= 10;
	while (power >= 1)
	{
		if (n < 0)
			printer = (char)(-(n / power) + '0');
		else
			printer = (char)(n / power + '0');
		write(fd, &printer, 1);
		n -= (n / power) * power;
		power /= 10;
	}
}
