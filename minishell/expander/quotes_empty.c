/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:44:50 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:48:12 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	handle_space(t_expander *expander)
{
	char	*dup_str;
	t_token	*new_node;

	if (expander->buf_i > 0)
	{
		expander->buf[expander->buf_i] = '\0';
		dup_str = ft_strdup(expander->buf);
		if (!dup_str)
		{
			perror("malloc");
			cleanup_expander(expander);
			return (-1);
		}
		new_node = ft_lstnew_token(dup_str);
		if (!new_node)
		{
			free(dup_str);
			perror("malloc");
			cleanup_expander(expander);
			return (-1);
		}
		ft_lstadd_back_token(expander->expanded_args_ll, new_node);
		expander->buf_i = 0;
	}
	return (1);
}

static int	handle_escape(t_expander *expander, char *arg)
{
	if (*(arg + 1) != '\0')
	{
		arg++;
		expander->buf[expander->buf_i++] = *arg;
		return (2);
	}
	else
	{
		expander->buf[expander->buf_i++] = *arg;
		return (1);
	}
}

static int	handle_dollar(t_expander *expander, char *arg, t_shell *shell)
{
	if (*(arg + 1) == '\0' || *(arg + 1) == ' '
		|| *(arg + 1) == '\"' || *(arg + 1) == '\'')
	{
		expander->buf[expander->buf_i++] = *arg;
		return (1);
	}
	else
		return (expand_variable(expander, arg, shell));
}

int	no_quote_state(t_expander *expander, char *arg, t_shell *shell)
{
	int	expanded_variable_len;

	expanded_variable_len = 1;
	if (*arg == '~')
		expanded_variable_len = expand_tilde(expander, arg, shell);
	else if (*arg == '$')
		expanded_variable_len = handle_dollar(expander, arg, shell);
	else if (*arg == ' ')
		expanded_variable_len = handle_space(expander);
	else if (*arg == '\"')
		expander->quote_type = DOUBLE_QUOTE;
	else if (*arg == '\'')
		expander->quote_type = SINGLE_QUOTE;
	else if (*arg == '\\')
		expanded_variable_len = handle_escape(expander, arg);
	else
		expander->buf[expander->buf_i++] = *arg;
	return (expanded_variable_len);
}
