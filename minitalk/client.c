/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 17:05:05 by edugonza          #+#    #+#             */
/*   Updated: 2025-02-26 17:05:05 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_list *list_c;

void	send_signal(char *str, int server_PID)
{
	unsigned long	i;

	i = 0;
	usleep(1000);
	while (i < ft_strlen(str))
	{
		usleep(1000);
		ft_printf("%c", str[i]);
		if (str[i] == '0')
			kill(server_PID, SIGUSR1);
		if (str[i] == '1')
			kill(server_PID, SIGUSR2);
		i++;
	}
	ft_printf("i: %d", i);

	ft_printf("\n");
	return ;
}


void ack_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Client got acknowledgment!\n");
	}
	
}

int	send_size(char *str, int server_PID)
{
	int size;
	char *size_binary;

	size = ft_strlen(str);
	size_binary = ft_putnbr_base(size);
	send_signal(size_binary, server_PID);
	return (size);
}


void	translate_to_signal(char *str, int size, int server_PID)
{
	char *char_binary;
	int i;

	i = 0;
	while (i < size)
	{
		char_binary = ft_putchar_base(str[i]);
		send_signal(char_binary, server_PID);
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	int i = 0;
	int size;
	char *str;
	int server_PID;
	server_PID = ft_atoi(av[1]);
	
	if (ac < 3) {
		ft_printf("Usage: ./client <server_pid>\n");
		return 1;
	}

	i = 3;
	str = av[2];
	while (i < ac)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, av[i]);
		i++;
	}
	ft_printf("str: %s\n", str);
	size = send_size(str, server_PID);
	ft_printf("size: %d\n", size);
	translate_to_signal(str, size, server_PID);


	signal(SIGUSR1, ack_handler);
	pause();
	return 0;
}


