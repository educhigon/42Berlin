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

t_list *list_s;

void	printf_nodes(t_list *list, int size, int start, int end)
{
    t_list *current = list;
    int i = 0;
    while (i < size && current)
    {
		if (i >= start && i < end)
			ft_printf("%c", *(char *)current->content);
        current = current->next;
        i++;
    }
    ft_printf("\n");
}

void del_content(void *content)
{
    (void)content; // Do nothing—content is static
}

void	send_0_1(int signum)
{
	static char zero = '0';
	static char one = '1';
	
	if (signum == SIGUSR1)
		add_signal(&list_s, &zero);
	else if (signum == SIGUSR2)
		add_signal(&list_s, &one);
	return ;
}

void combine_message(int signum, siginfo_t *info, void *context)
{
	static int		num_signals;
	static int		i;
	char *str;

	(void)context;
	if (ft_lstsize(list_s) == 16)
	{
		str = get_binary_num_from_signals(list_s, 0, 16);
		num_signals = convert_binary_str_to_int(str) * 16 + 16;
		free(str);
		i = 16;
	}
	else if (ft_lstsize(list_s) < 16)
		num_signals = 0;
	if (num_signals == 0)
	{
		send_0_1(signum);
	}	
	else
	{
		send_0_1(signum);
		i++;
		if (i % 16 == 0 && i != 16)
			translate_char(list_s, i - 16, i);
		if (info && i == num_signals)
		{
			kill(info->si_pid, SIGUSR1);
			ft_lstclear(&list_s, del_content);
			return ;
		}
	}
	return ;
}

int main()
{
	struct sigaction act;
	
	ft_printf("Server PID: %d\n", getpid());
	
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
