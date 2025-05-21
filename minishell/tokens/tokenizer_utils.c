/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:58:35 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/21 12:06:36 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ismeta(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

void	skip_whitespace_with_token(char **s,  t_token **tokens_ll)
{
	int flag = 0;
	char	*end;
	t_token	*token;

	while (**s && ft_isspace(**s))
	{
		flag++;
		if (flag == 1)
		{
			end = *s + 1;
			token = get_token(*s, end);
			token->type = TOKEN_SPACE;
			ft_lstadd_back_token(tokens_ll, token);
		}
		*s += 1;
	}
	return ;
}

void	skip_whitespace(char **s)
{
	while (**s && ft_isspace(**s))
		*s += 1;
}
