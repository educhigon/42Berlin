/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:48:40 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/24 15:59:07 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int		i;
	int		j;
	char	*arr;

	i = 0;
	arr = base;
	while (base[i])
		i++;
	if (i < 2)
		return (0);
	while (base[i])
	{
		j = 0;
		while (j < i)
		{
			if (base[i] == arr[j++])
				return (0);
			if (base[i] <= '0' && base[i] >= '9')
				if (base[i] <= 'a' && base[i] >= 'z')
					if (base[i] <= 'A' && base[i] >= 'Z')
						return (0);
		}
		i--;
	}
	return (1);
}

int	skip_beginning(char *nbr, int *count_neg)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			*count_neg *= -1;
		i++;
	}
	return (i);
}
