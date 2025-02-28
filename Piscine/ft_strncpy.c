/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:04:07 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/08 14:03:42 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				flag;

	i = 0;
	flag = 0;
	while (i < n)
	{
		if (src[i] == '\0')
			flag = 1;
		if (src[i] != '\0' && flag == 0)
		{
			dest[i] = src[i];
		}
		if (flag == 1)
		{
			dest[i] = '\0';
		}
		i++;
	}
	return (dest);
}
