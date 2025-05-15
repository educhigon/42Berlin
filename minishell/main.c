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

char *find_path_var(char **env)
{
	int i = 0;

	while (env[i] != 0)
	{
		if (!ft_strncmp(env[i], "PATH", 4))
			return (env[i]+5);
		i++;
	}
	return (0);
}

char *find_path(char *line, char *path)
{
	int	j;
	char **all_paths;
	char *full_path;

	all_paths = ft_split(path, ':');
	j = 0;
	while (all_paths[j] != NULL)
	{
		full_path = malloc ((ft_strlen(all_paths[j]) + 2 + ft_strlen(line)) * sizeof(char));
		ft_strlcpy(full_path, all_paths[j], ft_strlen(all_paths[j])+1);
		full_path[ft_strlen(all_paths[j])] = '/';
		ft_strlcpy(full_path + (ft_strlen(all_paths[j]) + 1), line, ft_strlen(line)+1);
		// ft_printf(C"full_path: %s \n"RST, full_path);
		// FREE MEM
		if(!access(full_path, X_OK))
			return(full_path);
		j++;
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
	t_token	*token_ll;
	char *path_var;

	path_var = find_path_var(env);

	while (1)
	{
		line = readline(PROMPT);
		// token_ll = NULL;
		if (line == NULL)
		{
			ft_printf(G"Exiting\n"RST);
			exit(EXIT_SUCCESS);
		}
		xble = find_path(line, path_var);
		printf("line\t->\t'%s'\n\n", xble);
		token_ll = tokenize(line);
		print_tokens(token_ll);


		// parser.current = token_ll; // Initialize parser with the token list
		// ASTNode *tree = parse(&parser); // Parse the tokens into an AST
		// print_ast_tree(tree, "", 1); // Print the AST

		// tokenize

		ft_printf("line: %s \n", xble);
		if (fork() == 0)
		{
			ft_printf("executing...\n");
			// execve(line, NULL, env);
		}
		wait(&status);
		free(line);
		line = NULL;
	}


	free(line);
	return (EXIT_SUCCESS);
}
