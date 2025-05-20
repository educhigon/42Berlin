/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkolosow <jkolosow@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:56:59 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/09 11:44:37 by jkolosow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;

	if (!dest && !src)
		return (NULL);
	dest_ptr = dest;
	while (n > 0)
	{
		*dest_ptr = *((char *)src);
		++dest_ptr;
		++src;
		--n;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	char	*src_copy;

	src_copy = (char *)src;
	if (!(*src))
	{
		ft_memcpy(dst, src, 1);
		return (0);
	}
	if (dsize > 0)
	{
		if (dsize > ft_strlen(src))
		{
			ft_memcpy(dst, src, ft_strlen(src));
			dst[ft_strlen(src)] = '\0';
		}
		else if (dsize > 0)
		{
			ft_memcpy(dst, src, (dsize - 1));
			dst[dsize - 1] = '\0';
		}
	}
	return (ft_strlen(src_copy));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		++s;
		++len;
	}
	return (len);
}
