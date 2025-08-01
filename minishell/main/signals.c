/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:34:26 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/25 18:03:21 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	handle_sigquit(int sig)
{
	char	*line_buffer;

	(void)sig;
	line_buffer = rl_line_buffer;
	if (line_buffer && *line_buffer != '\0')
	{
		write(1, "\nexit\n", 6);
		exit(EXIT_SUCCESS);
	}
	write(1, "\r", 1);
	write(1, "\033[K", 3);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	setup_signals(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	sa_int.sa_handler = handle_sigint;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sigaction(SIGINT, &sa_int, NULL);
	sa_quit.sa_handler = handle_sigquit;
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_flags = 0;
	sigaction(SIGQUIT, &sa_quit, NULL);
}
/*
int	main(int ac, char **av, char **env)
{
	t_parser	parser;
	t_shell		*evment;
	char		*line;
	t_token		*token_ll;
	t_token		*token_ll_or;
	t_astnode	*tree;
	int	exec_ans;

	(void)ac;
	(void)av;
	setup_signals();
	evment = malloc(sizeof(t_shell));
	if(!evment)
		return 0;
	evment->envp = copy_env(env);
	evment->current_cmd.status = 0;
	while (1)
	{
		line = readline(PROMPT);
		if (line == NULL)
		{
			ft_split_free(evment->envp);
			free(line);
			ft_printf(G"exit\n"RST);
			exit(EXIT_SUCCESS);
		}
		if (*line == '\0')
			continue ;
		token_ll = tokenize(line, evment);
		if (!token_ll)
			continue;
		token_ll_or = token_ll;
		if(invalid_token(token_ll, evment))
		{
			ft_lstclear_token(&token_ll_or, del_content_token);
			continue;
		}
		else
		{
			add_history(ft_strjoin_st_st(convert_ll_to_array(token_ll_or)));
			parser.current = token_ll;
			tree = parse_line(&parser, NULL, &token_ll);
			tree = expand_tree(tree, evment);
			exec_ans = 0;
			evment->current_cmd.status = 0;
			exec_ans = execute(tree, evment);
			free(line);
			free_tree(tree);
			ft_lstclear_token(&token_ll_or, del_content_token);
			line = NULL;
			if (exec_ans == -1)
			{
				ft_printf(RED"ERROR\n"RST);
				continue;
			}

		}
	}
	ft_split_free(evment->envp);
	if (tree)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}	*/
