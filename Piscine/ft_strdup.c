/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:01:40 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/24 17:30:42 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new_s;
	int		size;
	int		i;

	size = 0;
	if (src == NULL)
		return (0);
	while (src[size] != '\0')
		size++;
	new_s = malloc(size * sizeof(char));
	i = 0;
	while (i < size)
	{
		new_s[i] = src[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
