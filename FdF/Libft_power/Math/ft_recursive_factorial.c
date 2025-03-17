/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:43:50 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/24 10:07:02 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	fact;

	if (nb < 0)
		return (0);
	fact = 1;
	if (nb >= 0 && nb <= 1)
		return (fact);
	else
	{
		fact = ft_recursive_factorial(nb - 1);
		fact = fact * nb;
	}
	return (fact);
}
