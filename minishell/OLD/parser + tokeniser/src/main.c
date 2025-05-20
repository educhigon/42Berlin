/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:23:10 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/12 14:00:54 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
TO DO'S
	- get token could return NULL; in that case the token_ll should be freed and
		an error message should be printed
*/

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_token	*token_ll;
	Parser	parser; //new

	(void) argc;
	(void) argv;
	(void) envp;
	line = NULL;
	while (1)
	{
		line = readline(PROMPT);
		if (line == NULL)
			exit(EXIT_SUCCESS);
		//printf("line\t->\t'%s'\n", line);
		token_ll = tokenize(line);

		parser.current = token_ll; // Initialize parser with the token list
		ASTNode *tree = parse(&parser); // Parse the tokens into an AST
		print_ast_tree(tree, "", 1); // Print the AST
		// free_ast_tree(tree); //TODO Free the AST 
		// add_history(line);

		free(line);
		line = NULL;
		//print_tokens(token_ll);
		ft_lstclear(&token_ll, del_content);
	}
	return (EXIT_SUCCESS);
}
