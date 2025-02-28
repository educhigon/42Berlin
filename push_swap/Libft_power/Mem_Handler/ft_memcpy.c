/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:34:29 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/13 16:30:46 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned long n)
{
	unsigned int	i;
	unsigned char	*de;
	unsigned char	*sr;

	de = (unsigned char *)dest;
	sr = (unsigned char *)src;
	i = 0;
	if (!src && !dest)
		return (0);
	if (n != 0 || !src || !dest)
	{
		while (i < n)
		{
			de[i] = sr[i];
			i++;
		}
	}
	return (dest);
}
