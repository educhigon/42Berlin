/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_numbers_in_block.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:19:07 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/20 19:39:17 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	nullify_num(char *num);
void	reduce_number(char *nbr);
int		number_finder(char *to_find, char *pathname);

void	print_units(char *c, char *pathname)
{
	number_finder(c, pathname);
}

void	print_decimals(char *nbr, char *pathname)
{
	char	num_name[4];

	nullify_num(num_name);
	if (nbr[0] == '1')
		number_finder(nbr, pathname);
	else if (nbr[0] == '0')
	{
		if (nbr[1] != '0')
		{
			num_name[0] = nbr[1];
			number_finder(num_name, pathname);
		}
	}
	else
	{
		num_name[0] = nbr[0];
		num_name[1] = '0';
		number_finder(num_name, pathname);
		if (nbr[1] != '0')
		{
			nullify_num(num_name);
			num_name[0] = nbr[1];
			print_units(num_name, pathname);
		}
	}
}

void	print_hundreds(char *nbr, char *pathname)
{
	char	num_name[4];

	nullify_num(num_name);
	num_name[0] = nbr[0];
	number_finder(num_name, pathname);
	num_name[0] = '1';
	num_name[1] = '0';
	num_name[2] = '0';
	number_finder(num_name, pathname);
	nullify_num(num_name);
	num_name[0] = nbr[1];
	num_name[1] = nbr[2];
	print_decimals(num_name, pathname);
}

void	split_block_in_num(char *nbr, char *pathname)
{
	char	num_name[4];
	int		size;

	nullify_num(num_name);
	if (nbr[0] == '0' && nbr[1] == '\0')
	{
		print_units(nbr, pathname);
		return ;
	}
	reduce_number(nbr);
	size = 0;
	while (nbr[size] != '\0')
		size++;
	if (size == 1)
		print_units(nbr, pathname);
	else if (size == 2)
		print_decimals(nbr, pathname);
	else
		print_hundreds(nbr, pathname);
}
