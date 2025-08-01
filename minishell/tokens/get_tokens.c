/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:59:51 by jkolosow          #+#    #+#             */
/*   Updated: 2025/07/13 13:03:47 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	get_eof_token(char **s, t_token **tokens_ll)
{
	t_token	*token;

	if (**s == '\0')
	{
		token = malloc(sizeof(t_token));
		if (!token)
			return ;
		token->content = NULL;
		token->len = 1;
		token->next = NULL;
		token->fully_quoted = 0;
		token->type = TOKEN_EOF;
		ft_lstadd_back_token(tokens_ll, token);
	}
	return ;
}

void	get_text_fully_quoted(char **s, int quote)
{
	*s += 1;
	while (**s && **s != quote)
		*s += 1;
	*s += 1;
	return ;
}

void	get_word_token(char **s, t_token **tokens_ll)
{
	char	*start;
	char	*end;
	t_token	*token;

	start = *s;
	while (**s && !ft_isspace(**s) && !ismeta(**s))
	{
		if (isquoted(**s))
			get_text_fully_quoted(s, **s);
		else
			*s += 1;
	}
	end = *s;
	token = get_token(start, end);
	token->type = TOKEN_WORD;
	ft_lstadd_back_token(tokens_ll, token);
}

void	get_pipe_token(char **s, t_token **tokens_ll)
{
	char	*start;
	char	*end;
	t_token	*token;

	start = *s;
	*s += 1;
	end = *s;
	token = get_token(start, end);
	token->type = TOKEN_PIPE;
	ft_lstadd_back_token(tokens_ll, token);
}
