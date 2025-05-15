/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 18:19:58 by edugonza          #+#    #+#             */
/*   Updated: 2025-05-06 18:19:58 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_tokens(t_token *token)
{
	//int	i;

	//i = 0;
	if (token == NULL)
		printf("There are no tokens\n");
	else
	{
		while (token)
		{
			printf("token->content:\t'%s'\n", token->content);
			printf("token->type:\t%d\n", token->type);
			printf("token->len:\t%zu\n", token->len);
			printf("token->fully_quoted:\t%d\n", token->fully_quoted);
			printf("token->next:\t[%p]\n", token->next);
			putchar('\n');
			token = token->next;
		}
	}
	return ;
}
