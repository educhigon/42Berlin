/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:56:10 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/25 16:07:47 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static t_astnode	*setup_empty_command(t_astnode *redirect_node)
{
	redirect_node->s_redirect.command = create_command_node();
	redirect_node->s_redirect.command->parent = redirect_node;
	redirect_node->s_redirect.command->s_command.argv
		= malloc(2 * sizeof(char *));
	redirect_node->s_redirect.command->s_command.argv[0]
		= malloc(1 * sizeof(char));
	redirect_node->s_redirect.command->s_command.argv[0][0] = '\0';
	redirect_node->s_redirect.command->s_command.argv[1] = NULL;
	return (redirect_node);
}

static t_astnode	*find_deepest_command(t_astnode *tree)
{
	while (tree->s_redirect.command
		&& tree->s_redirect.command->type == AST_REDIRECT)
		tree = tree->s_redirect.command;
	return (tree);
}

t_astnode	*parse_redirect(t_parser *parser, t_astnode *tree, t_token **tok)
{
	t_astnode	*new_tree;
	t_astnode	*temp_tree;

	new_tree = create_redirect_node(tree, NULL, (*tok)->type);
	*tok = next_tok(parser);
	if ((*tok)->type != TOKEN_WORD)
		return (NULL);
	build_name(*tok, new_tree);
	*tok = next_tok(parser);
	if (new_tree->s_redirect.command == NULL)
	{
		if ((*tok)->type == TOKEN_EOF)
			return (setup_empty_command(new_tree));
		new_tree->s_redirect.command = create_command_node();
		new_tree->s_redirect.command->parent = new_tree;
	}
	while ((*tok)->type == TOKEN_WORD)
	{
		temp_tree = find_deepest_command(new_tree);
		temp_tree->s_redirect.command = parse_command(parser,
				temp_tree->s_redirect.command, tok);
	}
	return (new_tree);
}
