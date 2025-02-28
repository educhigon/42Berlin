/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:51:20 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/23 11:45:30 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	final_nbr;
	int	power;

	final_nbr = 0;
	i = 0;
	power = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == '+'
		|| str[i] == '-')
	{
		if (str[i] == '-')
			power *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	while (str[i] >= '0' && str[i] <= '9')
	{
		final_nbr += (str[i] - '0') * power;
		power *= 10;
		i--;
	}
	return (final_nbr);
}
