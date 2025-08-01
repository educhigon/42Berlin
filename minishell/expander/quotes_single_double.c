/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_single_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:45:14 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:45:19 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	single_quote_state(t_expander *expander, char *str, t_shell *shell)
{
	(void) shell;
	if (*str == '\'')
		expander->quote_type = NO_QUOTE;
	else
		expander->buf[expander->buf_i++] = *str;
	return (1);
}

int	double_quote_state(t_expander *expander, char *str, t_shell *shell)
{
	int	expanded_variable_len;

	expanded_variable_len = 1;
	if (*str == '$')
	{
		if (*(str + 1) == '\0' || *(str + 1) == ' ' || *(str + 1) == '\"')
			expander->buf[expander->buf_i++] = *str;
		else
			expanded_variable_len = expand_variable(expander, str, shell);
	}
	else if (*str == '\"')
		expander->quote_type = NO_QUOTE;
	else if (*str == '\\' && (*(str + 1) == '\"' || *(str + 1) == '\\'))
	{
		str++;
		expander->buf[expander->buf_i++] = *str;
		expanded_variable_len = 2;
	}
	else
		expander->buf[expander->buf_i++] = *str;
	return (expanded_variable_len);
}
