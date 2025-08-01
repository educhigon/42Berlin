/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:41:43 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:41:48 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	process_argument(t_expander *expander, char *arg, t_shell *shell)
{
	int	skip;

	while (*arg)
	{
		if (expander->quote_type == NO_QUOTE)
			skip = no_quote_state(expander, arg, shell);
		else if (expander->quote_type == SINGLE_QUOTE)
			skip = single_quote_state(expander, arg, shell);
		else if (expander->quote_type == DOUBLE_QUOTE)
			skip = double_quote_state(expander, arg, shell);
		if (*arg)
			arg += skip;
	}
}

static void	check_quotes_closed(t_expander *expander)
{
	if (expander->quote_type != NO_QUOTE)
	{
		printf("quote is really not closed\n");
		cleanup_expander(expander);
		exit(1);
	}
}

static char	*duplicate_buffer(t_expander *expander)
{
	char	*dup_str;

	expander->buf[expander->buf_i] = '\0';
	dup_str = ft_strdup(expander->buf);
	if (!dup_str)
	{
		perror("malloc");
		cleanup_expander(expander);
		exit(EXIT_FAILURE);
	}
	return (dup_str);
}

static t_token	*create_token(char *str, t_expander *expander)
{
	t_token	*new_node;

	if (!ft_strlen(str))
	{
		free(str);
		return (NULL);
	}
	new_node = ft_lstnew_token(str);
	if (!new_node)
	{
		free(str);
		perror("malloc");
		cleanup_expander(expander);
		exit(EXIT_FAILURE);
	}
	return (new_node);
}

void	expand_argument(char *arg, t_token **expanded_args_ll, t_shell *shell)
{
	t_expander	expander;
	t_token		*new_node;
	char		*dup_str;

	init_expander(&expander, arg, expanded_args_ll);
	process_argument(&expander, arg, shell);
	check_quotes_closed(&expander);
	dup_str = duplicate_buffer(&expander);
	new_node = create_token(dup_str, &expander);
	if (new_node)
		ft_lstadd_back_token(expanded_args_ll, new_node);
	cleanup_expander(&expander);
}
