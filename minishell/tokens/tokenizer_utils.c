/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:58:35 by jkolosow          #+#    #+#             */
/*   Updated: 2025/07/13 13:09:42 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	isquoted(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	ismeta(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

void	skip_whitespace(char **s)
{
	while (**s && ft_isspace(**s))
		*s += 1;
}

void	go_to_end_of_quote(char **s, char quote)
{
	*s += 1;
	while (**s && **s != quote)
		*s += 1;
	*s += 1;
	if (**s && (**s == '\"' || **s == '\"'))
		go_to_end_of_quote(s, **s);
	return ;
}
