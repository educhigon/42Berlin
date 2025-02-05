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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((unsigned char)s2[i] == (unsigned char)s1[i] && 
		(unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0' 
		&& i < n - 1)
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}