/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:43:23 by joseph            #+#    #+#             */
/*   Updated: 2025/05/20 12:41:51 by edugonza         ###   ########.fr       */
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

	new_tree = create_redirect_node(tree, NULL, (*tok)->type - 2);
	*tok = next_tok(parser);
	// if ((*tok)->type == TOKEN_SPACE)
	// 	*tok = next_tok(parser);
	build_name(*tok, new_tree);
	// TODO: Check that the next token is a word, otherwise throw an error
	*tok = next_tok(parser);
	// if ((*tok)->type == TOKEN_SPACE)
	// 	*tok = next_tok(parser);
	if (new_tree->redirect.command == NULL)
	{
		printf("I have no command\n");
		new_tree->redirect.command = create_command_node();
		new_tree->redirect.command->parent = new_tree;
		new_tree->redirect.command = parse_command(parser, new_tree->redirect.command, tok);
	}
	else
		new_tree = parse_command(parser, new_tree, tok);
	return new_tree;
}

ASTNode *parse_pipeline(Parser *parser, ASTNode *tree, t_token **tok)
{
	ASTNode *new_tree;

	// if (tree->parent == NULL)
	// {
	if(tree)
	{
		ft_printf("Node of type: %d ", tree->type);
		if(tree->parent)
			ft_printf("with parent of type: %d\n", tree->parent->type);
		else
			ft_printf(" -- I don't have a parent\n");
	}
	new_tree = create_binary_node(AST_PIPELINE, tree, NULL);
	tree->parent = new_tree;
	*tok = next_tok(parser);
	// if ((*tok)->type == TOKEN_SPACE)
	// 	*tok = next_tok(parser);
	new_tree->binary.right = create_command_node();
	new_tree->binary.right->parent = new_tree;
	new_tree->binary.right = parse_command(parser, new_tree->binary.right, tok);
	if (!new_tree->binary.right)
		return NULL; // TODO: Maybe throw an error?
	// }
	// else
	// {
	// 	ft_printf("I HAVE a parent\n");
	// 	parse_pipeline(parser, tree->parent, tok);
	// }
	return new_tree;
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

ASTNode *parse_command(Parser *parser, ASTNode *tree, t_token **tok)
{
	sleep(2);
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
		tree = parse_command(parser, tree, tok);
		return (tree);
	}
	// else if ((*tok)->type == TOKEN_SPACE)
	// {
	// 	printf(C"## enter SPACE\n"RST);
	// 	if (tree != NULL)
	// 		build_word(*tok, tree);
	// 	*tok = next_tok(parser);
	// 	tree = parse_command(parser, tree, tok);
	// 	return (tree);
	// }
	else if ((*tok)->type == TOKEN_REDIRECT_IN ||
		(*tok)->type == TOKEN_REDIRECT_HEREDOC ||
		(*tok)->type == TOKEN_REDIRECT_OUT_APP ||
		(*tok)->type == TOKEN_REDIRECT_OUT_TRUNC)
	{
		printf(C"## enter REDIRECT\n"RST);
		tree = parse_redirect(parser, tree, tok);
		return (tree);
	}
	else if ((*tok)->type == TOKEN_PIPE)
	{
		printf(C"## enter PIPELINE\n"RST);
		while (tree->parent != NULL)
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
	return (NULL);
}
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
    print_ast_tree(root, "", 1);

    return 0;
}

 cat << EOF | grep e | wc -l > file2
 << EOF cat | grep e | wc -l > file2

*/
