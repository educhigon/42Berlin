/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_chooser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:34:02 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/24 13:13:37 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	choose_builtin(t_shell *shell, t_astnode *node)
{
	int	status;

	if (ft_strcmp(node->s_command.argv[0], "cd") == 0)
		status = ft_cd(shell, node->s_command.argv);
	else if (ft_strcmp(node->s_command.argv[0], "env") == 0)
		status = ft_env(shell);
	else if (ft_strcmp(node->s_command.argv[0], "exit") == 0)
		status = ft_exit(shell, node);
	else if (ft_strcmp(node->s_command.argv[0], "export") == 0)
		status = ft_export(shell, node->s_command.argv);
	else if (ft_strcmp(node->s_command.argv[0], "unset") == 0)
		status = ft_unset(shell, node->s_command.argv);
	else if (ft_strcmp(node->s_command.argv[0], "pwd") == 0)
		status = ft_pwd();
	else if (ft_strcmp(node->s_command.argv[0], "echo") == 0)
		status = ft_echo(node->s_command.argv);
	else
		return (1);
	return (status);
}

int	is_builtin(t_astnode *node)
{
	if (ft_strcmp(node->s_command.argv[0], "cd") == 0
		|| ft_strcmp(node->s_command.argv[0], "env") == 0
		|| ft_strcmp(node->s_command.argv[0], "exit") == 0
		|| ft_strcmp(node->s_command.argv[0], "export") == 0
		|| ft_strcmp(node->s_command.argv[0], "unset") == 0
		|| ft_strcmp(node->s_command.argv[0], "pwd") == 0
		|| ft_strcmp(node->s_command.argv[0], "echo") == 0)
		return (1);
	else
		return (0);
}

int	is_builtin_state(t_astnode *node)
{
	if (ft_strcmp(node->s_command.argv[0], "cd") == 0
		|| ft_strcmp(node->s_command.argv[0], "exit") == 0
		|| ft_strcmp(node->s_command.argv[0], "export") == 0
		|| ft_strcmp(node->s_command.argv[0], "unset") == 0)
		return (1);
	else
		return (0);
}
