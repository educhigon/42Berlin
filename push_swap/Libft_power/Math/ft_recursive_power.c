/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:39:23 by edugonza          #+#    #+#             */
/*   Updated: 2025/02/28 11:54:16 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	powered;

	powered = nb;
	if (power < 0)
		return (0);
	if (nb == 0 || power == 0)
		return (1);
	if (power == 1)
		return (nb);
	else
	{
		powered *= ft_recursive_power(nb, power - 1);
		return (powered);
	}
}
