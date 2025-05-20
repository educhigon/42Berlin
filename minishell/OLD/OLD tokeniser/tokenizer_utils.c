/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:58:35 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/20 18:37:37 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

//should we add &
int	ismeta(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == ')' || c == '(')
		return (1);
	return (0);
}

void	skip_whitespace(char **s)
{
	while (**s && ft_isspace(**s))
		*s += 1;
}
