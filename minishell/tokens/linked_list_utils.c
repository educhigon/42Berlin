/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:41:16 by jkolosow          #+#    #+#             */
/*   Updated: 2025/07/13 13:02:37 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	del_content_token(void *content)
{
	char	*token;

	token = (char *) content;
	if (token)
		free(token);
	return ;
}

void	ft_lstadd_back_token(t_token **lst, t_token *new)
{
	t_token	*ptr;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

void	ft_lstdelone_token(t_token *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	return ;
}

t_token	*ft_token_last(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear_token(t_token **lst, void (*del)(void *))
{
	t_token	*temp;

	if (!(*lst) || !del)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone_token(temp, del);
	}
	return ;
}
