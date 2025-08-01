/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:41:19 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/24 11:14:59 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	handle_pipe_error(t_shell *shell)
{
	ft_putstr_fd("bash: pipe: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	shell->current_cmd.status = errno;
	exit(1);
}

static void	read_heredoc_input(int *pipefd, char *delimiter)
{
	char	*line;

	while (1)
	{
		line = readline("DOC_here> ");
		if (!line || !ft_strcmp(line, delimiter))
		{
			free(line);
			break ;
		}
		write(pipefd[1], line, ft_strlen(line));
		write(pipefd[1], "\n", 1);
		free(line);
	}
}

void	get_heredoc(t_astnode *tree, t_shell *shell)
{
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		handle_pipe_error(shell);
	else
	{
		read_heredoc_input(pipefd, tree->s_redirect.filename[0]);
		if (shell->current_cmd.input_type
			&& shell->current_cmd.input_type != 3)
		{
			close(pipefd[1]);
			close(pipefd[0]);
			return ;
		}
		else
		{
			close(pipefd[1]);
			shell->current_cmd.input_fd = pipefd[0];
			shell->current_cmd.input_type = 2;
		}
	}
	return ;
}
