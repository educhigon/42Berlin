/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:36:50 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/20 10:19:38 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned long len)
{
	unsigned int	str_len;
	unsigned int	i;
	char			*substr;

	if (!s)
		return (0);
	str_len = ft_strlen((char *)s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (start + len < str_len)
		substr = malloc((len + 1) * sizeof(char));
	else
		substr = malloc((str_len - start + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[i] != '\0' && str_len > start)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
