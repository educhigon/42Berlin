/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_missing_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:39:46 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/12 15:54:17 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void count_missing_numbers(char **src, int number)
{
	int i;
	int j;
	int counter;

	i = 1;
	counter = 0;
	while(i < 5)
	{
		j = 1;
		while(j < 5)
		{
			if (src[i][j] == number)
				counter++;
			j++;
		}
		i++;
	}
	return(counter);
}