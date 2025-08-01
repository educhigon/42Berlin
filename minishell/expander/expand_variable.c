/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:42:01 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/25 15:33:21 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../main.h"

char	*get_valid_var_name(char *arg, t_expander *expander);

static int	copy_expanded_value(t_expander *expander, char *expanded_variable)
{
	int	expanded_variable_len;

	expanded_variable_len = ft_strlen(expanded_variable);
	expand_buffer_by(expander, expanded_variable_len);
	while (*expanded_variable)
	{
		expander->buf[expander->buf_i] = *expanded_variable;
		expander->buf_i++;
		expanded_variable++;
	}
	return (expanded_variable_len);
}

static int	expand_regular_variable(t_expander *expander,
	char *arg, t_shell *shell)
{
	char	*var_name;
	char	*expanded_variable;
	int		expanded_variable_len;
	int		var_name_len;

	var_name = get_valid_var_name(arg, expander);
	if (!var_name)
		return (-1);
	var_name_len = ft_strlen(var_name);
	expanded_variable = ft_getenv(shell->envp, var_name);
	if (!expanded_variable)
	{
		free(var_name);
		return (var_name_len + 1);
	}
	expanded_variable_len = copy_expanded_value(expander, expanded_variable);
	free(var_name);
	if (expanded_variable_len < 0)
	{
		perror("malloc");
		return (-1);
	}
	return (var_name_len + 1);
}

int	expand_last_status(t_expander *expander, char *str, t_shell *shell)
{
	char	*last_status;
	int		last_status_len;
	int		i;

	i = 0;
	(void) str;
	last_status = ft_itoa(shell->current_cmd.status);
	if (!last_status)
	{
		perror("malloc");
		return (-1);
	}
	last_status_len = ft_strlen(last_status);
	expand_buffer_by(expander, last_status_len);
	while (last_status[i])
		expander->buf[expander->buf_i++] = last_status[i++];
	free(last_status);
	return (2);
}

char	*get_valid_var_name(char *arg, t_expander *expander)
{
	char	*var_name;
	int		var_len;

	(void) expander;
	var_len = 0;
	arg++;
	if (!ft_isalpha(*arg) && *arg != '_')
		return (NULL);
	while (ft_isalnum(*arg) || *arg == '_')
	{
		arg++;
		var_len++;
	}
	arg = arg - var_len;
	var_name = malloc(sizeof(char) * (var_len + 1));
	if (!var_name)
		return (NULL);
	ft_memcpy(var_name, arg, var_len);
	var_name[var_len] = '\0';
	return (var_name);
}

int	expand_variable(t_expander *expander, char *arg, t_shell *shell)
{
	if (*(arg + 1) == '?')
		return (expand_last_status(expander, arg, shell));
	else if (expander->quote_type == NO_QUOTE
		&& (*(arg + 1) == '\"' || *(arg + 1) == '\''))
		return (1);
	else
		return (expand_regular_variable(expander, arg, shell));
}
