/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:53:42 by edugonza          #+#    #+#             */
/*   Updated: 2025/05/20 19:37:57 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void advance(Parser *parser)
{
	if (parser->current)
		parser->current = parser->current->next;
}

t_token *next_tok(Parser *parser)
{
	// ft_printf("from tok: '%s'", parser->current->content);
	advance(parser);
	// ft_printf(" to '%s'\n", parser->current->content);
	return parser->current;
}

int ft_strlen_char_char(char **str)
{
	int i;

	i = 0;
	if (!*str)
		return (0);
	while(str[i] != 0)
	{
		// printf("str[i]: '%s'\n", str[i]);
		i++;
	}
	return (i);
}

void build_word(t_token *tok, ASTNode *tree)
{
	char **cmd;
	int len;
	int i;

	if (tree->command.argv == NULL)
		len = 0;
	else
		len = ft_strlen_char_char(tree->command.argv);
	len++;
	// printf("len: '%d'\n", len);

	cmd = malloc ((len + 1) * sizeof(char *));
	i = 0;
	while (i < len - 1)
	{
		cmd[i] = malloc ((ft_strlen(tree->command.argv[i]) + 1) * sizeof(char));;
		ft_memcpy(cmd[i], tree->command.argv[i], ft_strlen(tree->command.argv[i]) + 1);
		i++;
	}
	cmd[i] = malloc ((ft_strlen(tok->content) + 1) * sizeof(char));;
	ft_memcpy(cmd[i], tok->content, ft_strlen(tok->content) + 1);
	cmd[i+1] = 0;
	if (tree->command.argv != NULL)
		ft_split_free(tree->command.argv);
	tree->command.argv = cmd;
	cmd = NULL;
	return ;
}

void build_name(t_token *tok, ASTNode *tree)
{
	char **filename;
	int len;
	int i;

	if (tree->redirect.filename == NULL)
		len = 0;
	else
		len = ft_strlen_char_char(tree->redirect.filename);
	len++;
	filename = malloc ((len + 1) * sizeof(char *));
	i = 0;
	while (i < len - 1)
	{
		filename[i] = malloc ((ft_strlen(tree->redirect.filename[i]) + 1) * sizeof(char));;
		ft_memcpy(filename[i], tree->redirect.filename[i], ft_strlen(tree->redirect.filename[i]) + 1);
		i++;
	}
	filename[i] = malloc ((ft_strlen(tok->content) + 1) * sizeof(char));;
	ft_memcpy(filename[i], tok->content, ft_strlen(tok->content) + 1);
	filename[i+1] = 0;
	if (tree->redirect.filename != NULL)
		ft_split_free(tree->redirect.filename);
	tree->redirect.filename = filename;
	filename = NULL;
	return ;
}

void free_tree(ASTNode *tree)
{
	if (tree->type == AST_REDIRECT)
	{
		ft_split_free(tree->redirect.filename);
		free_tree(tree->redirect.command);
		free(tree);
	}
	else if (tree->type == AST_PIPELINE)
	{
		free_tree(tree->binary.left);
		free_tree(tree->binary.right);
		free(tree);
	}
	else if (tree->type == AST_COMMAND)
	{
		ft_split_free(tree->command.argv);
		free(tree);
	}
	return;
}
