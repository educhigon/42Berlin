/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:56:10 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/25 16:07:14 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_astnode	*parse_command(t_parser *parser, t_astnode *tree, t_token **tok)
{
	if (tree == NULL)
		tree = create_command_node();
	build_word(*tok, tree);
	*tok = next_tok(parser);
	return (tree);
}

t_astnode	*parse_pipeline(t_parser *parser, t_astnode *tree, t_token **tok)
{
	t_astnode	*new_tree;

	new_tree = create_binary_node(AST_PIPELINE, tree, NULL);
	if (tree)
	{
		tree->parent = new_tree;
		if (tree->type == AST_REDIRECT && tree->s_redirect.command)
			tree->s_redirect.command->parent = tree;
	}
	*tok = next_tok(parser);
	new_tree->s_binary.right = create_command_node();
	new_tree->s_binary.right->parent = new_tree;
	new_tree->s_binary.right = parse_line(parser, new_tree->s_binary.right,
			tok);
	if (!new_tree->s_binary.right)
		return (NULL);
	return (new_tree);
}

t_astnode	*parse_line(t_parser *parser, t_astnode *tree, t_token **tok)
{
	if (!*tok)
		return (tree);
	while ((*tok)->type != TOKEN_EOF)
	{
		if ((*tok)->type == TOKEN_WORD)
			tree = parse_command(parser, tree, tok);
		else if ((*tok)->type == TOKEN_REDIRECT_IN
			|| (*tok)->type == TOKEN_REDIRECT_HEREDOC
			|| (*tok)->type == TOKEN_REDIRECT_OUT_APP
			|| (*tok)->type == TOKEN_REDIRECT_OUT_TRUNC)
			tree = parse_redirect(parser, tree, tok);
		else if ((*tok)->type == TOKEN_PIPE)
			tree = parse_pipeline(parser, tree, tok);
	}
	return (tree);
}
