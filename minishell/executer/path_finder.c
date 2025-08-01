/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:43:39 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/14 14:27:15 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	*find_var(char **env, char *var_name)
{
	int	i;

	i = 0;
	while (env[i] != 0)
	{
		if (!ft_strncmp(env[i], var_name, ft_strlen(var_name)))
			return (env[i] + ft_strlen(var_name) + 1);
		i++;
	}
	return (NULL);
}

static char	*create_full_path(char *path_dir, char *command)
{
	char	*full_path;
	size_t	dir_len;
	size_t	cmd_len;

	dir_len = ft_strlen(path_dir);
	cmd_len = ft_strlen(command);
	full_path = malloc((dir_len + cmd_len + 2) * sizeof(char));
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, path_dir, dir_len + 1);
	full_path[dir_len] = '/';
	ft_strlcpy(full_path + (dir_len + 1), command, cmd_len + 1);
	return (full_path);
}

char	*find_path(char *line, t_shell *shell)
{
	int		j;
	char	**all_paths;
	char	*full_path;
	char	*path;

	path = find_var(shell->envp, "PATH");
	if (path == NULL)
		return (NULL);
	all_paths = ft_split(path, ':');
	if (!all_paths)
		return (NULL);
	j = 0;
	while (all_paths[j] != NULL)
	{
		full_path = create_full_path(all_paths[j], line);
		if (full_path && !access(full_path, X_OK))
		{
			ft_split_free(all_paths);
			return (full_path);
		}
		free(full_path);
		j++;
	}
	ft_split_free(all_paths);
	return (NULL);
}
