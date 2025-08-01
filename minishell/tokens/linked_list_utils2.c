/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:41:16 by jkolosow          #+#    #+#             */
/*   Updated: 2025/07/13 13:05:51 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_token	*ft_lstnew_token(void *content)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize_token(t_token *lst)
{
	unsigned long	i;
	t_token			*ptr;

	if (!lst)
		return (0);
	i = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
