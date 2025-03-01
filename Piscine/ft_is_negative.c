/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:52:45 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/06 15:16:44 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int num)
{
	int	i;

	if (num < 0)
	{
		i = 78;
		write(1, &i, 1);
	}
	else
	{
		i = 80;
		write(1, &i, 1);
	}
}
/*
int main() {
	ft_is_negative(4);
	ft_is_negative(-3);
	ft_is_negative(0);
}
*/
