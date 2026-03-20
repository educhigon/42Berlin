/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_4_where_2_and_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:34:36 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/13 14:47:22 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	add_4_where_2_and_3(int **str, sid *rules)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (rules->left[i] == 2 && rules->right[i] == 3)
			str[i][1] = 4;
		if (rules->left[i] == 3 && rules->right[i] == 2)
			str[i][2] = 4;
		i++;
	}
	i = 1;
	while (i < 5)
	{
		if (rules->top[i] == 2 && rules->bottom[i] == 3)
			str[1][i] = 4;
		if (rules->top[i] == 3 && rules->bottom[i] == 2)
			str[2][i] = 4;
		i++;
	}

}