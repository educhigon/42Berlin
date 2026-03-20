/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:52:05 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/23 19:18:01 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


const int START = 0;
const int NUM_EXEC = 5;

#include "C04/ex00/ft_strlen.c"
#include "C04/ex01/ft_putstr.c"
#include "C04/ex02/ft_putnbr.c"
#include "C04/ex03/ft_atoi.c"
#include "C04/ex04/ft_putnbr_base.c"
#include "C04/ex05/ft_atoi_base.c"


void ex05()
{
	// char str[] = " ---+--+1ab567";
	// char base[] = "A123456789";
	// printf("\nPrint the value of '%s' written in base: %s: \n", str, base);
	// printf("Converted num: %d", ft_atoi_base(str, base));

	// char str1[] = " ---+--+12ab567";
	// char base[] = "A123456789";
	// printf("\nPrint the value of '%s' written in base: %s: \n", str1, base);
	// printf("Converted num: %d", ft_atoi_base(str1, base));

	// char str2[] = " ---+--+123ab567";
	// char base[] = "A123456789";
	// printf("\nPrint the value of '%s' written in base: %s: \n", str2, base);
	// printf("Converted num: %d", ft_atoi_base(str2, base));

	// char str3[] = " ---+--+1234ab567";
	// char base[] = "A123456789";
	// printf("\nPrint the value of '%s' written in base: %s: \n", str3, base);
	// printf("Converted num: %d", ft_atoi_base(str3, base));

	char str4[] = " ---+--+2147483649s";
	char base[] = "A123456789";
	printf("\nPrint the value of '%s' written in base: %s: \n", str4, base);
	printf("Converted num: %d", ft_atoi_base(str4, base));

	char str5[] = " ---+--+1234AB567";
	char base5[] = "AB23456789";
	printf("\nPrint the value of '%s' written in base: %s: \n", str5, base5);
	printf("Converted num: %d", ft_atoi_base(str5, base5));

	char str6[] = " ---+--+1E240";
	char base6[] = "0123456789ABCDEF";
	printf("\nPrint the value of '%s' written in base: %s: \n", str6, base6);
	printf("Converted num: %d", ft_atoi_base(str6, base6));

	char str7[] = " ---+--+11110001001000000";
	char base7[] = "01";
	printf("\nPrint the value of '%s' written in base: %s: \n", str7, base7);
	printf("Converted num: %d", ft_atoi_base(str7, base7));

	char str8[] = " 	---+--+361100";
	char base8[] = "01234567";
	printf("\nPrint the value of '%s' written in base: %s: \n", str8, base8);
	printf("Converted num: %d", ft_atoi_base(str8, base8));


}


void ex04()
{
	int nbr = 00;
	printf("\nPrint the value of '%d' in hexa: \n", nbr);
	ft_putnbr_base(nbr, "0123456789ABCDEF");

	int nbr1 = 58;
	printf("\nPrint the value of '%d' in 012: \n", nbr1);
	ft_putnbr_base(nbr1, "012");

	int nbr2 = 20;
	printf("\nPrint the value of '%d' in hexa: \n", nbr2);
	ft_putnbr_base(nbr2, "0123456789ABCDEF");

	int nbr3 = 30;
	printf("\nPrint the value of '%d' in hexa: \n", nbr3);
	ft_putnbr_base(nbr3, "0123456789ABCDEF");

	int nbr4 = 40;
	printf("\nPrint the value of '%d' in hexa: \n", nbr4);
	ft_putnbr_base(nbr4, "0123456789ABCDEF");

	int nbr5 = 50;
	printf("\nPrint the value of '%d' in hexa: \n", nbr5);
	ft_putnbr_base(nbr5, "0123456789ABCDEF");

	int nbr6 = 60;
	printf("\nPrint the value of '%d' in hexa: \n", nbr6);
	ft_putnbr_base(nbr6, "0123456789ABCDEF");

	int nbr7 = -2147483648;
	printf("\nPrint the value of '%d' in hexa: \n", nbr7);
	ft_putnbr_base(nbr7, "0123456789ABCDEF");

	int nbr8 = -2147483648;
	printf("\nPrint the value of '%d' in hexa: \n", nbr8);
	ft_putnbr_base(nbr8, "01");
}


void ex03()
{
	char arr1[] = " 	---+--+1234ab567";
	printf("\nPrint the value of '%s': '%d'\n", arr1, ft_atoi(arr1));
	char arr2[] = " 	---+--+2147483648assa";
	printf("\nPrint the value of '%s': '%d'\n", arr2, ft_atoi(arr2));
	char arr3[] = "    42asas"; // Simple positive number
	printf("\nPrint the value of '%s': '%d'\n", arr3, ft_atoi(arr3));
	char arr4[] = "    +0asas"; // Positive zero
	printf("\nPrint the value of '%s': '%d'\n", arr4, ft_atoi(arr4));
	char arr5[] = "    -0asas"; // Negative zero (should also return 0)
	printf("\nPrint the value of '%s': '%d'\n", arr5, ft_atoi(arr5));
	char arr6[] = "   ----+2147483647asas"; // Max int value
	printf("\nPrint the value of '%s': '%d'\n", arr6, ft_atoi(arr6));
	char arr7[] = "  ----+-2147483648asas"; // Min int value
	printf("\nPrint the value of '%s': '%d'\n", arr7, ft_atoi(arr7));
	char arr8[] = "    -9999999999asas"; // Underflow case
	printf("\nPrint the value of '%s': '%d'\n", arr8, ft_atoi(arr8));
	char arr9[] = "  +----5asas"; // Multiple signs
	printf("\nPrint the value of '%s': '%d'\n", arr9, ft_atoi(arr9));
	char arr10[] = ""; // Empty string
	printf("\nPrint the value of '%s': '%d'\n", arr10, ft_atoi(arr10));
	char arr11[] = "   +-12345asas"; // Multiple signs with space
	printf("\nPrint the value of '%s': '%d'\n", arr11, ft_atoi(arr11));
	char arr12[] = "   99999999999999999999asas"; // Very large number (overflow)
	printf("\nPrint the value of '%s': '%d'\n", arr12, ft_atoi(arr12));
	char arr13[] = "   \n\t\v\f\r +-+-123asas"; // Various whitespace characters
	printf("\nPrint the value of '%s': '%d'\n", arr13, ft_atoi(arr13));
	char arr14[] = "   \n\t\v\f\r +-+-sas"; // Various whitespace characters
	printf("\nPrint the value of '%s': '%d'\n", arr14, ft_atoi(arr14));
	char arr15[] = "   \n\t\v\f\r +-+-10000"; // Various whitespace characters
	printf("\nPrint the value of '%s': '%d'\n", arr15, ft_atoi(arr15));


}

void ex02()
{
	// int nbr1 = -2147483648;
	// printf("\nPrint the nbr: '%d' - 1\n", nbr1);
	// ft_putnbr(-2147483648 - 1);
	// int nbr2 = 2147483647;
	// printf("\nPrint the nbr: '%d' + 1\n", nbr2);
	// ft_putnbr(2147483647 + 1);
	int nbr3 = -2147483648;
	printf("\nPrint the nbr: '%d'\n", nbr3);
	ft_putnbr(-2147483648);
	int nbr4 = 2147483647;
	printf("\nPrint the nbr: '%d'\n", nbr4);
	ft_putnbr(2147483647);
	int nbr5 = -0;
	printf("\nPrint the nbr: '%d'\n", nbr5);
	ft_putnbr(-0);
	int nbr6 = 0;
	printf("\nPrint the nbr: '%d'\n", nbr6);
	ft_putnbr(0);
	int nbr7 = 120;
	printf("\nPrint the nbr: '%d'\n", nbr7);
	ft_putnbr(120);
}

void ex01()
{
	char arr1[] = "0123456789";
	printf("\nPrint the string: '%s'\n", arr1);
	ft_putstr(arr1);

	char arr2[] = "01234";
	printf("\nPrint the string: '%s'\n", arr2);
	ft_putstr(arr2);
}

void ex00()
{
	char arr1[] = "0123456789";
	printf("\nlength of '%s' is: %d", arr1, ft_strlen(arr1));
	char arr2[] = "01234";
	printf("\nlength of '%s' is: %d", arr2, ft_strlen(arr2));
	char arr3[] = "";
	printf("\nlength of '%s' is: %d", arr3, ft_strlen(arr3));
}

void find_ex(int i)
{
	switch (i)
	{
	case 0:
		ex00();
		break;
	case 1:
		ex01();
		break;
	case 2:
		ex02();
		break;
	case 3:
		ex03();
		break;
	case 4:
		ex04();
		break;
	case 5:
		ex05();
		break;
	default:
		break;
	}
}

int main()
{
	int i = START;

	while(i <= NUM_EXEC)
	{
		printf("\n\n#-------TESTING EX%d  ----------------: \n", i);
		find_ex(i);
		i++;
	}
}