/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:56:10 by edugonza          #+#    #+#             */
/*   Updated: 2025/05/20 19:37:29 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

ASTNode *create_command_node(void)
{
	ASTNode *node;

	node = malloc(sizeof(ASTNode));
	node->parent = NULL;
	node->type = AST_COMMAND;
	node->command.argv = NULL;
	return node;
}

ASTNode *create_binary_node(ASTNodeType type, ASTNode *left, ASTNode *right)
{
	ASTNode *node;

	node = malloc(sizeof(ASTNode));
	node->parent = NULL;
	node->type = type;
	node->binary.left = left;
	node->binary.right = right;
	return node;
}

ASTNode *create_redirect_node(ASTNode *command, char **filename, int redirect_type)
{
	ASTNode *node;
	node = malloc(sizeof(ASTNode));
	node->parent = NULL;
	node->type = AST_REDIRECT;
	node->redirect.command = command;
	node->redirect.filename = filename;
	node->redirect.redirect_type = redirect_type;
	return node;
}


ASTNode *parse_command(Parser *parser, ASTNode *tree, t_token **tok)
{
	// printf(C"## enter WORD\n"RST);
	if (tree == NULL)
	{
		// printf("!! null tree\n");
		tree = create_command_node();
	}
	build_word(*tok, tree);
	*tok = next_tok(parser);
	// printf(RED"## Finish WORD\n"RST);
	return (tree);
}
ASTNode *parse_redirect(Parser *parser, ASTNode *tree, t_token **tok)
{
	ASTNode *new_tree;
	// printf(C"## enter REDIRECT\n"RST);

	new_tree = create_redirect_node(tree, NULL, (*tok)->type - 2);
	*tok = next_tok(parser);
	if ((*tok)->type != TOKEN_WORD) {
		// ft_printf(RED"syntax error: expected filename\n"RST);
		// free_node(new_tree); TODO: free correctly
		return NULL;
	}
	build_name(*tok, new_tree);
	*tok = next_tok(parser);
	// TODO: Check that the redirect has a command, otherwise throw error
	if (new_tree->redirect.command == NULL)
	{
		// printf("I have no command\n");
		new_tree->redirect.command = create_command_node();
		new_tree->redirect.command->parent = new_tree;
	}
	while((*tok)->type == TOKEN_WORD)
	{
		new_tree->redirect.command = parse_command(parser, new_tree->redirect.command, tok);
	}
	// printf(RED"## Finish REDIRECT\n"RST);
	return new_tree;
}

ASTNode *parse_pipeline(Parser *parser, ASTNode *tree, t_token **tok)
{
	ASTNode *new_tree;
	// printf(C"## enter PIPELINE\n"RST);

	new_tree = create_binary_node(AST_PIPELINE, tree, NULL);
	if (tree) {
		tree->parent = new_tree;
		// Update child's parent pointers if necessary
		if (tree->type == AST_REDIRECT && tree->redirect.command)
			tree->redirect.command->parent = tree;
	}
	*tok = next_tok(parser);
	new_tree->binary.right = create_command_node();
	new_tree->binary.right->parent = new_tree;
	new_tree->binary.right = parse_line(parser, new_tree->binary.right, tok);
	if (!new_tree->binary.right) {
		// ft_printf(RED"syntax error: missing command after pipe\n"RST);
		// free_node(new_tree);  TODO: free correctly
		return NULL;
	}
	// printf(RED"## Finish PIPELINE\n"RST);
	return new_tree;

}


ASTNode *parse_line(Parser *parser, ASTNode *tree, t_token **tok)
{
	if (!*tok) {
		// ft_printf(RED"Cannot parse: NULL token\n"RST);
		return tree;
	}

	while((*tok)->type != TOKEN_EOF)
	{
		// ft_printf("tok type: %d\n", (*tok)->type);
		if ((*tok)->type == TOKEN_WORD)
			tree = parse_command(parser, tree, tok);
		else if ((*tok)->type == TOKEN_REDIRECT_IN ||
			(*tok)->type == TOKEN_REDIRECT_HEREDOC ||
			(*tok)->type == TOKEN_REDIRECT_OUT_APP ||
			(*tok)->type == TOKEN_REDIRECT_OUT_TRUNC)
				tree = parse_redirect(parser, tree, tok);
		else if ((*tok)->type == TOKEN_PIPE)
			tree = parse_pipeline(parser, tree, tok);
	}
	return (tree);
}
