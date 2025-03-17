/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:52:22 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/24 10:07:10 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	powered;
	int	i;

	powered = nb;
	i = 1;
	if (power < 0)
		return (0);
	if (nb == 0 || power == 0)
		return (1);
	while (i < power)
	{
		powered *= nb;
		i++;
	}
	return (powered);
}
