/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:34:24 by edugonza          #+#    #+#             */
/*   Updated: 2025/07/23 11:36:36 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

// Helper: check if a string is a valid -n option
int	is_n_flag(const char *s)
{
	int	i;

	if (s[0] != '-' || s[1] == '\0')
		return (0);
	i = 1;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(char **argv)
{
	int		newline;
	char	**args;

	newline = 1;
	args = argv + 1;
	while (*args && is_n_flag(*args))
	{
		newline = 0;
		args++;
	}
	while (*args)
	{
		ft_printf("%s", *args);
		if (*(args + 1))
			ft_printf(" ");
		args++;
	}
	if (newline)
		ft_printf("\n");
	return (0);
}
