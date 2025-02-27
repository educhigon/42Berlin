/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:52:37 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/14 15:33:14 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_stop(char const *s1, char const *set, int i_start, int ite)
{
	unsigned int	stop;
	unsigned int	i;
	unsigned int	j;
	unsigned int	s1_len;

	stop = 0;
	i = i_start;
	s1_len = ft_strlen((char *)s1);
	while (i < s1_len && stop == 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				stop = 1;
			j++;
		}
		if (stop == 0)
			break ;
		stop = 0;
		i += ite;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str_trim;
	unsigned int	s1_len;
	int				start;
	int				end;
	int				i;

	if (!s1)
		return (0);
	s1_len = ft_strlen((char *)s1);
	end = count_stop(s1, set, s1_len - 1, -1);
	start = count_stop(s1, set, 0, 1);
	if (end < start)
		return (ft_strdup(""));
	str_trim = malloc((end - start + 2) * sizeof(char));
	if (!str_trim)
		return (0);
	i = 0;
	while (start + i <= end && s1[start + i] != '\0')
	{
		str_trim[i] = s1[start + i];
		i++;
	}
	str_trim[i] = '\0';
	return (str_trim);
}
