/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:13:17 by edugonza          #+#    #+#             */
/*   Updated: 2024/10/22 17:10:23 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <bsd/string.h>

const int START = 0;
const int NUM_EXEC = 5;

#include "check_before_push/ex00/ft_strcmp.c"
#include "check_before_push/ex01/ft_strncmp.c"
#include "check_before_push/ex02/ft_strcat.c"
#include "check_before_push/ex03/ft_strncat.c"
#include "check_before_push/ex04/ft_strstr.c"
#include "check_before_push/ex05/ft_strlcat.c"

void ex05()
{
	// char src_or[] = "0123456789";
	// char dest_or[5] = "abcd";
	// printf("Len of function is: '%zu'\n", strlcat(dest_or, src_or, 0));
	// printf("ORIGINAL -- Final dest: '%s'\n", dest_or);
	
	char src_edu[] = "0123456789";
	char dest_edu[5] = "abcd";
	printf("Len of function is: '%u'\n", ft_strlcat(dest_edu, src_edu, 0));
	printf("EDU -- Final dest: '%s'\n", dest_edu);
}

void ex04()
{
	// char str[] = "ab c abcd abcde";
	char str[] = "aabc abcd abcde";

	char to_find[] = "bcd"; 
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find, ft_strstr(str, to_find));
	char to_find1[] = "bcde";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find1, ft_strstr(str, to_find1));
	char to_find2[] = "bdd";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find2, ft_strstr(str, to_find2));
	char to_find3[] = "";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find3, ft_strstr(str, to_find3));
	char to_find31[] = "678";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find31, ft_strstr(str, to_find31));
	char to_find8[] = "aabc abcd abcde";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find8, ft_strstr(str, to_find8));
	char to_find9[] = "aabc abcd abcdef";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find9, ft_strstr(str, to_find9));
	char str_empty[] = "";
	char to_find10[] = "abc";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str_empty, to_find10, ft_strstr(str_empty, to_find10));
	char str_empty2[] = "abc";
	char to_find11[] = "";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str_empty2, to_find11, ft_strstr(str_empty2, to_find11));
	char to_find12[] = "abcde";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find12, ft_strstr(str, to_find12));
	char to_find13[] = "abcde123";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find13, ft_strstr(str, to_find13));


	char to_find4[] = "bcd";
	printf("\nFind in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find4, strstr(str, to_find4));
	char to_find5[] = "bcde";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find5, strstr(str, to_find5));
	char to_find6[] = "bdd";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find6, strstr(str, to_find6));
	char to_find7[] = "";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find7, strstr(str, to_find7));
	char to_find71[] = "678";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_find71, strstr(str, to_find71));
	char to_findo8[] = "aabc abcd abcde";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_findo8, strstr(str, to_findo8));
	char to_findo9[] = "aabc abcd abcdef";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_findo9, strstr(str, to_findo9));
	char str_emptyo[] = "";
	char to_findo10[] = "abc";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str_emptyo, to_findo10, strstr(str_emptyo, to_findo10));
	char str_emptyo2[] = "";
	char to_findo11[] = "";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str_emptyo2, to_findo11, strstr(str_emptyo2, to_findo11));
	char to_findo12[] = "abcde";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_findo12, strstr(str, to_findo12));
	char to_findo13[] = "abcde123";
	printf("Find in this str: '%s' this str: '%s' Pointer returned: '%s'\n", str, to_findo13, strstr(str, to_findo13));



}

void ex03()
{
	char src[] = ",ABC_abc";
	char dest[] = "ABD1234";
	printf("Combine '%s' to '%s' with 5chars: ", src, dest);
	printf(": %s\n", ft_strncat(dest, src, 5));

	char src1[] = ",ABC0123456789";
	char dest1[] = "ABD1234";
	printf("Combine '%s' to '%s' with 40chars: ", src1, dest1);
	printf(": %s\n", ft_strncat(dest1, src1, 40));

}

void ex02()
{
	char src[] = "_ABC";
	char dest[] = "ABD1234";
	printf("Combine '%s' to '%s': ", src, dest);
	printf(": %s\n", ft_strcat(dest, src));

	char src1[] = "_ABC0123456789";
	char dest1[] = "ABD1234";
	printf("Combine '%s' to '%s': ", src1, dest1);
	printf(": %s\n", ft_strcat(dest1, src1));
	
	char src2[] = "_ABC0123456789";
	char dest2[] = "";
	printf("Combine '%s' to '%s': ", src2, dest2);
	printf(": %s\n", ft_strcat(dest2, src2));
}

void ex01()
{
	char s1[] = "ABC";
	char s2[] = "AB\0D";
	printf("\n\nDifference of %d chars between '%s' and '%s': %d\n", 4, s1, s2, ft_strncmp(s1, s2, 4));
	
	char s11[] = "ABCDEF";
	char s21[] = "ABC";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 5, s11, s21, ft_strncmp(s11, s21, 5));

	char s12[] = "ABCD";
	char s22[] = "AB\0D";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 3, s12, s22, ft_strncmp(s12, s22, 3));

	char s13[] = "AB";
	char s23[] = "ABCD";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 3, s13, s23, ft_strncmp(s13, s23, 3));

	char s14[] = "A";
	char s24[] = "\0";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 1, s14, s24, ft_strncmp(s14, s24, 1));

	char s15[] = "ABC";
	char s25[] = "ABCDEF";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 5, s15, s25, ft_strncmp(s15, s25, 5));

	char s16[] = "";
	char s26[] = "";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 5, s16, s26, ft_strncmp(s16, s26, 5));

	// Test with n = 0
	char s17[] = "ABC";
	char s27[] = "XYZ";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 0, s17, s27, ft_strncmp(s17, s27, 0));

	// Test where strings differ at the nth position
	char s18[] = "ABCDEF";
	char s28[] = "ABCDEX";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 6, s18, s28, ft_strncmp(s18, s28, 6));


	printf("\n\nOriginal:");




	char so1[] = "ABC";
	char so2[] = "AB\0D";
	printf("\n\nDifference of %d chars between '%s' and '%s': %d\n", 4, so1, so2, strncmp(so1, so2, 4));
	
	char so11[] = "ABCDEF";
	char so21[] = "ABC";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 5, so11, so21, strncmp(so11, so21, 5));

	char so12[] = "ABCD";
	char so22[] = "AB\0D";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 3, so12, so22, strncmp(so12, so22, 3));

	char so13[] = "AB";
	char so23[] = "ABCD";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 3, so13, so23, strncmp(so13, so23, 3));

	char so14[] = "A";
	char so24[] = "\0";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 1, so14, so24, strncmp(so14, so24, 1));

	char so15[] = "ABC";
	char so25[] = "ABCDEF";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 5, so15, so25, strncmp(so15, so25, 5));

	char so16[] = "";
	char so26[] = "";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 5, so16, so26, strncmp(so16, so26, 5));

	// Test with n = 0
	char so17[] = "ABC";
	char so27[] = "XYZ";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 0, so17, so27, strncmp(so17, so27, 0));

	// Test where strings differ at the nth position
	char so18[] = "ABCDEF";
	char so28[] = "ABCDEX";
	printf("Difference of %d chars between '%s' and '%s': %d\n", 6, so18, so28, strncmp(so18, so28, 6));

}

void ex00()
{
	char s1[] = "ABC";
	char s2[] = "ABD";
	printf("Difference between '%s' and '%s': %d\n", s1, s2, ft_strcmp(s1, s2));
	
	char s11[] = "ABC";
	char s21[] = "AB";
	printf("Difference between '%s' and '%s': %d\n", s11, s21, ft_strcmp(s11, s21));

	char s12[] = "ABC";
	char s22[] = "A";
	printf("Difference between '%s' and '%s': %d\n", s12, s22, ft_strcmp(s12, s22));

	char s13[] = "A";
	char s23[] = "A";
	printf("Difference between '%s' and '%s': %d\n", s13, s23, ft_strcmp(s13, s23));

	char s14[] = "A";
	char s24[] = "ABC";
	printf("Difference between '%s' and '%s': %d\n", s14, s24, ft_strcmp(s14, s24));

	char s15[] = "";
	char s25[] = "";
	printf("Difference between '%s' and '%s': %d\n", s15, s25, ft_strcmp(s15, s25));

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