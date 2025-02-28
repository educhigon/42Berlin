/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkolosow <jkolosow@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:27:09 by jkolosow          #+#    #+#             */
/*   Updated: 2024/10/19 15:50:15 by jkolosow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return ((c == ' ') || (c == '\b') || (c == '\t') || (c == '\n') 
		|| (c == '\v') || (c == '\f') || (c == '\r'));
}

char	*move_spaces(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	return (str);
}

char	*extract_number(char *start, char *end)
{
	int		index;
	char	*number;

	index = 0;
	number = malloc((end - start + 1) * sizeof(char));
	if (!number)
		return (NULL); 
	while (index < (end - start + 1))
	{
		number[index] = start[index];
		index++;
	}
	number[index] = '\0';
	return (number);
}

char	*sanitize_number(char *str)
{
	int		index;

	index = 0;
	str = move_spaces(str);
	if (*str == '-')
		return (NULL);
	else if (*str == '+')
		str++;
	while (*str == '+' || *str == '-')
		return (NULL);
	if (!ft_is_digit(*str))
		return (NULL);
	while (*str == '0' && *(str + 1) != '\0' && ft_is_digit(*(str + 1)))
		str++;
	while (ft_is_digit(str[index]))
		index++;
	if (str[index] == '.')
		return (NULL);
	if (*str == '\0')
		return (NULL);
	return (extract_number(str, str + index - 1));
}

/*
int	main(void)
{
	char test1[] = "123"; // 123
	printf("'%s' -> '%s'\n", test1, sanitize_number(test1));
	char test2[] = "-456"; // -456
	printf("'%s' -> '%s'\n", test2, sanitize_number(test2));
	char test3[] = " 789"; // 789
	printf("'%s' -> '%s'\n", test3, sanitize_number(test3));
	char test4[] = " -321"; // -321
	printf("'%s' -> '%s'\n", test4, sanitize_number(test4));
	char test5[] = "42abc"; // 42
	printf("'%s' -> '%s'\n", test5, sanitize_number(test5));
	char test6[] = "-7xyz"; // -7
	printf("'%s' -> '%s'\n", test6, sanitize_number(test6));
	char test7[] = ""; // (null)
	printf("'%s' -> '%s'\n", test7, sanitize_number(test7));
	char test8[] = "    "; // (null)
	printf("'%s' -> '%s'\n", test8, sanitize_number(test8));
	char test9[] = "2147483648"; // 2147483648
	printf("'%s' -> '%s'\n", test9, sanitize_number(test9));
	char test10[] = "-2147483649"; // -2147483649
	printf("'%s' -> '%s'\n", test10, sanitize_number(test10));
	char test11[] = "-0"; // (null)
	printf("'%s' -> '%s'\n", test11, sanitize_number(test11));
	char test12[] = "--123"; // (null)
	printf("'%s' -> '%s'\n", test12, sanitize_number(test12));
	char test13[] = "-+123"; // (null)
	printf("'%s' -> '%s'\n", test13, sanitize_number(test13));
	char test14[] = "abc123"; // (null)
	printf("'%s' -> '%s'\n", test14, sanitize_number(test14));
	char test15[] = "12.34"; // 12
	printf("'%s' -> '%s'\n", test15, sanitize_number(test15));
	char test16[] = "999999999"; // 999999999
	printf("'%s' -> '%s'\n", test16, sanitize_number(test16));
	char test17[] = "-999999999"; // -999999999
	printf("'%s' -> '%s'\n", test17, sanitize_number(test17));
	char test18[] = " -42abc "; // -42
	printf("'%s' -> '%s'\n", test18, sanitize_number(test18));
	char test19[] = " +34xyz "; // 34
	printf("'%s' -> '%s'\n", test19, sanitize_number(test19));
	char test20[] = "000123"; // 123
	printf("'%s' -> '%s'\n", test20, sanitize_number(test20));
	char test21[] = "-000456"; // -456
	printf("'%s' -> '%s'\n", test21, sanitize_number(test21));
	char test22[] = "0"; // 0
	printf("'%s' -> '%s'\n", test22, sanitize_number(test22));
	char test23[] = "1"; // 1
	printf("'%s' -> '%s'\n", test23, sanitize_number(test23));
	char test24[] = "0a"; // 0
	printf("'%s' -> '%s'\n", test24, sanitize_number(test24));
	char test25[] = "00000000"; // 0
	printf("'%s' -> '%s'\n", test25, sanitize_number(test25));
	return (0);
}
*/
