/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:28:47 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/14 14:26:00 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	get_text_from_file(t_astnode *tree, t_shell *shell)
{
	int	fd;

	fd = open(tree->s_redirect.filename[0], O_RDONLY);
	if (fd == -1)
	{
		shell->current_cmd.err_text = tree->s_redirect.filename[0];
		shell->current_cmd.status = errno;
	}
	else
	{
		if (shell->current_cmd.input_type
			&& shell->current_cmd.input_type != 3)
		{
			close(fd);
			return ;
		}
		else
		{
			shell->current_cmd.input_fd = fd;
			shell->current_cmd.input_type = 1;
		}
	}
	return ;
}

static int	open_output_file(t_astnode *tree)
{
	int	fd;

	if (tree->s_redirect.redirect_type == 4)
		fd = open(tree->s_redirect.filename[0],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (tree->s_redirect.redirect_type == 5)
		fd = open(tree->s_redirect.filename[0],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = -1;
	return (fd);
}

static void	handle_output_error(t_shell *shell, char *filename)
{
	shell->current_cmd.err_text = filename;
	shell->current_cmd.status = errno;
}

void	get_output_redirection(t_astnode *tree, t_shell *shell)
{
	int	fd;

	fd = open_output_file(tree);
	if (fd == -1)
		handle_output_error(shell, tree->s_redirect.filename[0]);
	else if (shell->current_cmd.output_type
		&& shell->current_cmd.output_type != 3)
		close(fd);
	else
	{
		shell->current_cmd.output_fd = fd;
		shell->current_cmd.output_type = tree->s_redirect.redirect_type - 3;
	}
}
