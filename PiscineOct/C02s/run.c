/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:12:00 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/14 15:53:02 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>

const int START = 0;
const int NUM_EXEC = 11;

#include "C02/ex00/ft_strcpy.c"
#include "C02/ex01/ft_strncpy.c"
#include "C02/ex02/ft_str_is_alpha.c"
#include "C02/ex03/ft_str_is_numeric.c"
#include "C02/ex04/ft_str_is_lowercase.c"
#include "C02/ex05/ft_str_is_uppercase.c"
#include "C02/ex06/ft_str_is_printable.c"
#include "C02/ex07/ft_strupcase.c"
#include "C02/ex08/ft_strlowcase.c"
#include "C02/ex09/ft_strcapitalize.c"
#include "C02/ex10/ft_strlcpy.c"
#include "C02/ex11/ft_putstr_non_printable.c"
// #include "C02/ex12/ft_print_memory.c"

void ex12()
{

}

void ex11()
{
	char arr1[] = "Coucou\ntu vas bien ?";
	printf("--- Original: \n%s\n", arr1);
	ft_putstr_non_printable(arr1);
	printf("\n\n");
	char arr2[] = "Coucou\ttu vas bien ?";
	printf("--- Original: \n%s\n", arr2);
	ft_putstr_non_printable(arr2);
}

void ex10()
{
	char src0[] = "1234";

	printf("\n-------Test -1\n");
	printf("\nSRC = 5 char, DEST = 4 char, n = 4 char\n");
	unsigned int nn = 4;
	char destt[nn];
	unsigned int ress;
	ress = ft_strlcpy(destt, src0, nn);
	printf("Dest: '%s' \n", destt);
	printf("Result number: %d \n", ress);


	printf("\n-------Test 0\n");
	printf("\nSRC = 5 char, DEST = 3 char, n = 3 char\n");
	unsigned int n = 3;
	char dest[n];
	unsigned int res;
	res = ft_strlcpy(dest, src0, n);
	printf("Source: %s \n", src0);
	printf("Dest: '%s' \n", dest);
	printf("Result number: %d \n", res);

	char src[] = "123456789 Trying different things!";

	printf("\n-------Test 1\n");
	printf("\nSRC = 35 char, DEST = 6 char, n = 6 char\n");
	unsigned int n1 = 6;
	char dest1[n1];
	unsigned int res1;
	res1 = ft_strlcpy(dest1, src, n1);
	printf("Source: %s \n", src);
	printf("Dest: '%s' \n", dest1);
	printf("Result number: %d \n", res1);

	printf("\n-------Test 2\n");
	printf("\nSRC = 35 char, DEST = 60 char, n = 60 char\n");
	unsigned int n2 = 60;
	char dest2[n2];
	unsigned int res2;
	res2 = ft_strlcpy(dest2, src, n2);
	printf("Source: %s \n", src);
	printf("Dest: '%s' \n", dest2);
	printf("Result number: %d \n", res2);

	printf("\n-------Test 3\n");
	printf("\nSRC = 35 char, DEST = 6 char, n = 10 char\n");
	unsigned int n3 = 10;
	char dest3[6];
	unsigned int res3;
	res3 = ft_strlcpy(dest3, src, n3);
	printf("Source: %s \n", src);
	printf("Dest: '%s' \n", dest3);
	printf("Result number: %d \n", res3);

	printf("\n-------Test 4\n");
	printf("\nSRC = 35 char, DEST = 6 char, n = 3 char\n");
	unsigned int n4 = 3;
	char dest4[6];
	unsigned int res4;
	res4 = ft_strlcpy(dest4, src, n4);
	printf("Source: %s \n", src);
	printf("Dest: '%s' \n", dest4);
	printf("Result number: %d \n", res4);

	printf("\n-------Test 5\n");
	printf("\nSRC = 35 char, DEST = 60 char, n = 50 char\n");
	unsigned int n5 = 50;
	char dest5[60];
	unsigned int res5;
	res5 = ft_strlcpy(dest5, src, n5);
	printf("Source: %s \n", src);
	printf("Dest: '%s' \n", dest5);
	printf("Result number: %d \n", res5);

	printf("\n-------Test 6\n");
	printf("\nSRC = 35 char, DEST = 60 char, n = 65 char\n");
	unsigned int n6 = 65;
	char dest6[60];
	unsigned int res6;
	res6 = ft_strlcpy(dest6, src, n6);
	printf("Source: %s \n", src);
	printf("Dest: '%s' \n", dest6);
	printf("Result number: %d \n", res6);
}

void ex09()
{
	char *response;

	char arr[] = "MAIUSCULA";
	response = ft_strcapitalize(arr);
	printf("Capitalize this string: 'MAIUSCULA'\n--The result is = %s\n", response);
	char arr2[] = "minusculaMAIUSCULA";
	response = ft_strcapitalize(arr2);
	printf("Capitalize this string: 'minusculaMAIUSCULA'\n--The result is = %s\n", response);
	char arr3[] = "";
	response = ft_strcapitalize(arr3);
	printf("Capitalize this string: ''\n--The result is = %s\n", response);
	char arr4[] = "minusculaMAIUSCULA MAIUSCULA 42Mini";
	response = ft_strcapitalize(arr4);
	printf("Capitalize this string: 'minusculaMAIUSCULA MAIUSCULA 42Mini'\n--The result is = %s\n", response);
	char arr5[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	response = ft_strcapitalize(arr5);
	printf("Capitalize this string: 'salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un' \nThe result is = %s\n", response);

}

void ex08()
{
	char arr[] = "YOGOYGY";
	char *response;
	response = ft_strlowcase(arr);
	printf("This string: YOGOYGY - should be 'yogoygy'. The result is = %s\n", response);
	char arr2[] = "hjklbyogYOGOYGY";
	response = ft_strlowcase(arr2);
	printf("This string: hjklbyogYOGOYGY - should be 'hjklbyogyogoygy'. The result is = %s\n", response);
	char arr3[] = "";
	response = ft_strlowcase(arr3);
	printf("Checking %s - Return should be 1. RETURN = %s\n", arr3, response);

}

void ex07()
{
	char arr[] = "YOGOYGY";
	char *response;
	response = ft_strupcase(arr);
	printf("This string: YOGOYGY - should be 'YOGOYGY'. The result is = %s\n", response);
	char arr2[] = "hjklbyogYOGOYGY";
	response = ft_strupcase(arr2);
	printf("This string: hjklbyogYOGOYGY - should be 'HJKLBYOGYOGOYGY'. The result is = %s\n", response);
	char arr3[] = "";
	response = ft_strupcase(arr3);
	printf("Checking %s - Return should be 1. RETURN = %s\n", arr3, response);

}

void ex06()
{
	int i = 0;
	char arr1[96];

	arr1[0] = ' ';
	while (arr1[i] != '~')
	{
		arr1[i + 1] = arr1[i] + 1;
		i++;
	}

	int response;
	response = ft_str_is_printable(arr1);
	printf("Checking %s\n - Return should be 1. RETURN = %d\n", arr1, response);

	char arr2[97];
	arr2[0] = ' ';

	i = 1;
	while (arr1[i] != '~')
	{
		arr2[i + 1] = arr2[i] + 1;
		i++;
	}
	arr2[0] = '\n';
	
	response = ft_str_is_printable(arr2);
	printf("Checking %s\n - Return should be 0. RETURN = %d\n", arr2, response);

	char arr3[] = "";
	response = ft_str_is_printable(arr3);
	printf("Checking %s - Return should be 1. RETURN = %d\n", arr3, response);

}

void ex05()
{
	char arr[] = "YOGOYGY";
	int response;
	response = ft_str_is_uppercase(arr);
	printf("Checking %s - Return should be 1. RETURN = %d\n", arr, response);
	char arr2[] = "hjklbyogYOGOYGY";
	response = ft_str_is_uppercase(arr2);
	printf("Checking %s - Return should be 0. RETURN = %d\n", arr2, response);
	char arr3[] = "";
	response = ft_str_is_uppercase(arr3);
	printf("Checking %s - Return should be 1. RETURN = %d\n", arr3, response);

}

void ex04()
{
	char arr[] = "adsfdghgjk";
	int response;
	response = ft_str_is_lowercase(arr);
	printf("Checking %s - Return should be 1. RETURN = %d\n", arr, response);
	char arr2[] = "hjklbyogYOGOYGY";
	response = ft_str_is_lowercase(arr2);
	printf("Checking %s - Return should be 0. RETURN = %d\n", arr2, response);
	char arr3[] = "";
	response = ft_str_is_lowercase(arr3);
	printf("Checking %s - Return should be 1. RETURN = %d\n", arr3, response);

}

void ex03()
{
	char arr[] = "012345654681235184320";
	int response;
	response = ft_str_is_numeric(arr);
	printf("Checking %s - Return should be 1. RETURN = %d\n", arr, response);
	char arr2[] = "013815A651302";
	response = ft_str_is_numeric(arr2);
	printf("Checking %s - Return should be 0. RETURN = %d\n", arr2, response);
	char arr3[] = "";
	response = ft_str_is_numeric(arr3);
	printf("Checking %s - Return should be 1. RETURN = %d\n", arr3, response);

}

void ex02()
{
	char arr[] = "hello";
	int response;
	response = ft_str_is_alpha(arr);
	printf("Checking %s - Return should be 1. RETURN = %d\n", arr, response);
	char arr2[] = "hello@";
	response = ft_str_is_alpha(arr2);
	printf("Checking %s - Return should be 0. RETURN = %d\n", arr2, response);
	char arr3[] = "";
	response = ft_str_is_alpha(arr3);
	printf("Checking %s - Return should be 1. RETURN = %d\n", arr3, response);

}

void ex01()
{
	char src[] = "Very cool! Trying different things!";

	printf("\n-------Test 1\n");
	printf("\nSRC = 35 char, DEST = 6 char, n = 6 char\n");
	unsigned int n1 = 6;
	char dest1[n1];
	char *pointer1;
	pointer1 = ft_strncpy(dest1, src, n1);
	printf("Dest: %s \n", dest1);
	printf("Pointer: '%s' \n", pointer1);
	printf("Last char on pos %d of dest: '%c' = %d\n", n1-1, dest1[n1-1], dest1[n1-1]);
	printf("Last char on pos %d of dest: '%c' = %d\n", n1, dest1[n1], dest1[n1]);

	printf("\n-------Test 2\n");
	printf("\nSRC = 35 char, DEST = 50 char, n = 50 char\n");
	unsigned int n2 = 50;
	char dest2[n2];
	char *pointer2;
	pointer2 = ft_strncpy(dest2, src, n2);
	printf("Dest: %s \n", dest2);
	printf("Pointer: '%s' \n", pointer2);
	printf("Last char on pos %d of dest: '%c' = %d\n", n2-1, dest2[n2-1], dest2[n2-1]);

	printf("\n-------Test 3\n");
	printf("\nSRC = 35 char, DEST = 70 char, n = 50 char\n");
	unsigned int n3 = 50;
	char dest3[70];
	char *pointer3;
	pointer3 = ft_strncpy(dest3, src, n3);
	printf("Dest: %s \n", dest3);
	printf("Pointer: '%s' \n", pointer3);
	printf("Last char on pos %d of dest: '%c' = %d\n", 70-1, dest3[70-1], dest3[70-1]);


	printf("\n-------Test 4\n");
	printf("\nSRC = 35 char, DEST = 20 char, n = 10 char\n");
	unsigned int n4 = 10;
	char dest4[20];
	char *pointer4;
	pointer4 = ft_strncpy(dest4, src, n4);
	printf("Dest: %s \n", dest4);
	printf("Pointer: '%s' \n", pointer4);
	printf("Last char on pos %d of dest: '%c' = %d\n", 20-1, dest4[20-1], dest4[20-1]);
}

void ex00()
{

	char src[] = "Very cool! Trying different things!";
	int len;
	len = sizeof(src)/sizeof(src[0]);

	char dest[len];
	char *pointer;
	pointer = ft_strcpy(dest, src);
	
	printf("%s", dest);
	printf("\n%s", pointer);
	
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
	case 6:
		ex06();
		break;
	case 7:
		ex07();
		break;
	case 8:
		ex08();
		break;
	case 9:
		ex09();
		break;
	case 10:
		ex10();
		break;
	case 11:
		ex11();
		break;
	case 12:
		ex12();
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