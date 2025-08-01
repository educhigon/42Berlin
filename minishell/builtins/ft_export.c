/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:35:34 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:37:18 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	is_valid_varname(const char *name)
{
	int	i;

	if (!name || !name[0])
		return (0);
	if (!(ft_isalpha(name[0]) || name[0] == '_'))
		return (0);
	i = 1;
	while (name[i])
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_' || name[i] != '-'))
			return (0);
		i++;
	}
	return (1);
}

static int	handle_var_without_value(t_shell *shell, char *varname)
{
	char	*new_var;
	int		result;
	int		idx;

	result = 0;
	if (!is_valid_varname(varname))
		return (print_errors(shell, "export", "not a valid identifier", 1));
	idx = find_env_var(shell->envp, varname);
	if (idx == -1)
	{
		new_var = ft_strjoin(varname, "=");
		if (!new_var)
			return (-1);
		result = add_env_entry(shell, new_var);
		free(new_var);
	}
	return (result);
}

static int	handle_var_with_value(t_shell *shell, char *arg)
{
	char	*key;
	int		idx;
	int		result;

	result = 0;
	key = parse_var_key(arg);
	if (!key || !is_valid_varname(key))
	{
		free(key);
		return (print_errors(shell, "export", "not a valid identifier", 1));
	}
	idx = find_env_index(shell->envp, key);
	if (idx != -1)
		replace_env_entry(shell->envp, idx, arg);
	else if (add_env_entry(shell, arg) != 0)
	{
		ft_putstr_fd("export: failed to add variable\n", 2);
		result = -1;
	}
	free(key);
	return (result);
}

int	process_export_arg(t_shell *shell, char *arg)
{
	char	*eq;

	eq = ft_strchr(arg, '=');
	if (!eq)
		return (handle_var_without_value(shell, arg));
	else
		return (handle_var_with_value(shell, arg));
}

int	ft_export(t_shell *shell, char **args)
{
	int	i;
	int	status;

	status = 0;
	i = 1;
	if (!args[i])
		print_sorted_env(shell->envp);
	while (args[i])
	{
		if (process_export_arg(shell, args[i]) != 0)
			status = 1;
		i++;
	}
	return (status);
}
