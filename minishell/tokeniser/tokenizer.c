/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:54:59 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/20 11:59:21 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
t_token	*tokenize(char *line)
{
	t_token	*tokens_ll;

	tokens_ll = NULL;
	if (*line == '\0')
		return (NULL);
	while (*line)
	{
		skip_whitespace(&line);
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
}*/

t_token	*tokenize(char *line)
{
	t_token			*tokens_ll;
	t_token_type	type;

	tokens_ll = NULL;
	if (*line == '\0')
		return (NULL);
	while (*line)
	{
		skip_whitespace(&line);
		if (*line)
		{
			type = get_token_type(line);
			if (type == TOKEN_ERROR)
			{
				printf("Error: invalid token\n");
				return (NULL);
			}
			else if (type == TOKEN_PIPE)
				get_pipe_token(&line, &tokens_ll);
			else if (type == TOKEN_REDIRECT_IN || type == TOKEN_HEREDOC)
				get_less_than_token(&line, &tokens_ll);
			else if (type == TOKEN_REDIRECT_OUT_APP || type == TOKEN_REDIRECT_OUT_TRUNC)
				get_greater_than_token(&line, &tokens_ll);
			//else if (type == TOKEN_SUB_OPEN || type == TOKEN_SUB_CLOSE)
			//	printf("Error: subshell not implemented yet\n");
			//	implement this: get_subshell_token(&line, &tokens_ll);
			else if (type == TOKEN_WORD)
				get_word_token(&line, &tokens_ll);
			else
			{
				printf("unknown Error\n");
				return (NULL);
			}
		}
	}
	return (tokens_ll);
}

t_token_type	get_token_type(char *line)
{
	if (*line == '|')
		return (get_type_pipe(line));
	else if (*line == '<')
		return (get_type_redirectin(line));
	else if (*line == '>')
		return (get_type_redirectout(line));
	//else if (*line =='(' || *line == ')')
	//	return(get_type_subshell(line));
	return (get_type_word(line));
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
	token->len = end - start;
	token->next = NULL;
	return (token);
}
