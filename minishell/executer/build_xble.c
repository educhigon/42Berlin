/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_xble.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:40:25 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:40:33 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	check_executable_status(char *cmd, t_shell *shell, t_astnode *tree)
{
	struct stat	st;

	if (stat(cmd, &st) != 0)
		exit(print_errors(shell, tree->s_command.argv[0],
				"No such file or directory", 127));
	if (S_ISDIR(st.st_mode))
		exit(print_errors(shell, tree->s_command.argv[0],
				"Is a directory", 126));
	if (access(cmd, X_OK) != 0)
		exit(print_errors(shell, tree->s_command.argv[0],
				"Permission denied", 126));
	return (0);
}

static int	is_path_format(char *cmd)
{
	return (cmd[0] == '/' || ft_strncmp(cmd, "./", 2) == 0
		|| ft_strncmp(cmd, "../", 3) == 0);
}

char	*build_xble(t_astnode *tree, t_shell *shell)
{
	char	*cmd;
	char	*xble;

	cmd = tree->s_command.argv[0];
	if (is_path_format(cmd))
	{
		check_executable_status(cmd, shell, tree);
		return (ft_strdup(cmd));
	}
	xble = find_path(cmd, shell);
	if (!xble)
		exit(print_errors(shell, cmd, "command not found", 127));
	return (xble);
}
