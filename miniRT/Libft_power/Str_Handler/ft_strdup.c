/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:06:48 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/14 11:23:09 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	unsigned int	size;
	char			*dup;

	size = 0;
	while (s[size] != '\0')
		size++;
	size++;
	if (size != 0)
	{
		dup = malloc(size * sizeof(char));
		if (!dup)
			return (0);
		i = 0;
		while (s[i] != '\0')
		{
			dup[i] = s[i];
			i++;
		}
		dup[i] = s[i];
		return (dup);
	}
	return (0);
}
