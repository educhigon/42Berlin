/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:23:47 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/13 14:11:59 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *str, int c)
{
	unsigned long	i;
	long			j;

	i = 0;
	j = -1;
	if (str[0] == '\0' && (char)c == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			j = i;
		if (str[i + 1] == '\0' && (char)c == '\0')
			j = i + 1;
		i++;
	}
	if (j == -1)
		return (0);
	return (str + j);
}
