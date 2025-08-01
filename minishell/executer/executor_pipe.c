/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:40:54 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:40:57 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	handle_left_process(int *pipefd, t_astnode *tree, t_shell *shell)
{
	shell->current_cmd.output_fd = pipefd[1];
	shell->current_cmd.output_type = 3;
	close(pipefd[0]);
	execute_tree(tree->s_binary.left, shell);
	exit(shell->current_cmd.status);
}

static void	handle_right_process(int *pipefd, t_astnode *tree, t_shell *shell)
{
	shell->current_cmd.input_fd = pipefd[0];
	shell->current_cmd.input_type = 3;
	close(pipefd[1]);
	execute_tree(tree->s_binary.right, shell);
	exit(shell->current_cmd.status);
}

int	exec_pipe(t_astnode *tree, t_shell *shell)
{
	int		pipefd[2];
	pid_t	pid_left;
	pid_t	pid_right;
	int		status_l;
	int		status_r;

	if (pipe(pipefd) == -1)
		exit(print_errors(shell, "pipe: ", strerror(errno), errno));
	pid_left = fork();
	if (pid_left == -1)
		exit(print_errors(shell, "fork: ", strerror(errno), errno));
	if (pid_left == 0)
		handle_left_process(pipefd, tree, shell);
	pid_right = fork();
	if (pid_right == -1)
		exit(print_errors(shell, "fork: ", strerror(errno), errno));
	if (pid_right == 0)
		handle_right_process(pipefd, tree, shell);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid_left, &status_l, 0);
	waitpid(pid_right, &status_r, 0);
	if (WIFEXITED(status_r))
		shell->current_cmd.status = WEXITSTATUS(status_r);
	return (0);
}
