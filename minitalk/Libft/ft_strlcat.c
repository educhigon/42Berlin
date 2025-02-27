/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:51:18 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/14 11:22:55 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size_dest;
	unsigned int	size_src;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	i = size_dest;
	j = 0;
	while (src[j] != '\0' && i < size - 1 && size != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < size_dest)
		return (size_src + size);
	return (size_dest + size_src);
}
