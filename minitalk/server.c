/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 17:04:56 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-26 17:04:56 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_list	*g_list_s;

static void	del_content(void *content)
{
	(void)content;
}

static void	save_0_1(int signum)
{
	static char	zero;
	static char	one;

	zero = '0';
	one = '1';
	if (signum == SIGUSR1)
		add_signal(&g_list_s, &zero);
	else if (signum == SIGUSR2)
		add_signal(&g_list_s, &one);
	return ;
}

static void	build_message(int i, siginfo_t *info, long num_signals)
{
	if (i % 8 == 0 && i != 8)
		translate_char(g_list_s, i - 8, i);
	if (info && i == num_signals)
	{
		kill(info->si_pid, SIGUSR1);
		ft_lstclear(&g_list_s, del_content);
		i = 0;
		num_signals = 0;
		return ;
	}
}

static void	combine_message(int signum, siginfo_t *info, void *context)
{
	static long		num_signals;
	static long		i;
	char			*str;

	(void)context;
	if (ft_lstsize(g_list_s) == 32)
	{
		str = get_binary_num_from_signals(g_list_s, 0, 32);
		num_signals = convert_binary_str_to_int(str) * 8 + 32;
		free(str);
		i = 32;
	}
	else if (ft_lstsize(g_list_s) < 32)
		num_signals = 0;
	if (num_signals == 0)
		save_0_1(signum);
	else
	{
		i++;
		save_0_1(signum);
		build_message(i, info, num_signals);
	}
	return ;
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("%d\n", getpid());
	act.sa_sigaction = combine_message;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, NULL);
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
