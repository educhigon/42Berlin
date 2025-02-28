/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:16:03 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/20 19:41:39 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		number_finder(char *to_find, char *pathname);
void	split_block_in_num(char *nbr, char *pathname);

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

char	*fill_blocks_with_zeros(int block)
{
	char	*order_of_magnitude;
	int		i;

	order_of_magnitude = malloc((block * 3 + 2) * sizeof (char));
	if (!order_of_magnitude)
		return (NULL);
	order_of_magnitude[0] = '1';
	i = 1;
	while (i <= block * 3)
	{
		order_of_magnitude[i] = '0';
		i++;
	}
	order_of_magnitude[i] = '\0';
	return (order_of_magnitude);
}

int	process_num(char *num, char *pathname)
{
	int		digits;
	int		blocks;
	int		i;
	char	num_temp[4];
	int		leading_num;

	digits = ft_strlen(num);
	if (digits < 3)
	{
		split_block_in_num(num, pathname);
		return (0);
	}
	blocks = digits / 3;
	leading_num = digits % 3; 
	if (leading_num == 2)
	{
		num_temp[0] = '0';
		num_temp[1] = num[0];
		num_temp[2] = num[1];
	}
	if (leading_num == 1)
	{
		num_temp[0] = '0';
		num_temp[1] = '0';
		num_temp[2] = num[0];
	}
	num_temp[3] = '\0';
	if (!(leading_num == 0))
	{
		split_block_in_num(num_temp, pathname);
		number_finder(fill_blocks_with_zeros(blocks), pathname);
	}
	i = 0;
	while (i < blocks)
	{
		num_temp[0] = num[i * 3 + leading_num];
		num_temp[1] = num[i * 3 + leading_num + 1];
		num_temp[2] = num[i * 3 + leading_num + 2];
		num_temp[3] = '\0';
		if (!(num_temp[0] == '0' && num_temp[1] == '0' && num_temp[2] == '0'))
		{
			split_block_in_num(num_temp, pathname);
			if (!(i + 1 == blocks))
				number_finder(fill_blocks_with_zeros(blocks - i - 1), pathname);
		}
		i++;
	}
	return (0);
}
