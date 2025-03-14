/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-27 08:29:31 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-27 08:29:31 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	add_signal(t_list **lst, char *digit)
{
	t_list	*node;

	node = ft_lstnew(digit);
	if (!node)
		return ;
	ft_lstadd_back(lst, node);
	return ;
}

void	translate_char(t_list *list, int start, int end)
{
	char	*str;
	char	charac;
	int		i;

	if (start && end)
	{
		str = get_binary_num_from_signals(list, start, end);
		charac = 0;
		i = 0;
		while (i < 8)
		{
			charac = charac << 1;
			if (str[i] == '1')
				charac = charac | 1;
			i++;
		}
		write(1, &charac, 1);
		free(str);
	}
	return ;
}

int	convert_binary_str_to_int(char *str)
{
	long unsigned int	i;
	long				size;
	long				power;

	power = 2147483648;
	i = 0;
	size = 0;
	while (i < ft_strlen(str) - 1)
	{
		if (str[i] != '0')
			size += power;
		power /= 2;
		i++;
	}
	if (str[i] != '0')
		size++;
	return ((int)size);
}

char	*get_binary_num_from_signals(t_list *list, int start, int end)
{
	t_list	*current;
	int		i;
	int		j;
	char	*str;

	current = list;
	i = 0;
	j = 0;
	str = malloc(33 * sizeof(char));
	while (i < end && current)
	{
		if (j < end - start && i >= start)
		{
			str[j] = *(char *)current->content;
			j++;
		}
		current = current->next;
		i++;
	}
	str[j] = '\0';
	return (str);
}
