/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:25:13 by edugonza          #+#    #+#             */
/*   Updated: 2025/02/05 17:09:54 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

long long	ft_atoi_here(const char *str)
{
	int	i;
	long long	final_nbr;
	long long	power;

	final_nbr = 0;
	i = 0;
	power = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			power *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		final_nbr = final_nbr * 10 + (long long)((str[i] - '0') * power);
		i++;
	}
	return (final_nbr);
}

int	check_int(char *str)
{
	int	j;

	j = 0;
	if (str[j] == '-')
		j++;
	while (j < ft_strlen(str))
	{
		if (str[j] < '0' || str[j] > '9')
			return (0);
		j++;
	}
	return (1);
}

int	check_big_int(char *str)
{
	if (ft_atoi_here(str) > 2147483647 || ft_atoi_here(str) < -2147483648)
		return (0);
	return (1);
}

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

int	i_ATE(int size, int index)
{
	if (size - index < index)
		return (1);
	return (0);
}
