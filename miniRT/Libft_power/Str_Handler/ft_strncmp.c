/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:50:43 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/13 14:19:53 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((unsigned char)s2[i] == (unsigned char)s1[i]
		&& (unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0'
		&& i < n - 1)
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
