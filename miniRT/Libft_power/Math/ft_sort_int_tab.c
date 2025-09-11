/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:14:36 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/07 13:52:04 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	swap;
	int	flag;

	i = 0;
	flag = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = swap;
			flag = 1;
		}
		i++;
	}
	if (flag != 0)
	{
		ft_sort_int_tab(tab, size);
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int arr2[] = {16, 17, 64, 77, 85, 92, 126};
	int i = 0;

	ft_sort_int_tab(arr2, 7);
	while (i < 7)
	{
		printf("%d,", arr2[i]);
		i++;
	}
	
	printf("\n");

	int	arr1[] = {1, 4, 7, 5, 2, 6, 9, 3};
	i = 0;

	ft_sort_int_tab(arr1, 8);
	while (i < 8)
	{
		printf("%d,", arr1[i]);
		i++;
	}
}
*/
