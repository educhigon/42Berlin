/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:54:59 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/15 12:16:27 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_token	*tokenize(char *line)
{
	t_token	*tokens_ll;

	tokens_ll = NULL;
	if (*line == '\0')
		return (NULL);
	while (*line)
	{
		skip_whitespace(&line, &tokens_ll);
		if (*line)
		{
			if (*line == '|')
				get_pipe_token(&line, &tokens_ll);
			else if (*line == '<')
				get_less_than_token(&line, &tokens_ll);
			else if (*line == '>')
				get_greater_than_token(&line, &tokens_ll);
			else if (*line == '"')
				get_double_quote_token(&line, &tokens_ll);
			else if (*line == '\'')
				get_single_quote_token(&line, &tokens_ll);
			else
				get_word_token(&line, &tokens_ll);
		}
	}
	return (tokens_ll);
}

t_token	*get_token(char *start, char *end)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->content = malloc((end - start) + 1 * sizeof (char));
	if (!(token->content))
	{
		free(token);
		return (NULL);
	}
	ft_strlcpy(token->content, start, end - start + 1);
	token->fully_quoted = 0;
	token->len = end - start;
	token->next = NULL;
	return (token);
}
