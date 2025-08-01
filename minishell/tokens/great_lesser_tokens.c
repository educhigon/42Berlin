/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   great_lesser_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:53:06 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:53:11 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	get_greater_than_token(char **s, t_token **tokens_ll)
{
	char	*start;
	char	*end;
	t_token	*token;

	start = *s;
	*s += 1;
	if (**s && **s == '>')
	{
		*s += 1;
		end = *s;
		token = get_token(start, end);
		token->type = TOKEN_REDIRECT_OUT_APP;
	}
	else
	{
		end = *s;
		token = get_token(start, end);
		token->type = TOKEN_REDIRECT_OUT_TRUNC;
	}
	ft_lstadd_back_token(tokens_ll, token);
}

void	get_less_than_token(char **s, t_token **tokens_ll)
{
	char	*start;
	char	*end;
	t_token	*token;

	start = *s;
	*s += 1;
	if (**s && **s == '<')
	{
		*s += 1;
		end = *s;
		token = get_token(start, end);
		token->type = TOKEN_REDIRECT_HEREDOC;
	}
	else
	{
		end = *s;
		token = get_token(start, end);
		token->type = TOKEN_REDIRECT_IN;
	}
	ft_lstadd_back_token(tokens_ll, token);
}
