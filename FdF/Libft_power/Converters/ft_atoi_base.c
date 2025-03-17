/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:25:00 by edugonza          #+#    #+#             */
/*   Updated: 2025/02/28 11:53:56 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base_size2(char *base)
{
	int	base_size;

	base_size = 0;
	while (base[base_size])
		base_size++;
	return (base_size);
}

int	check_num_belongs_to_base(char str, char *base)
{
	int	j;

	j = 0;
	while (base[j] != '\0')
	{
		if (base[j] == str)
			return (1);
		j++;
	}
	return (0);
}

int	convert_arr_to_int_base(char *nbr, int start_nbr, int end_nbr, char *base)
{
	int	j;
	int	power;
	int	base_size;
	int	nbr_base10;

	base_size = 0;
	power = 1;
	nbr_base10 = 0;
	while (base[base_size])
		base_size++;
	while (start_nbr <= end_nbr)
	{
		j = 0;
		while (nbr[end_nbr] != base[j])
			j++;
		nbr_base10 += j * power;
		power *= base_size;
		end_nbr--;
	}
	return (nbr_base10);
}

int	is_base_invalid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (i < check_base_size2(base))
	{
		j = i + 1;
		while (j < check_base_size2(base))
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	final_nbr;
	int	power;

	final_nbr = 0;
	i = 0;
	power = 1;
	if (is_base_invalid(base))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == '+'
		|| str[i] == '-')
	{
		if (str[i] == '-')
			power *= -1;
		i++;
	}
	j = i;
	while (check_num_belongs_to_base(str[j], base))
		j++;
	j--;
	final_nbr = convert_arr_to_int_base(str, i, j, base);
	if (power < 0)
		final_nbr *= -1;
	return (final_nbr);
}
