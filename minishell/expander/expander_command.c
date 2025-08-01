/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:42:25 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/25 18:45:45 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	expand_command(t_astnode *node, t_shell *shell)
{
	char	**args;
	t_token	*expanded_args_ll;
	char	**old_argv;

	expanded_args_ll = NULL;
	args = node->s_command.argv;
	while (args && *args)
	{
		expand_argument(*args, &expanded_args_ll, shell);
		args++;
	}
	old_argv = node->s_command.argv;
	node->s_command.argv = convert_ll_to_array(expanded_args_ll);
	if (old_argv)
		ft_split_free(old_argv);
	ft_lstclear_token(&expanded_args_ll, free);
}
