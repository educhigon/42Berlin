/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sorted_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:39:13 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:39:32 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static char	**copy_env_array(char **env, int count)
{
	char	**env_copy;
	int		i;

	env_copy = malloc(sizeof(char *) * (count + 1));
	if (!env_copy)
		return (NULL);
	i = 0;
	while (i < count)
	{
		env_copy[i] = ft_strdup(env[i]);
		i++;
	}
	env_copy[count] = NULL;
	return (env_copy);
}

static void	sort_env_array(char **env_copy, int count)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strcmp(env_copy[j], env_copy[j + 1]) > 0)
			{
				temp = env_copy[j];
				env_copy[j] = env_copy[j + 1];
				env_copy[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	print_and_free_env(char **env_copy, int count)
{
	int		i;
	char	*eq;

	i = 0;
	while (i < count)
	{
		eq = ft_strchr(env_copy[i], '=');
		if (eq)
		{
			*eq = '\0';
			printf("declare -x %s=\"%s\"\n", env_copy[i], eq + 1);
			*eq = '=';
		}
		else
			printf("declare -x %s\n", env_copy[i]);
		free(env_copy[i]);
		i++;
	}
	free(env_copy);
}

void	print_sorted_env(char **env)
{
	int		count;
	char	**env_copy;

	count = 0;
	while (env && env[count])
		count++;
	env_copy = copy_env_array(env, count);
	if (!env_copy)
		return ;
	sort_env_array(env_copy, count);
	print_and_free_env(env_copy, count);
}
