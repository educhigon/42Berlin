/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:48:57 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/04 16:51:43 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (size);
	i = 0;
	while (src[i] != '\0')
	{
		if (i < size - 1 && src[i] != '\0')
			dest[i] = src[i];
		if ((i + 1 == size -1 || src[i + 1] == '\0') && dest[i] != '\0')
			dest[i + 1] = '\0';
		i++;
	}
	return (i);
}
