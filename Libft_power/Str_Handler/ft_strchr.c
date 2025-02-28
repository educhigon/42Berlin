/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:28:55 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/13 14:11:21 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *str, int c)
{
	unsigned long	i;

	i = 0;
	if (str[0] == '\0' && (char)c == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (str + (int)i);
		if (str[i + 1] == '\0' && (char)c == '\0')
			return (str + (int)i + 1);
		i++;
	}
	return (0);
}
