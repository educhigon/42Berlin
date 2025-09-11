/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:59:44 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/24 17:30:03 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	size;
	int	i;

	p = NULL;
	if (min >= max)
		return (p);
	size = max - min;
	p = (int *)malloc(size * sizeof(int));
	if (!p)
		return (p);
	i = 0;
	while (i < size)
	{
		p[i] = min + i;
		i++;
	}
	return (p);
}

/*
#include <stdio.h>
void print_array(int *arr, int size)
{
    if (arr == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}
int main()
{
    int min, max;
    int *range;
    
    // Test 1: min < max (normal case)
    min = 0;
    max = 5;
    printf("Test 1: min = %d, max = %d\n", min, max);
    range = ft_range(min, max);
    printf("Range: ");
    print_array(range, max - min);
    free(range);

    // Test 2: min = max (should return NULL)
    min = 3;
    max = 3;
    printf("Test 2: min = %d, max = %d (min == max)\n", min, max);
    range = ft_range(min, max);
    printf("Range: ");
    print_array(range, 0);

    // Test 3: min > max (should return NULL)
    min = 10;
    max = 5;
    printf("Test 3: min = %d, max = %d (min > max)\n", min, max);
    range = ft_range(min, max);
    printf("Range: ");
    print_array(range, 0);

    // Test 4: Negative range
    min = -3;
    max = 3;
    printf("Test 4: min = %d, max = %d (Negative range)\n", min, max);
    range = ft_range(min, max);
    printf("Range: ");
    print_array(range, max - min);
    free(range);

    // Test 5: Large range
    min = 100;
    max = 110;
    printf("Test 5: min = %d, max = %d (Large range)\n", min, max);
    range = ft_range(min, max);
    printf("Range: ");
    print_array(range, max - min);
    free(range);

}
*/