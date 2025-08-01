/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:45:27 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:45:34 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_astnode	*expand_tree(t_astnode *node, t_shell *shell)
{
	if (!node)
		return (NULL);
	if (node->type == AST_PIPELINE || node->type == AST_SEQUENCE)
	{
		node->s_binary.left = expand_tree(node->s_binary.left, shell);
		node->s_binary.right = expand_tree(node->s_binary.right, shell);
	}
	else if (node->type == AST_REDIRECT)
	{
		expand_redirect(node, shell);
		if (node->s_redirect.command)
			node->s_redirect.command
				= expand_tree(node->s_redirect.command, shell);
	}
	else if (node->type == AST_COMMAND)
		expand_command(node, shell);
	return (node);
}
