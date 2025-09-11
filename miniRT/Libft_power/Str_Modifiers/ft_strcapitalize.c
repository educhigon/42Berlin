/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:10:58 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/09 19:21:09 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha(char *str)
{
	if ((*str < 'A') || (*str > 'Z' && *str < 'a') || (*str > 'z'))
		return (0);
	return (1);
}

int	ft_char_is_numeric(char *str)
{
	if (*str < '0' || *str > '9')
		return (0);
	return (1);
}

void	capitalize(char *str, int i)
{
	int	flag;

	flag = 0;
	if ((!ft_char_is_alpha(&str[i - 1]) && !ft_char_is_numeric(&str[i - 1])))
		flag = 1;
	if (flag && (ft_char_is_alpha(&str[i]) || ft_char_is_numeric(&str[i])))
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
			str[i] = str[i] - 32;
	}
	else
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] = str[i] + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	if ((str[i] >= 'a') && (str[i] <= 'z'))
		str[i] = str[i] - 32;
	i++;
	while (str[i])
	{
		capitalize(str, i);
		i++;
	}
	return (str);
}
