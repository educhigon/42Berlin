/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:52:51 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:52:55 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_astnode	*create_command_node(void)
{
	t_astnode	*node;

	node = malloc(sizeof(t_astnode));
	node->parent = NULL;
	node->type = AST_COMMAND;
	node->s_command.argv = NULL;
	return (node);
}

t_astnode	*create_binary_node(t_astnode_type type, t_astnode *left,
	t_astnode *right)
{
	t_astnode	*node;

	node = malloc(sizeof(t_astnode));
	node->parent = NULL;
	node->type = type;
	node->s_binary.left = left;
	node->s_binary.right = right;
	return (node);
}

t_astnode	*create_redirect_node(t_astnode *command, char **filename,
	int redirect_type)
{
	t_astnode	*node;

	node = malloc(sizeof(t_astnode));
	node->parent = NULL;
	node->type = AST_REDIRECT;
	node->s_redirect.command = command;
	node->s_redirect.filename = filename;
	node->s_redirect.redirect_type = redirect_type;
	return (node);
}
