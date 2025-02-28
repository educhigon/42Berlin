/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:15:23 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/07 13:47:47 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <unistd.h>
#include <stdio.h>
int main() 
{
	int a = 5;
	int b = 2;
	int div = 0;
	int mod = 0;
	int *div_p = &div;
	int *mod_p = &mod;

	ft_div_mod(a, b, div_p, mod_p);

	printf("DIV: %d \n", div);
	printf("MOD: %d", mod);
}
*/
