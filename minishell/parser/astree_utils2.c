/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:52:40 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:52:44 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	free_tree(t_astnode *tree)
{
	if (tree->type == AST_REDIRECT)
	{
		ft_split_free(tree->s_redirect.filename);
		free_tree(tree->s_redirect.command);
		free(tree);
	}
	else if (tree->type == AST_PIPELINE)
	{
		free_tree(tree->s_binary.left);
		free_tree(tree->s_binary.right);
		free(tree);
	}
	else if (tree->type == AST_COMMAND)
	{
		ft_split_free(tree->s_command.argv);
		free(tree);
	}
	return ;
}

void	advance(t_parser *parser)
{
	if (parser->current)
		parser->current = parser->current->next;
}

t_token	*next_tok(t_parser *parser)
{
	advance(parser);
	return (parser->current);
}

int	ft_strlen_char_char(char **str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}
