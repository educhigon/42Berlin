/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:38:16 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/12 16:10:10 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void renew_matrix(int **matrix)
{
	int i;
	int j;

	i = 1;
	while(i < 5)
	{
		j = 1;
		while(j < 5)
		{
			matrix[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	input_basic_rules(char **str)
{
	int number_counter[4] = {0, 0, 0, 0, 0};
	int matrix[4][4];
	int sum;

	number_counter[1] = count_missing_numbers(str, 1);
	number_counter[2] = count_missing_numbers(str, 2);
	number_counter[3] = count_missing_numbers(str, 3);
	number_counter[4] = count_missing_numbers(str, 4);
	add_4_where_1(str);
	add_4321_where_4(str);
	add_3_where_2_and_1(str);
	add_4_where_2_and_3(str);
	if (number_counter[4] != 4)
		renew_matrix(matrix);
		exclusion(str, matrix, 4);
		sum = count_places_available(matrix);
		if (sum + number_counter[4] == 4);


}

