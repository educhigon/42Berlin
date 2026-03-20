/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclusion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:37:15 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/12 16:04:16 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void exclusion(char **src, int number, int **matrix)
{
	int i;
	int j;
	int k;
	int sum;

	i = 1;
	while(i < 5)
	{
		j = 1;
		while(j < 5)
		{
			if (src[i][j] == number)
			{
				k = 1;
				while(k < 5)
				{
					matrix[i][k] = 0;
					k++;
				}
				k = 1;
				while(k < 5)
				{
					matrix[k][j] = 0;
					k++;
				}
			}
			j++;
		}
		i++;
	}
}

int count_places_available(int **matrix)
{
	int i;
	int j;
	int sum;

	sum = 0;
	i = 1;
	while(i < 5)
	{
		j = 1;
		while(j < 5)
		{
			sum += matrix[i][j];
			j++;
		}
		i++;
	}
}