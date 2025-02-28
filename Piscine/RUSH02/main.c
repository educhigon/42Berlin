/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:11:51 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/20 19:52:20 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	find_number(int *file_control, char *to_find, char *filepath);
int		*build_file_control(int nbr_lines, char *filepath);
void	*split_block_in_num(char *nbr, char *pathname);
char	*sanitize_number(char *str);
int		process_num(char *num, char *pathname);

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

int	run_process(char *num, char *pathname)
{
	num = sanitize_number(num);
	if (!num)
	{
		print_error();
		free(num);
		return (0);
	}
	process_num(num, pathname);
	free(num);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*num;
	char	*pathname;

	if (argc == 2)
	{
		num = argv[1];
		pathname = "./numbers.dict";
	}
	else if (argc == 3)
	{
		num = argv[2];
		pathname = argv[1];
	}
	else
	{
		print_error();
		return (1);
	}
	return (run_process(num, pathname));
}

/*
int	main(void)
{
	char	num[4];

	num[0] = '\0';
	num[1] = '\0';
	num[2] = '\0';
	num[3] = '\0';
	num[0] = '9';
	num[1] = '9';
	num[2] = '9';
	split_block_in_num(num);

	num[0] = '0';
	split_block_in_num(num);
	num[0] = '1';
	split_block_in_num(num);
	num[0] = '2';
	split_block_in_num(num);
	num[0] = '3';
	split_block_in_num(num);
	num[0] = '4';
	split_block_in_num(num);
	num[0] = '5';
	split_block_in_num(num);
	num[0] = '6';
	split_block_in_num(num);
	num[0] = '7';
	split_block_in_num(num);
	num[0] = '8';
	split_block_in_num(num);
	num[0] = '9';
	split_block_in_num(num);
	num[0] = '1';
	num[1] = '0';
	split_block_in_num(num);
	num[0] = '1';
	num[1] = '1';
	split_block_in_num(num);
	num[0] = '1';
	num[1] = '2';
	split_block_in_num(num);
	num[0] = '1';
	num[1] = '3';
	split_block_in_num(num);
	num[0] = '1';
	num[1] = '4';
	split_block_in_num(num);
	num[0] = '1';
	num[1] = '5';
	split_block_in_num(num);
	num[0] = '1';
	num[1] = '6';
	split_block_in_num(num);
	num[0] = '1';
	num[1] = '7';
	split_block_in_num(num);
	num[0] = '1';
	num[1] = '8';
	split_block_in_num(num);
	num[0] = '1';
	num[1] = '9';
	split_block_in_num(num);
	num[0] = '2';
	num[1] = '0';
	split_block_in_num(num);
	num[0] = '2';
	num[1] = '1';
	split_block_in_num(num);
	num[0] = '2';
	num[1] = '2';
	split_block_in_num(num);
	num[0] = '2';
	num[1] = '3';
	split_block_in_num(num);
	num[0] = '2';
	num[1] = '4';
	split_block_in_num(num);
	num[0] = '2';
	num[1] = '5';
	split_block_in_num(num);
	num[0] = '2';
	num[1] = '6';
	split_block_in_num(num);
	num[0] = '2';
	num[1] = '7';
	split_block_in_num(num);
	num[0] = '2';
	num[1] = '8';
	split_block_in_num(num);
	num[0] = '2';
	num[1] = '9';
	split_block_in_num(num);
	num[0] = '3';
	num[1] = '0';
	split_block_in_num(num);
	num[1] = '1';
	split_block_in_num(num);
	num[1] = '2';
	split_block_in_num(num);
	num[1] = '3';
	split_block_in_num(num);
	num[1] = '4';
	split_block_in_num(num);
	num[1] = '5';
	split_block_in_num(num);
	num[1] = '6';
	split_block_in_num(num);
	num[1] = '7';
	split_block_in_num(num);
	num[1] = '8';
	split_block_in_num(num);
	num[1] = '9';
	split_block_in_num(num);

}
*/