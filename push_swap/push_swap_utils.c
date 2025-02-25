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

long long	ft_atoi_here(const char *str)
{
	int			i;
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

void	print_array(int **arrays, int *sizes)
{
	int	i;

	i = 0;
	write(1, "\n A  B\n[", 8);
	ft_putnbr_fd(sizes[0], 1);
	write(1, "][", 2);
	ft_putnbr_fd(sizes[1], 1);
	write(1, "]\n------\n", 9);
	while (i < sizes[0] || i < sizes[1])
	{
		write(1, " ", 1);
		if (i < sizes[0])
			ft_putnbr_fd(arrays[0][i], 1);
		write(1, "  ", 2);
		if (i < sizes[1])
			ft_putnbr_fd(arrays[1][i], 1);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 2);
	return ;
}

int	i_ate(int size, int index)
{
	if (size - index <= index)
		return (1);
	return (0);
}

void	create_helper_num(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}
