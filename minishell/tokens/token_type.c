/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:42:30 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/13 13:07:46 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_token_type	get_type_pipe(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line == '|' && len < 1)
	{
		len++;
		line++;
	}
	if (len == 1)
		return (TOKEN_PIPE);
	return (TOKEN_ERROR);
}

t_token_type	get_type_redirectin(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line == '<' && len < 2)
	{
		len++;
		line++;
	}
	if (len == 1)
		return (TOKEN_REDIRECT_IN);
	else if (len == 2)
		return (TOKEN_REDIRECT_HEREDOC);
	return (TOKEN_ERROR);
}

t_token_type	get_type_redirectout(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line == '>' && len < 2)
	{
		len++;
		line++;
	}
	if (len == 1)
		return (TOKEN_REDIRECT_OUT_TRUNC);
	else if (len == 2)
		return (TOKEN_REDIRECT_OUT_APP);
	return (TOKEN_ERROR);
}

t_token_type	get_type_word(char *line)
{
	int		quote;

	quote = 0;
	while (*line)
	{
		if (*line && *(line + 1) == '\\')
			line++;
		else if (*line == '\"' || *line == '\"')
		{
			quote = *line;
			go_to_end_of_quote(&line, quote);
			line--;
			if (*line != quote)
				return (TOKEN_ERROR);
			line++;
		}
		else if ((ismeta(*line) || ft_isspace(*line)))
			break ;
		line++;
	}
	return (TOKEN_WORD);
}

t_token_type	get_token_type(char *line)
{
	if (*line == '|')
		return (get_type_pipe(line));
	else if (*line == '<')
		return (get_type_redirectin(line));
	else if (*line == '>')
		return (get_type_redirectout(line));
	return (get_type_word(line));
}
