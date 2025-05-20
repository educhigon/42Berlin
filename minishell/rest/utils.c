/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 18:19:58 by edugonza          #+#    #+#             */
/*   Updated: 2025-05-06 18:19:58 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	print_header(void)
{
	ft_printf(G
"		  ██████  █    ██  ██▓███  ▓█████  ██▀███    "
"   ██████  ██░ ██ ▓█████  ██▓     ██▓    \n"
"		▒██    ▒  ██  ▓██▒▓██░  ██▒▓█   ▀ ▓██ ▒ ██▒  "
" ▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    \n"
"		░ ▓██▄   ▓██  ▒██░▓██░ ██▓▒▒███   ▓██ ░▄█ ▒  "
" ░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░    \n"
"		  ▒   ██▒▓▓█  ░██░▒██▄█▓▒ ▒▒▓█  ▄ ▒██▀▀█▄    "
"   ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    \n"
"		▒██████▒▒▒▒█████▓ ▒██▒ ░  ░░▒████▒░██▓ ▒██▒  "
" ▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒\n"
"		▒ ▒▓▒ ▒ ░░▒▓▒ ▒ ▒ ▒▓▒░ ░  ░░░ ▒░ ░░ ▒▓ ░▒▓░  "
" ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░\n"
"		░ ░▒  ░ ░░░▒░ ░ ░ ░▒ ░      ░ ░  ░  ░▒ ░ ▒░  "
" ░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░\n"
"		░  ░  ░   ░░░ ░ ░ ░░          ░     ░░   ░   "
" ░  ░  ░   ░  ░░ ░   ░     ░ ░     ░ ░   \n"
"		      ░     ░                 ░  ░   ░       "
"       ░   ░  ░  ░   ░  ░    ░  ░    ░  ░\n"
"		                                             "
"                                         \n\n"RST);
// https://patorjk.com/software/taag/#p=display&v=0&f=Bloody&t=Super%20Shell
}

void	print_tokens(t_token *token)
{
	printf("	(0) TOKEN_WORD \n	(1) TOKEN_SPACE \n	(2) TOKEN_REDIRECT_IN \n	(3) TOKEN_REDIRECT_HEREDOC \n	(4) TOKEN_REDIRECT_OUT_APP \n	(5) TOKEN_REDIRECT_OUT_TRUNC \n	(6) TOKEN_PIPE \n	(7) TOKEN_D_QUOTE \n	(8) TOKEN_S_QUOTE \n	(9) TOKEN_SEQUENCE \n	(10) TOKEN_EOF\n\n");
	//int	i;

	//i = 0;
	if (token == NULL)
		printf("There are no tokens\n");
	else
	{
		while (token)
		{
			printf("token->content:\t'%s'\n", token->content);
			printf("token->type:\t%d\n", (t_token_type)token->type);
			printf("token->len:\t%zu\n", token->len);
			printf("token->fully_quoted:\t%d\n", token->fully_quoted);
			printf("token->next:\t[%p]\n", token->next);
			putchar('\n');
			token = token->next;
		}
	}
	return ;
}

// Helper function to print arguments of a command
static void print_command_args(char **argv) {
	if (argv) {
		for (char **arg = argv; *arg; ++arg) {
			printf(" %s", *arg);
		}
	}
	printf("\n");
}

// Recursive AST printer with tree-like ASCII formatting
void print_ast_tree(ASTNode *node, const char *prefix, int is_last)
{
	if (!node)
		return;
	sleep(2);

	// └── or ├── based on whether it's the last child
	printf("%s%s", prefix, is_last ? "└── " : "├── ");

	// Print node info
	switch (node->type) {
		case AST_COMMAND:
			printf("COMMAND:");
			print_command_args(node->command.argv);
			break;
		case AST_PIPELINE:
			printf("PIPELINE\n");
			break;
		case AST_SEQUENCE:
			printf("SEQUENCE\n");
			break;
		case AST_REDIRECT:
			printf("REDIRECT (%s): ", node->redirect.redirect_type == 0 ? "input" : "output");
			print_command_args(node->redirect.filename);
			break;
		default:
			printf("UNKNOWN NODE\n");
			return;
	}

	// Prepare new prefix for child nodes
	char new_prefix[256];
	snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_last ? "    " : "│   ");

	// Recurse into children
	switch (node->type) {
		case AST_PIPELINE:
		case AST_SEQUENCE:
			print_ast_tree(node->binary.left, new_prefix, 0);  // not last
			print_ast_tree(node->binary.right, new_prefix, 1); // last
			break;
		case AST_REDIRECT:
			print_ast_tree(node->redirect.command, new_prefix, 1); // only child
			break;
		default:
			break; // COMMAND has no children
	}
}
