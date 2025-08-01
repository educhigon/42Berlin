/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:42:39 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:46:40 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	is_valid_redirect_for_expansion(t_astnode *node)
{
	if (!node || !node->s_redirect.filename || !node->s_redirect.filename[0])
	{
		perror("expand_redirect: null filename array/filename\n");
		return (0);
	}
	if (node->s_redirect.redirect_type == 1)
		return (0);
	return (1);
}

static int	validate_expanded_filename(t_token *expanded_filenames_ll)
{
	if (ft_lstsize_token(expanded_filenames_ll) != 1
		|| ft_strlen(expanded_filenames_ll->content) == 0)
	{
		perror("expand_redirect: invalid redirect");
		return (0);
	}
	return (1);
}

static int	replace_filename_in_redirect(t_astnode *node,
		t_token *expanded_filenames_ll)
{
	char	*expanded_filename;
	char	*old_filename;

	expanded_filename = ft_strdup(expanded_filenames_ll->content);
	if (!expanded_filename)
	{
		perror("expand_redirect: memory allocation failed");
		return (0);
	}
	old_filename = node->s_redirect.filename[0];
	node->s_redirect.filename[0] = expanded_filename;
	if (old_filename)
		free(old_filename);
	return (1);
}

void	expand_redirect(t_astnode *node, t_shell *shell)
{
	char	*unexpanded_filename;
	t_token	*expanded_filenames_ll;

	expanded_filenames_ll = NULL;
	if (!is_valid_redirect_for_expansion(node))
		return ;
	unexpanded_filename = node->s_redirect.filename[0];
	expand_argument(unexpanded_filename, &expanded_filenames_ll, shell);
	if (!validate_expanded_filename(expanded_filenames_ll))
	{
		ft_lstclear_token(&expanded_filenames_ll, free);
		return ;
	}
	if (!replace_filename_in_redirect(node, expanded_filenames_ll))
	{
		ft_lstclear_token(&expanded_filenames_ll, free);
		return ;
	}
	ft_lstclear_token(&expanded_filenames_ll, free);
}
