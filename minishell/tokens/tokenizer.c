/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:54:59 by jkolosow          #+#    #+#             */
/*   Updated: 2025/07/25 15:34:42 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

/**
 * Handles token based on its type
 */
static int	handle_token_type(t_token_type type, char **line,
	t_token **tokens_ll)
{
	if (type == TOKEN_PIPE)
		get_pipe_token(line, tokens_ll);
	else if (type == TOKEN_REDIRECT_IN || type == TOKEN_REDIRECT_HEREDOC)
		get_less_than_token(line, tokens_ll);
	else if (type == TOKEN_REDIRECT_OUT_APP || type == TOKEN_REDIRECT_OUT_TRUNC)
		get_greater_than_token(line, tokens_ll);
	else if (type == TOKEN_WORD)
		get_word_token(line, tokens_ll);
	else
	{
		printf("unknown Error\n");
		return (0);
	}
	return (1);
}

/**
 * Process a single token from the input
 */
static int	process_token(char **line, t_token **tokens_ll, t_shell *shell)
{
	t_token_type	type;

	type = get_token_type(*line);
	if (type == TOKEN_ERROR)
	{
		print_errors(shell, "Error", "invalid token", 1);
		return (0);
	}
	return (handle_token_type(type, line, tokens_ll));
}

/**
 * Tokenize input line into a linked list of tokens
 */
t_token	*tokenize(char *line, t_shell *shell)
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
			if (!process_token(&line, &tokens_ll, shell))
				return (NULL);
		}
	}
	get_eof_token(&line, &tokens_ll);
	return (tokens_ll);
}

t_token	*get_token(char *start, char *end)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->fully_quoted = 0;
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

int	get_more_tokens(t_token *tokens, t_shell *shell)
{
	char		*line;

	line = readline("> ");
	while (line && !ft_strlen(line))
		line = readline("> ");
	if (line == NULL)
	{
		print_errors(shell, "syntax error", "unexpected end of file", 2);
		ft_putstr_fd("supershell: exit\n", 2);
		return (1);
	}
	add_history(line);
	free(tokens->next);
	tokens->next = tokenize(line, shell);
	return (0);
}
