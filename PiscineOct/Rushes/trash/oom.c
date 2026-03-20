/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oom.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:40:30 by ehussein          #+#    #+#             */
/*   Updated: 2024/10/20 16:39:59 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int	count_blocks(char	*str)
{
	if ((ft_strlen(str) % 3) == 0)
	{
		printf("length of input nbr: %d \n", ft_strlen(str));
		printf("number of blocks in nbr: %d \n", (ft_strlen(str) / 3));
		return ((ft_strlen(str) / 3));
	}
	else
	{
		printf("length of input nbr: %d \n", ft_strlen(str));
		printf("number of blocks in nbr: %d \n", ((ft_strlen(str) / 3 + 1)));
		return (((ft_strlen(str) / 3) + 1));
	}
}

char	*fill_blocks_with_zeros(char	*str)
{
	int		non_leading_block_count;
	int		zero_count;
	char	*order_of_magnitude;
	int		i;

	non_leading_block_count = count_blocks(str) - 1;
	zero_count = non_leading_block_count * 3;
	order_of_magnitude = malloc(zero_count * sizeof (char));
	order_of_magnitude[0] = '1';
	printf("number of zeros to add: %d \n", zero_count);
	i = 1;
	while (i <= zero_count)
	{
		order_of_magnitude[i] = '0';
		i++;
	}
	return (order_of_magnitude);
}

// int	main(void)
// {
// 	// int count = count_blocks("1234567890");
// 	//printf("block count in main: %d \n", count);
// 	char	*test_zeros = fill_blocks_with_zeros("1234567890123456");
// 	printf("resulting oom: %s \n", test_zeros);
// 	return (0);
// }

