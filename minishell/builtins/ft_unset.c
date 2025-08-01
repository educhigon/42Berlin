/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:38:48 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:39:03 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	is_valid_varname(const char *name)
{
	int	i;

	if (!name || !name[0])
		return (0);
	if (!(ft_isalpha(name[0]) || name[0] == '_'))
		return (0);
	i = 1;
	while (name[i])
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static int	is_match(char *env_entry, char *key)
{
	size_t	key_len;
	int		prefix_matches;
	int		next_char_is_equal;

	key_len = ft_strlen(key);
	prefix_matches = (ft_strncmp(env_entry, key, key_len) == 0);
	next_char_is_equal = (env_entry[key_len] == '=');
	if (prefix_matches && next_char_is_equal)
		return (1);
	else
		return (0);
}

void	remove_env_var(char **envp, char *key)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		if (is_match(envp[i], key))
		{
			free(envp[i]);
			j = i;
			while (envp[j])
			{
				envp[j] = envp[j + 1];
				j++;
			}
		}
		else
			i++;
	}
}

int	ft_unset(t_shell *shell, char **args)
{
	char	**envp;
	int		i;

	envp = shell->envp;
	i = 1;
	while (args[i])
	{
		if (is_valid_varname(args[i]))
			remove_env_var(envp, args[i]);
		else
			perror("unset invalid identifier");
		i++;
	}
	return (0);
}
