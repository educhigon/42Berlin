/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:20:44 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/21 12:25:37 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_strings(char *word1, char *word2)
{
	int	i;

	i = 0;
	while (word2[i] == word1[i] && word1[i] != '\0' && word2[i] != '\0')
		i++;
	return ((int)(word1[i] - word2[i]));
}

void	sort_args(int argc, char **argv)
{
	int		i;
	int		flag;
	char	*temp;

	i = 1;
	flag = 0;
	while (flag < 1)
	{
		flag = 1;
		while (i + 1 < argc)
		{
			if (check_strings(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i + 1];
				argv[i + 1] = argv[i];
				argv[i] = temp;
				flag = 0;
			}
			i++;
		}
		i = 1;
	}
}

void	write_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write (1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else if (argc > 2)
		sort_args(argc, argv);
	write_args(argc, argv);
	return (0);
}
