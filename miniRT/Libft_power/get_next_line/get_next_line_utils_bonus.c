/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:20:30 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/28 15:35:15 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

unsigned long	ft_strlen2_bonus(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_bonus(char *str, int c)
{
	unsigned long	i;

	i = 0;
	if (str[0] == '\0' && (char)c == '\0')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((int)i);
		if (str[i + 1] == '\0' && (char)c == '\0')
			return ((int)i + 1);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_bonus(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen2_bonus((char *)s1);
	s2_len = ft_strlen2_bonus((char *)s2);
	new_str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i - s1_len < s2_len)
	{
		new_str[i] = s2[i - s1_len];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_substr_bonus(char const *s, unsigned int start, unsigned long len)
{
	unsigned int	str_len;
	unsigned int	i;
	char			*substr;

	if (!s)
		return (0);
	str_len = ft_strlen2_bonus((char *)s);
	if (start >= str_len)
		substr = malloc(sizeof(char));
	else if (start + len < str_len)
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
