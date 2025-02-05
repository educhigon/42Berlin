/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:05:43 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/20 10:11:21 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (!lst)
		return ;
	ptr = *lst;
	while ((*lst))
	{
		ptr = (*lst);
		(*lst) = (*lst)->next;
		del((ptr)->content);
		free((ptr));
	}
	*lst = NULL;
	free(*lst);
	return ;
}
