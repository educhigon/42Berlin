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
	usleep(5000);
	while (i < ft_strlen(str))
	{
		usleep(5000);
		// ft_printf("%c", str[i]);
		if (str[i] == '0')
			kill(server_PID, SIGUSR1);
		if (str[i] == '1')
			kill(server_PID, SIGUSR2);
		i++;
	}
	// ft_printf("i: %d", i);

	// ft_printf("\n");
	return ;
}


void ack_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Client got acknowledgment!\n");
	}
	
}

char *fill_with_zeros(char *str)
{
	int s;
	char *new_str1;
	char *new_str2;

	new_str1 = str;
	s = ft_strlen(str);
	while(s < 32)
	{
		new_str2 = ft_strjoin("0", new_str1);
		free(new_str1);
		new_str1 = new_str2;
		s++;
	}
	return (new_str1);
}

int	send_size(char *str, int server_PID)
{
	int size;
	char *string_size;
	char *size_binary;

	size = ft_strlen(str);
	string_size = ft_itoa(size);
	size_binary = fill_with_zeros(ft_convert_base(string_size, "0123456789", "01"));
	send_signal(size_binary, server_PID);
	free(size_binary);
	free(string_size);
	return (size);
}


void	translate_to_signal(char *str, int size, int server_PID)
{
	char *char_binary;
	char *string_char;
	int i;

	i = 0;
	while (i < size)
	{
		string_char = ft_itoa(str[i]);
		char_binary = fill_with_zeros(ft_convert_base(string_char, "0123456789", "01"));
		send_signal(char_binary, server_PID);
		free(string_char);
		free(char_binary);
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	int size;
	int server_PID;
	server_PID = ft_atoi(av[1]);
	
	if (ac < 3) {
		ft_printf("Usage: ./client <server_pid>\n");
		return 1;
	}

	// ft_printf("str: %s\n", av[2]);
	size = send_size(av[2], server_PID);
	// ft_printf("size: %d\n", size);
	translate_to_signal(av[2], size, server_PID);
	signal(SIGUSR1, ack_handler);
	pause();
	return 0;
}


