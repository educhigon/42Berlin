/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:46:25 by edugonza          #+#    #+#             */
/*   Updated: 2025/02/28 13:14:28 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		check_base(char *base);
int		skip_beginning(char *nbr, int *count_neg);

void	substitute_num_by_base(int *final_nbr_helper, char *base,
		char *final_nbr, int helper_size)
{
	int	i;

	i = 0;
	if (final_nbr[0] == '-')
	{
		i = 1;
		helper_size++;
	}
	while (i <= helper_size)
	{
		if (final_nbr_helper[helper_size - i] < 0)
			final_nbr_helper[helper_size - i] *= -1;
		final_nbr[i] = base[final_nbr_helper[helper_size - i]];
		i++;
	}
}

void	convert_int_to_new_base(int nbr, char *base, char *final_nbr)
{
	int	i;
	int	base_size;
	int	final_nbr_helper[40];

	i = 0;
	while (i < 40)
		final_nbr[i++] = '\0';
	i = 0;
	if (nbr < 0)
	{
		final_nbr[0] = '-';
		i++;
	}
	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	while (nbr / base_size != 0)
	{
		final_nbr_helper[i] = (nbr % base_size);
		nbr /= base_size;
		i++;
	}
	final_nbr_helper[i] = (nbr % base_size);
	substitute_num_by_base(final_nbr_helper, base, final_nbr, i);
}

int	check_num_belongs_to_base(char *str, char *base, int i)
{
	int	j;
	int	flag;

	while (str[i] != '\0')
	{
		flag = 0;
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
				flag = 1;
			j++;
		}
		if (!flag)
			return (i);
		i++;
	}
	return (i--);
}

int	convert_arr_to_int_base(char *arr, int start_nbr, int end_nbr, char *base)
{
	long	final_nbr;
	int		j;
	int		power;
	int		base_size;

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	final_nbr = 0;
	power = 1;
	if (arr[start_nbr - 1] == '-')
		power = -1;
	while (end_nbr > start_nbr)
	{
		j = 0;
		while (base[j] != arr[end_nbr - 1])
			j++;
		if ((2147483647 < j * power + final_nbr || -2147483648 > j * power
				+ final_nbr))
			return (0);
		final_nbr += j * power;
		power *= base_size;
		end_nbr--;
	}
	return ((int)final_nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		start_nbr;
	int		count_neg;
	int		end_nbr;
	int		final_nbr;
	char	*final_nbr_final;

	final_nbr_final = (char *)malloc(40 * sizeof(char));
	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	count_neg = 1;
	start_nbr = skip_beginning(nbr, &count_neg);
	end_nbr = check_num_belongs_to_base(nbr, base_from, start_nbr);
	if (count_neg < 0)
		nbr[start_nbr - 1] = '-';
	final_nbr = convert_arr_to_int_base(nbr, start_nbr, end_nbr, base_from);
	if (final_nbr == 0)
		return (0);
	printf("nbr is: %d", final_nbr);
	convert_int_to_new_base(final_nbr, base_to, final_nbr_final);
	return (final_nbr_final);
}
/*
#include <stdio.h>

int	main(void)
{
	char nbr[] = "2147483647";
	char base_from[] = "0123456789";
	char base_to[] = "01";
	char *result;

	// write(1,"2147483647\n",10);
	result = ft_convert_base(nbr, base_from, base_to);
	printf("new number: %s\n", result);
}*/