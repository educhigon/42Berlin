/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:13:45 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/14 11:27:13 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	helper(unsigned char *de, unsigned char *sr, unsigned long n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		de[i] = sr[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, unsigned long n)
{
	unsigned long	i;
	unsigned char	*de;
	unsigned char	*sr;

	de = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (n != 0 && (src || dest))
	{
		if (dest > src)
		{
			i = n;
			while (i-- > 0)
				de[i] = sr[i];
		}
		else
			helper(de, sr, n);
	}
	return (dest);
}
