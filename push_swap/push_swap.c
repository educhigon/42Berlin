/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:09:59 by edugonza          #+#    #+#             */
/*   Updated: 2025/02/05 17:27:51 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	int	j;

	j = 0;
	while (j < ft_strlen(str))
	{
		if (str[0] == '-')
			j++;
		if (str[j] <= '0' || str[j] >= '9')
			return (0);
		j++;
	}
	return (1);
}
int	check_big_int(char *str)
{
	if (ft_atoi_here(str) > 2147483647 || ft_atoi_here(str) < -2147483648)
		return (0);
	return (1);
}
int	check_duplicates(char *str)
{
	int	i;
	int	j;

	i = 0;
	while(i < ft_strlen(str))
	{
		j = i + 1;
		while(j < ft_strlen(str))
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checker(char *num)
{

	if (!check_duplicates(num))
		return(0);
	return(1);
}

int fail()
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	if (ac < 2)
		return (fail());
	while (av[i] != NULL)
	{
		write(1,"Testing INT\n",12);
		if (!check_int(av[i]))
			return (fail());
		write(1,"Testing BIG INT\n",16);
		if (!check_big_int(av[i]))
			return (fail());
		j = i + 1;
		while(av[j] != NULL)
		{
			printf("av[i=%d]: %s & av[j=%d]: %s\n",i, av[i], j, av[j]);
			if (ft_atoi_here(av[j]) == ft_atoi_here(av[i]))
				return (fail());
			j++;
		}
		i++;
	}
}
// int	push_swap(const char *str, ...)
// {
// 	va_list	args;
// 	int		str_len;
// 	int		i;
// 	int		char_count;

// 	char_count = 0;
// 	str_len = ft_strlen(str);
// 	va_start(args, str);
// 	i = 0;
// 	while (i < str_len)
// 	{
// 		if (str[i] == '%')
// 			char_count += find_special_print(str[++i], args);
// 		else
// 		{
// 			write(1, &str[i], 1);
// 			char_count++;
// 		}
// 		i++;
// 	}
// 	return (char_count);
// }