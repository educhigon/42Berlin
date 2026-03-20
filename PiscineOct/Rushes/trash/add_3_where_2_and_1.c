/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_3_where_2_and_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:28:39 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/13 14:47:30 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	add_3_where_2_and_1(int **str, sid *rules)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (rules->left[i] == 2 && rules->right[i] == 1)
			str[i][0] = 3;
		if (rules->left[i] == 1 && rules->right[i] == 2)
			str[i][3] = 3;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (rules->top[i] == 2 && rules->bottom[i] == 1)
			str[0][i] = 3;
		if (rules->top[i] == 1 && rules->bottom[i] == 2)
			str[3][i] = 3;
		i++;
	}

}