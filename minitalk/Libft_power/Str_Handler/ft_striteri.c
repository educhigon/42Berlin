/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:59:39 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/12 11:54:00 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	str_len;
	unsigned int	i;

	if (!s)
		return ;
	str_len = ft_strlen((char *)s);
	s[str_len] = '\0';
	i = 0;
	while (i < str_len)
	{
		f(i, &s[i]);
		i++;
	}
}
