/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:40:25 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/20 10:24:11 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*free_all(char **new_str, int word)
{
	int	i;

	i = 0;
	while (i < word)
	{
		free(new_str[i]);
		i++;
	}
	free(new_str);
	return (NULL);
}

static int	build_new_arr(char const *s, char c, unsigned int i, char **new_str)
{
	unsigned int	j;
	unsigned int	k;

	j = i;
	while (s[j] != c && s[j] != '\0')
		j++;
	*new_str = malloc ((j - i + 1) * sizeof (char));
	if (!(*new_str))
		return (0);
	k = 0;
	while (i < j)
	{
		(*new_str)[k] = s[i];
		i++;
		k++;
	}
	(*new_str)[k] = '\0';
	return (i);
}

static int	count_str_words(char const *s, char c)
{
	unsigned int	count_words;
	unsigned int	i;

	i = 0;
	count_words = 0;
	if (s[i] != c)
		count_words++;
	i++;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count_words++;
		i++;
	}
	return (count_words);
}

char	**ft_split(char const *s, char c)
{
	char			**new_str;
	unsigned int	i;
	unsigned int	word;

	if (!s)
		return (0);
	new_str = malloc((count_str_words(s, c) + 1) * sizeof(char *));
	if (!new_str)
		return (0);
	i = 0;
	word = 0;
	while (s[i] != '\0' && s[0] != 0)
	{
		if (s[i] != c)
		{
			i = build_new_arr(s, c, i, &new_str[word]);
			if (i == 0)
				return (free_all(new_str, word));
			word++;
		}
		else
			i++;
	}
	new_str[word] = 0;
	return (new_str);
}
