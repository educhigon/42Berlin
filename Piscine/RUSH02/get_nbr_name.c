/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:42:37 by jkolosow          #+#    #+#             */
/*   Updated: 2024/10/20 17:05:40 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(int c);

int	ft_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

char	*get_nbr_name(char *str)
{
	if (str)
	{
		while (*str != '\0' && *str != ':')
			str++;
		if (*str != ':')
			return (NULL);
		str++;
		while (*str != '\0' && ft_isspace(*str))
			str++;
		if (!ft_is_printable(*str))
			return (NULL);
		return (str);
	}
	else
		return (NULL);
}

// #############################################################################
/*
#include <stdio.h>

void test1(void)
{
	char str[] = "0: zero";
	printf("'%s' -> '%s'\n", str, get_nbr_name(str));
	return ;
}

void test38(void)
{
	char str[] = "1000000000000000000000000000: 	 octillion";
	printf("'%s' -> '%s'\n", str, get_nbr_name(str));
	return ;
}

int	main(void)
{
	test1();
	test38();
	return (0);
}
*/