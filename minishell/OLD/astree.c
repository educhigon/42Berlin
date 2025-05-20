/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:43:23 by joseph            #+#    #+#             */
/*   Updated: 2025/05/20 16:53:32 by edugonza         ###   ########.fr       */
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

ASTNode *parse_redirect(Parser *parser, ASTNode *tree, t_token **tok)
{
	ASTNode *new_tree;
	printf(C"## enter REDIRECT\n"RST);


	new_tree = create_redirect_node(tree, NULL, (*tok)->type - 2);
	*tok = next_tok(parser);
	if ((*tok)->type != TOKEN_WORD) {
		ft_printf(RED"syntax error: expected filename\n"RST);
		// free_node(new_tree); TODO: free correctly
		return NULL;
	}
	build_name(*tok, new_tree);
	*tok = next_tok(parser);
	// TODO: Check that the redirect has a command, otherwise throw error
	if (new_tree->redirect.command == NULL)
	{
		printf("I have no command\n");
		new_tree->redirect.command = create_command_node();
		new_tree->redirect.command->parent = new_tree;
	}

	if ((*tok)->type == TOKEN_PIPE)
		new_tree = parse_command(parser, new_tree, tok);
	else if ((*tok)->type == TOKEN_REDIRECT_IN ||
	(*tok)->type == TOKEN_REDIRECT_HEREDOC ||
	(*tok)->type == TOKEN_REDIRECT_OUT_APP ||
	(*tok)->type == TOKEN_REDIRECT_OUT_TRUNC)
		new_tree = parse_command(parser, new_tree, tok);
	else
		new_tree->redirect.command = parse_command(parser, new_tree->redirect.command, tok);

	// print_ast_tree(new_tree, "", 1);
	printf(RED"## Finish REDIRECT\n"RST);

	return new_tree;
}

ASTNode *parse_pipeline(Parser *parser, ASTNode *tree, t_token **tok)
{
	ASTNode *new_tree;
	printf(C"## enter PIPELINE\n"RST);

	if(tree)
	{
		ft_printf("Node of type: %d ", tree->type);
		if(tree->parent)
			ft_printf("with parent of type: %d\n", tree->parent->type);
		else
			ft_printf(" -- I don't have a parent\n");
	}
	new_tree = create_binary_node(AST_PIPELINE, tree, NULL);
	if (tree) {
		tree->parent = new_tree;
		// Update child's parent pointers if necessary
		if (tree->type == AST_REDIRECT && tree->redirect.command)
			tree->redirect.command->parent = tree;
	}

	if(tree)
	{
		ft_printf("Node of type: %d ", tree->type);
		if(tree->parent)
			ft_printf("with parent of type: %d\n", tree->parent->type);
		else
			ft_printf(" -- I don't have a parent\n");
	}

	*tok = next_tok(parser);
	new_tree->binary.right = create_command_node();
	new_tree->binary.right->parent = new_tree;
	new_tree->binary.right = parse_command(parser, new_tree->binary.right, tok);
	if (!new_tree->binary.right) {
		ft_printf(RED"syntax error: missing command after pipe\n"RST);
		// free_node(new_tree);  TODO: free correctly
		return NULL;
	}
	// new_tree->parent = NULL;
	// print_ast_tree(new_tree, "", 1);
	printf(RED"## Finish PIPELINE\n"RST);
	return new_tree;
}

ASTNode *parse_command(Parser *parser, ASTNode *tree, t_token **tok)
{
	if (!*tok) {
		ft_printf(RED"Cannot parse: NULL token\n"RST);
		return tree;
	}
	if(tree)
	{
		ft_printf("Node of type: %d ", tree->type);
		if(tree->parent)
			ft_printf("with parent of type: %d\n", tree->parent->type);
	}
	if ((*tok)->type == TOKEN_WORD || (*tok)->type == TOKEN_D_QUOTE || (*tok)->type == TOKEN_S_QUOTE)
	{
		printf(C"## enter WORD\n"RST);
		if (tree == NULL)
		{
			printf("!! null tree\n");
			tree = create_command_node();
		}
		build_word(*tok, tree);
		*tok = next_tok(parser);
		// tree = parse_command(parser, tree, tok);
		tree = parse_command(parser, tree, tok);
		// print_ast_tree(tree, "", 1);
		printf(RED"## Finish WORD\n"RST);
		return (tree);
	}
	else if ((*tok)->type == TOKEN_REDIRECT_IN ||
		(*tok)->type == TOKEN_REDIRECT_HEREDOC ||
		(*tok)->type == TOKEN_REDIRECT_OUT_APP ||
		(*tok)->type == TOKEN_REDIRECT_OUT_TRUNC)
	{
		tree = parse_redirect(parser, tree, tok);
		return (tree);
	}
	else if ((*tok)->type == TOKEN_PIPE)
	{
		while (tree && tree->parent != NULL)
			tree = tree->parent;
		tree = parse_pipeline(parser, tree, tok);
		return (tree);
	}
	else if ((*tok)->type == TOKEN_EOF)
	{
		printf(C"## EOF\n"RST);
		return (tree);
	}
	ft_printf(RED"Cannot parse\n"RST);
	return (tree);
}


// ASTNode *parse_sequence(Parser *parser)
// {
// 	ASTNode *left = parse_pipeline(parser);
// 	while (match(parser, TOKEN_SEQUENCE))
// 	{
// 		ASTNode *right = parse_pipeline(parser);
// 		if (!right) return NULL;
// 		left = create_binary_node(AST_SEQUENCE, left, right);
// 	}
// 	return left;
// }

/*
int main() {
    // Simulate: ls -l ; grep foo | sort > out.txt

    // COMMAND: ls -l
    char *ls_argv[] = {"ls", "-l", NULL};
    ASTNode *ls_node = create_command_node(ls_argv);

    // COMMAND: grep foo
    char *grep_argv[] = {"grep", "foo", NULL};
    ASTNode *grep_node = create_command_node(grep_argv);

    // COMMAND: sort
    char *sort_argv[] = {"sort", NULL};
    ASTNode *sort_node = create_command_node(sort_argv);

    // REDIRECT: sort > out.txt
    ASTNode *redirect_node = create_redirect_node(sort_node, "out.txt", 1);

    // PIPELINE: grep foo | sort > out.txt
    ASTNode *pipeline_node = create_binary_node(AST_PIPELINE, grep_node, redirect_node);

    // SEQUENCE: ls -l ; (grep foo | sort > out.txt)
    ASTNode *root = create_binary_node(AST_SEQUENCE, ls_node, pipeline_node);

    // Print the AST
    // print_ast_tree(root, "", 1);

    return 0;
}

 cat << EOF | grep e | wc -l > file2
 << EOF cat | grep e | wc -l > file2

*/
