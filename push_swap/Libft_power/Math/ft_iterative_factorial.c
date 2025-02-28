/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:12:24 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/24 10:06:54 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fact;

	i = 0;
	fact = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (i < nb)
	{
		fact *= nb - i;
		i++;
	}
	return (fact);
}
