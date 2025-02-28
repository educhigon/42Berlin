/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:03:21 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/07 13:46:59 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
/*
#include <unistd.h>
#include <stdio.h>
int main()
{
	int a;
	int b;
	
	a = 2;
	b = 5;
	printf("Value of a old: %d \n", a);
	printf("Value of b old: %d \n", b);

	ft_swap(&a, &b);
	
	printf("\n");
	printf("Value of a new: %d \n", a);
	printf("Value of b new: %d \n", b);
}
*/
