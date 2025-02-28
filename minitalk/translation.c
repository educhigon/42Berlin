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
	t_list *node;
	
	ft_printf("%c", digit);
	node = ft_lstnew(digit);
	ft_lstadd_back(lst, node);
	return ;

}

void	translate_char(t_list *list, int start, int end)
{
	char *str;
	char *converted_binary;
	int charac;

	if (start && end)
	{
		str = get_binary_num_from_signals(list, start, end);
		converted_binary = ft_convert_base(str, "01", "0123456789");
		charac = ft_atoi(converted_binary);
		write(1, &charac, 1);
	}
	return ;
}
int	convert_binary_str_to_int(char *str)
{
	int size;
	long unsigned int i;
	int power;

	power = 32768;
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
	return(size);
}

char *get_binary_num_from_signals(t_list *list,  int start, int end)
{
	t_list *current;
	int i;
	char *str;
	
	current = list;
	i = 0;
	str = malloc(17 * sizeof(char));
	while (i < end && current)
	{
		// ft_printf("i=%d\n", i);
		if (i >= start && i < end)
		{
			str[i - start] = *(char *)current->content;
			// ft_printf("str[i]= %c", str[i]);
		}
		current = current->next;
		i++;
	}
	str[i] = '\0';
	return(str);
}