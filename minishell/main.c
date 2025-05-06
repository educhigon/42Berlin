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
	// char *comm;
	(void)line;

	while (path[i] != 0)
	{
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
	printf(RED"Can't find command"RST);
	return (NULL);
}

int	main(int ac, char **av, char **path)
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
			printf(RED"[EOF]"RST);
			break;
		}
		xble = find_path(line, path);

		printf("line: %s \n", xble);
		if (fork() == 0)
		{
			printf("executing...\n");
			// execvp(line, line);
		}
	}
	

	wait(&status);
	free(line);
	return (EXIT_SUCCESS);
}