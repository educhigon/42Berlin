/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:40:37 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/25 15:39:12 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	handle_builtin_commands(t_astnode *tree, t_shell *shell)
{
	if (!shell->current_cmd.status)
	{
		shell->current_cmd.status = choose_builtin(shell, tree);
		return (shell->current_cmd.status);
	}
	else
		return (print_errors(shell, tree->s_command.argv[0],
				strerror(errno), 1));
}

static void	setup_redirections(t_shell *shell)
{
	if (shell->current_cmd.input_type)
	{
		if (dup2(shell->current_cmd.input_fd, STDIN_FILENO) == -1)
			exit(print_errors(shell, "IN dup2: ", strerror(errno), errno));
		close(shell->current_cmd.input_fd);
	}
	if (shell->current_cmd.output_type)
	{
		if (dup2(shell->current_cmd.output_fd, STDOUT_FILENO) == -1)
			exit(print_errors(shell, "OUT dup2: ", strerror(errno), errno));
		close(shell->current_cmd.output_fd);
	}
}

static void	execute_child_process(t_astnode *tree, t_shell *shell)
{
	char	*xble;
	int		status;

	setup_redirections(shell);
	if (is_builtin(tree))
	{
		if (!shell->current_cmd.status)
		{
			shell->current_cmd.status = choose_builtin(shell, tree);
			exit(WEXITSTATUS(shell->current_cmd.status));
		}
		else
			exit(print_errors(shell, tree->s_command.argv[0],
					strerror(errno), 1));
	}
	xble = build_xble(tree, shell);
	status = execve(xble, tree->s_command.argv, shell->envp);
	exit(print_errors(shell, tree->s_command.argv[0],
			strerror(errno), WEXITSTATUS(status)));
}

static void	parent_process(t_shell *shell, pid_t pid)
{
	int	status;

	if (shell->current_cmd.input_type)
		close(shell->current_cmd.input_fd);
	if (shell->current_cmd.output_type)
		close(shell->current_cmd.output_fd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->current_cmd.status = WEXITSTATUS(status);
}

int	exec_command(t_astnode *tree, t_shell *shell)
{
	pid_t	pid;

	if (!tree->s_command.argv[0])
		return (1);
	if (shell->current_cmd.status)
	{
		print_error_redir(shell);
		shell->current_cmd.status = 1;
		return (1);
	}
	if (is_builtin_state(tree))
		return (handle_builtin_commands(tree, shell));
	pid = fork();
	if (pid == -1)
		return (print_errors(shell, "fork", strerror(errno), errno));
	if (pid == 0)
		execute_child_process(tree, shell);
	else
		parent_process(shell, pid);
	return (0);
}
