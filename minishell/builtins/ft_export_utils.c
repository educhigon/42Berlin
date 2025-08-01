/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:34:42 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:37:36 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	find_env_var(char **env, char *name)
{
	int		i;
	size_t	name_len;

	i = 0;
	name_len = ft_strlen(name);
	if (!env)
		return (-1);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, name_len) == 0
			&& (env[i][name_len] == '=' || env[i][name_len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

int	find_env_index(char **env, char *key)
{
	int		i;
	char	*env_key;
	int		result;

	i = 0;
	if (!env)
		return (-1);
	while (env[i])
	{
		env_key = parse_var_key(env[i]);
		if (env_key)
		{
			result = ft_strcmp(env_key, key);
			free(env_key);
			if (result == 0)
				return (i);
		}
		i++;
	}
	return (-1);
}

char	*parse_var_key(char *arg)
{
	char	*eq;
	size_t	len;
	char	*key;

	eq = ft_strchr(arg, '=');
	if (!eq)
		return (NULL);
	len = ft_strlen(arg) - ft_strlen(eq);
	key = malloc(len + 1);
	if (!key)
		return (NULL);
	ft_strlcpy(key, arg, len + 1);
	key[len] = '\0';
	return (key);
}

void	replace_env_entry(char **env, int index, const char *arg)
{
	char	*new_entry;

	new_entry = ft_strdup(arg);
	if (!new_entry)
		return ;
	free(env[index]);
	env[index] = new_entry;
}

int	add_env_entry(t_shell *shell, const char *arg)
{
	char	**env;
	int		size;
	char	**new_env;
	int		i;

	env = shell->envp;
	size = 0;
	while (env && env[size])
		size++;
	new_env = (char **)malloc((size + 2) * sizeof(char *));
	if (!new_env)
		return (-1);
	i = -1;
	while (++i < size)
		new_env[i] = env[i];
	new_env[size] = ft_strdup(arg);
	if (!new_env[size])
	{
		free(new_env);
		return (-1);
	}
	new_env[size + 1] = NULL;
	free(env);
	shell->envp = new_env;
	return (0);
}
