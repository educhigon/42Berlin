/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:32:05 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/24 17:33:29 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

const int	START = 0;
const int	NUM_EXEC = 4;

#include "C07-nogit/ex00/ft_strdup.c"
#include "C07-nogit/ex01/ft_range.c"
#include "C07-nogit/ex02/ft_ultimate_range.c"
#include "C07-nogit/ex03/ft_strjoin.c"
#include "C07-nogit/ex04/ft_convert_base.c"
#include "C07-nogit/ex04/ft_convert_base2.c"

// #include "C07-nogit/ex05/.c"
// #include "C07-nogit/ex06/.c"
// #include "C07-nogit/ex07/.c"



void	ex04(void)
{
	char	nbr[] = "-2147483648";
	char	base_from[] = "0123456789";
	char	base_to[] = "01";
	char	*result;

	result = ft_convert_base(nbr, base_from, base_to);
	printf("new number: %s\n", result);
}

void	ex03(void)
{
	char	*strs[] = {"hey", "there", "just", "passing", "by"};
	char	sep[] = ", - ";
	int		size;
	char	*new_string;

	size = 4;
	new_string = ft_strjoin(size, strs, sep);
	printf("%s\n", new_string);
	free(new_string);
	printf("Print this if sucessfully freed the memory\n");
	printf("WHAT HAPPENS IF SIZE > LENGHT OF STRS?");
}

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

void	ex02(void)
{
    int *range = NULL;
    int size;

    // Test 1: min < max (normal case)
    int min = 0;
    int max = 5;
    printf("Test 1: min = %d, max = %d\n", min, max);
    size = ft_ultimate_range(&range, min, max);
    printf("Size: %d\n", size);
    printf("Range: ");
    print_array(range, size);
    free(range);

    // Test 2: min = max (should return NULL and size = 0)
    min = 3;
    max = 3;
    printf("Test 2: min = %d, max = %d (min == max)\n", min, max);
    size = ft_ultimate_range(&range, min, max);
    printf("Size: %d\n", size);
    printf("Range: ");
    print_array(range, size);

    // Test 3: min > max (should return NULL and size = 0)
    min = 10;
    max = 5;
    printf("Test 3: min = %d, max = %d (min > max)\n", min, max);
    size = ft_ultimate_range(&range, min, max);
    printf("Size: %d\n", size);
    printf("Range: ");
    print_array(range, size);

    // Test 4: Negative range
    min = -3;
    max = 3;
    printf("Test 4: min = %d, max = %d (Negative range)\n", min, max);
    size = ft_ultimate_range(&range, min, max);
    printf("Size: %d\n", size);
    printf("Range: ");
    print_array(range, size);
    free(range);

    // Test 5: Large range
    min = 100;
    max = 110;
    printf("Test 5: min = %d, max = %d (Large range)\n", min, max);
    size = ft_ultimate_range(&range, min, max);
    printf("Size: %d\n", size);
    printf("Range: ");
    print_array(range, size);
    free(range);
}


void	ex01(void)
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
void	ex00(void)
{
	char src[] = "";
	printf("Original: \"%s\"\n", src);
    printf("Duplicated: \"%s\"\n", ft_strdup(src));

	char src1[] = "A";
	printf("Original: \"%s\"\n", src1);
    printf("Duplicated: \"%s\"\n", ft_strdup(src1));
	
	char src2[] = "Hello";
	printf("Original: \"%s\"\n", src2);
    printf("Duplicated: \"%s\"\n", ft_strdup(src2));

	char src3[] = "This is a longer test string.";
	printf("Original: \"%s\"\n", src3);
    printf("Duplicated: \"%s\"\n", ft_strdup(src3));
	
	char src4[] = "Special!@#$%^&*().";
	printf("Original: \"%s\"\n", src4);
    printf("Duplicated: \"%s\"\n", ft_strdup(src4));

	char src5[] = "    This string has leading and trailing spaces    ";
	printf("Original: \"%s\"\n", src5);
    printf("Duplicated: \"%s\"\n", ft_strdup(src5));

	// char src6[] = NULL;
	// printf("Original: \"%s\"\n", NULL);
    printf("Duplicated: \"%s\"\n", ft_strdup(NULL));
}

void	find_ex(int i)
{
	switch (i)
	{
	case 0:
		ex00();
		break ;
	case 1:
		ex01();
		break ;
	case 2:
		ex02();
		break ;
	case 3:
		ex03();
		break ;
	case 4:
		ex04();
		break ;
	// case 5:
	// 	ex05();
	// 	break ;
	// case 6:
	// 	ex06();
	// 	break ;
	// case 7:
	// 	ex07();
	// 	break ;
	default:
		break ;
	}
}

int	main(void)
{
	int i = START;

	while (i <= NUM_EXEC)
	{
		printf("\n\n#-------TESTING EX%d  ----------------: \n", i);
		find_ex(i);
		i++;
	}
}