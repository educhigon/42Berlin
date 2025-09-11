/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:49:31 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/07 13:51:09 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}
/*
#include <unistd.h>
#include <stdio.h>
int main()
{
	int arr1[8] = {1,2,3,4,5,6,7,8};
	int len = 8;
	int i = 0;

	ft_rev_int_tab(arr1, len);

	while (i < len)
	{
		printf("%d,", arr1[i]);
		i++;
	}
	printf("\n");
	
	int arr2[7] = {1,2,3,4,5,6,7};
	len = 7;
	i = 0;

	ft_rev_int_tab(arr2, len);

	while (i < len)
	{
		printf("%d,", arr2[i]);
		i++;
	}		
}
*/
