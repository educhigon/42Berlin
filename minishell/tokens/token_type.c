/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:42:30 by edugonza          #+#    #+#             */
/*   Updated: 2025/05/20 19:31:12 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_token_type	get_type_pipe(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line == '|')
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
	while (*line && *line == '<')
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
	while (*line && *line == '>')
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

/*
t_token_type	get_type_subshell(char *line)
{
	if (*line == '(')
		return (TOKEN_SUB_OPEN);
	else if (*line == ')')
		return (TOKEN_SUB_CLOSE);
	return (TOKEN_ERROR);
}*/


t_token_type	get_type_word(char *line)
{
	char	c;
	int		in_quote;

	in_quote = 0;
	while (*line)
	{
		if (*line && *(line + 1) == '\\')
			line++;//or line += 2;
		else if (*line == '\"' || *line == '\'')
		{
			if (in_quote == 0)
			{
				in_quote = 1;
				c = *line;
			}
			else if (in_quote == 1 && c == *line)
				in_quote = 0;
		}
		else if ((ismeta(*line) || ft_isspace(*line)) && in_quote == 0)
			break ;
		line++;
	}
	if (in_quote == 1)
		return (TOKEN_ERROR);
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
	//else if (*line =='(' || *line == ')')
	//	return(get_type_subshell(line));
	return (get_type_word(line));
}
