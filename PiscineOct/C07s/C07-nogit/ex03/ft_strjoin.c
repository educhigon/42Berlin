/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:12:25 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/22 14:47:38 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_final_size(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	count_chars;

	i = 0;
	count_chars = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		count_chars += j;
		j = 0;
		if (i != size - 1)
			while (sep[j] != '\0')
				j++;
		count_chars += j;
		i++;
	}
	return (count_chars + 1);
}

int	copy_string(char *str_return, char *strs, int count_chars)
{
	int	j;

	j = 0;
	while (strs[j] != '\0')
	{
		str_return[count_chars] = strs[j];
		j++;
		count_chars++;
	}
	return (count_chars);
}

char	*concat_everything(int size, char **strs, char *sep, char *str_return)
{
	int	i;
	int	count_chars;

	i = 0;
	count_chars = 0;
	while (i < size)
	{
		count_chars = copy_string(str_return, strs[i], count_chars);
		count_chars = copy_string(str_return, sep, count_chars);
		i++;
	}
	str_return[count_chars + 1] = '\0';
	return (str_return);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_return ;

	if (size == 0)
	{
		str_return = malloc(1 * sizeof(char));
		return (str_return);
	}
	str_return = malloc(get_final_size(size, strs, sep) * sizeof(char));
	str_return = concat_everything(size, strs, sep, str_return);
	return (str_return);
}
