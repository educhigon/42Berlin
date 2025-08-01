/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 16:52:35 by edugonza          #+#    #+#             */
/*   Updated: 2025-05-06 16:52:35 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	initialize_shell(t_shell **evment, char **env)
{
	*evment = malloc(sizeof(t_shell));
	if (!(*evment))
		exit(EXIT_FAILURE);
	(*evment)->envp = copy_env(env);
	(*evment)->current_cmd.status = 0;
}

static void	handle_eof(t_shell *evment)
{
	ft_split_free(evment->envp);
	free(evment);
	ft_printf(G"exit\n"RST);
	exit(EXIT_SUCCESS);
}

static char	*read_command_line(t_shell *evment)
{
	char	*line;

	line = readline(PROMPT);
	if (line == NULL)
		handle_eof(evment);
	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(int ac, char **av, char **env)
{
	t_shell		*evment;
	char		*line;
	int			exec_ans;

	(void)ac;
	(void)av;
	setup_signals();
	initialize_shell(&evment, env);
	while (1)
	{
		line = read_command_line(evment);
		if (!line)
			continue ;
		exec_ans = process_command(evment, line);
		free(line);
		if (exec_ans == -1)
			ft_printf(RED"ERROR\n"RST);
	}
	ft_split_free(evment->envp);
	free(evment);
	return (EXIT_SUCCESS);
}
