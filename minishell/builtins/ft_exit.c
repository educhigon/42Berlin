/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:34:35 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/24 12:13:45 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_exit(t_shell *shell, t_astnode *node)
{
	unsigned char	errornum;
	int				strstrlen;

	strstrlen = ft_strlen_st_st((const char **)node->s_command.argv);
	if (strstrlen > 2)
	{
		print_errors(shell, "", "too many arguments", 1);
		shell->current_cmd.status = 1;
		return (1);
	}
	if (strstrlen == 2)
		errornum = ft_atoi(node->s_command.argv[1]);
	else
		errornum = 0;
	shell->current_cmd.status = errornum;
	if (!errornum && strstrlen == 2 && ft_str_is_alpha(node->s_command.argv[1]))
	{
		print_errors(shell, "", "numeric argument required", 2);
		errornum = 2;
	}
	ft_split_free(shell->envp);
	free_tree(node);
	ft_lstclear_token(&shell->token_ll_or, del_content_token);
	free(shell);
	exit(errornum);
}
