/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:44:01 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/07 13:50:43 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <unistd.h>
#include <stdio.h>
int main()
{
	int count;
	char str[] = {'H','e','l','l','o'};
	
	count = ft_strlen(str);
	printf("COUNT = %d", count);
}	
*/
