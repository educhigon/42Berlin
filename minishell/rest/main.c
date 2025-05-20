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

#include "../main.h"

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
		{
			ft_split_free(all_paths);
			return(full_path);
		}
		free(full_path);
		j++;
	}

	ft_split_free(all_paths);
	ft_printf(RED"Can't find command"RST);
	return (NULL);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	Parser	parser;
	int status;
	char *line;
	char *xble;
	t_token	*token_ll;
	t_token	*token_ll_or;
	char *path_var;
	ASTNode *tree;


	path_var = find_path_var(env);
	print_header();

	while (1)
	{
		line = readline(PROMPT);
		if (*line == '\0')
			continue;

		// token_ll = NULL;
		if (line == NULL)
		{
			ft_printf(G"Exiting\n"RST);
			exit(EXIT_SUCCESS);
		}

		xble = find_path(line, path_var);
		printf("line\t->\t'%s'\n\n", xble);
		token_ll = tokenize(line);
		token_ll_or = token_ll;
		// print_tokens(token_ll);

		parser.current = token_ll; // Initialize parser with the token list
		// tree = parse_command(&parser, NULL, &token_ll); // Parse the tokens into an AST
		tree = parse_line(&parser, NULL, &token_ll); // Parse the tokens into an AST

		printf("###########################################################################\n");
		printf("\t\t\t\t  PRINTING TREE\n");
		printf("###########################################################################\n\n\n");
		print_ast_tree(tree, "", 1);
		printf("\n\n###########################################################################\n\n\n");

		ft_printf("line: %s \n", xble);
		if (fork() == 0)
		{
			ft_printf("executing...\n");
			// execve(line, NULL, env);
		}
		wait(&status);

		free(line);
		free(xble);
		ft_lstclear_token(&token_ll_or, del_content_token);
		free_tree(tree);
		line = NULL;
	}

	// ft_lstclear_token(&token_ll_or, del_content_token);
	// free(token_ll);
	// free(xble);
	// free(line);
	if (tree)
	{
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);

}
