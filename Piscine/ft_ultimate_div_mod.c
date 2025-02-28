/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:21:37 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/07 13:48:46 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;

	div = *a / *b;
	*b = *a % *b;
	*a = div;
}
/*
#include <unistd.h>
#include <stdio.h>
int main() {

	int a = 5;
	int b = 3;
	int *a_p = &a;
	int *b_p = &b;
	
	ft_ultimate_div_mod(a_p,b_p);

	printf("Original were 5 and 3 \n");
	printf("div should be 1, it is: %d \n", a);
	printf("mod should be 2, it is: %d", b);
}
*/
