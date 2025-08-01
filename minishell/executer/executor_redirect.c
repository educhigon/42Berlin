/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:41:01 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:41:07 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	exec_redirect(t_astnode *tree, t_shell *shell)
{
	if (tree->s_redirect.redirect_type == 2)
		get_text_from_file(tree, shell);
	else if (tree->s_redirect.redirect_type == 3)
		get_heredoc(tree, shell);
	else if (tree->s_redirect.redirect_type == 4
		|| tree->s_redirect.redirect_type == 5)
		get_output_redirection(tree, shell);
	else
		ft_printf(RED"Error in redirection"RST);
	execute_tree(tree->s_redirect.command, shell);
	return (0);
}
