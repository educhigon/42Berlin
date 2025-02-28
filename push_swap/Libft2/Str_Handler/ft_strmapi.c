/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:44:27 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/12 11:54:14 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	str_len;
	unsigned int	i;
	char			*new_str;

	if (!s)
		return (0);
	str_len = ft_strlen((char *)s);
	new_str = malloc((str_len + 1) * sizeof(char));
	if (!new_str)
		return (0);
	new_str[str_len] = '\0';
	i = 0;
	while (i < str_len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}
