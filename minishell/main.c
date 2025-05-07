/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 16:52:35 by edugonza          #+#    #+#             */
/*   Updated: 2025-05-06 16:52:35 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char *find_path(char *line, char **path)
{
	int	i;
	int	j;
	char **all_paths;
	char *full_path;
	i = 0;
	while (path[i] != 0)
	{
		// ft_printf(Y"path[%d]: %s\n", i, path[i]);
		if (!ft_strncmp(path[i], "PATH", 4))
		{
			path[i] = path[i] + 5;
			ft_printf(C"---> found the PATH: %s\n", path[i]);
			all_paths = ft_split(path[i], ':');
			j = 0;
			while (all_paths[j] != NULL)
			{
				full_path = malloc ((ft_strlen(all_paths[j]) + 2 + ft_strlen(line)) * sizeof(char));
				ft_strlcpy(full_path, all_paths[j], ft_strlen(all_paths[j])+1);
				full_path[ft_strlen(all_paths[j])] = '/';
				ft_strlcpy(full_path + (ft_strlen(all_paths[j]) + 1), line, ft_strlen(line)+1);
				ft_printf("full_path: %s \n", full_path);
				if(!access(full_path, X_OK))
					return(full_path);
				j++;
			}

		}
		
	// 	if (!access(path[i], line))
	// 	{
	// 		comm = malloc((ft_strlen(path[i]) + ft_strlen(line) + 1) * sizeof(char));
	// 		ft_memcpy(comm, path[i], ft_strlen(path[i]));
	// 		ft_memcpy(comm + ft_strlen(path[i]), line, ft_strlen(line));
	// 		comm + 1 = 0;
	// 		return comm;
	// 	}
		i++;
	}
	ft_printf(RED"Can't find command"RST);
	return (NULL);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	int status;
	char *line;
	char *xble;

	while (1)
	{
		line = readline("?> ");
		if (line == NULL)
		{	
			ft_printf(G"Exiting"RST);
			exit(EXIT_SUCCESS);
		}
		printf("line\t->\t'%s'\n", line);
		// tokenize
		xble = find_path(line, env);

		ft_printf("line: %s \n", xble);
		if (fork() == 0)
		{
			ft_printf("executing...\n");
			execve(line, NULL, env);
		}
		wait(&status);
		free(line);
		line = NULL;
	}
	

	free(line);
	return (EXIT_SUCCESS);
}