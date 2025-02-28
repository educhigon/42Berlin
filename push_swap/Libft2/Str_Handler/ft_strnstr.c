/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   
ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:59:31 by edugonza          #+#    #+#             */
/*   Updated: 2024/11/06 12:51:28 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *big, char *little, unsigned long len)
{
	unsigned long	i;
	unsigned long	j;

	if ((big[0] == '\0' && little[0] == '\0') || little[0] == '\0')
		return (&big[0]);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
			j++;
		if (little[j] == '\0')
			return (&big[i]);
		i++;
	}
	return (0);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int main(void)
{

	// char str[] = "ab c abcd abcde";
	char str[] = "aabc abcd abcde";

	char to_find1[] = "bcd"; 
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find1, ft_strnstr(str, to_find1, 15));
	char to_findo1[] = "bcd";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo1, strnstr(str, to_findo1, 15));

	char to_find2[] = "bcd"; 
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find2, ft_strnstr(str, to_find2, 4));
	char to_findo2[] = "bcd";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo2, strnstr(str, to_findo2, 4));


	char to_find3[] = "bcde";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find3, ft_strnstr(str, to_find3, 15));
	char to_findo3[] = "bcde";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo3, strnstr(str, to_findo3, 15));

	char to_find4[] = "bcde";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find4, ft_strnstr(str, to_find4, 4));
	char to_findo4[] = "bcde";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo4, strnstr(str, to_findo4, 4));


	char to_find5[] = "bdd";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find5, ft_strnstr(str, to_find5, 15));
	char to_findo5[] = "bdd";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo5, strnstr(str, to_findo5, 15));

	char to_find6[] = "bdd";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find6, ft_strnstr(str, to_find6, 4));
	char to_findo6[] = "bdd";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo6, strnstr(str, to_findo6, 4));


	char to_find7[] = "";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find7, ft_strnstr(str, to_find7, 15));
	char to_findo7[] = "";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo7, strnstr(str, to_findo7, 15));

	char to_find8[] = "";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find8, ft_strnstr(str, to_find8, 4));
	char to_findo8[] = "";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo8, strnstr(str, to_findo8, 4));


	char to_find9[] = "678";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find9, ft_strnstr(str, to_find9, 15));
	char to_findo9[] = "678";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo9, strnstr(str, to_findo9, 15));

	char to_find10[] = "678";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find10, ft_strnstr(str, to_find10, 4));
	char to_findo10[] = "678";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo10, strnstr(str, to_findo10, 4));


	char to_find11[] = "aabc abcd abcde";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find11, ft_strnstr(str, to_find11, 15));
	char to_findo11[] = "aabc abcd abcde";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo11, strnstr(str, to_findo11, 15));

	char to_find12[] = "aabc abcd abcde";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find12, ft_strnstr(str, to_find12, 4));
	char to_findo12[] = "aabc abcd abcde";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo12, strnstr(str, to_findo12, 4));


	char to_find13[] = "aabc abcd abcdef";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find13, ft_strnstr(str, to_find13, 15));
	char to_findo13[] = "aabc abcd abcdef";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo13, strnstr(str, to_findo13, 15));

	char to_find14[] = "aabc abcd abcdef";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find14, ft_strnstr(str, to_find14, 4));
	char to_findo14[] = "aabc abcd abcdef";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo14, strnstr(str, to_findo14, 4));


	char str_empty[] = "";
	char to_find15[] = "abc";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_empty, to_find15, ft_strnstr(str_empty, to_find15, 15));
	char str_emptyo[] = "";
	char to_findo15[] = "abc";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_emptyo, to_findo15, strnstr(str_emptyo, to_findo15, 15));

	char str_empty1[] = "";
	char to_find16[] = "abc";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_empty1, to_find16, ft_strnstr(str_empty1, to_find16, 4));
	char str_emptyo1[] = "";
	char to_findo16[] = "abc";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_emptyo1, to_findo16, strnstr(str_emptyo1, to_findo16, 4));


	char str_empty2[] = "";
	char to_find17[] = "";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_empty2, to_find17, ft_strnstr(str_empty2, to_find17, 15));
	char str_emptyo2[] = "";
	char to_findo17[] = "";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_emptyo2, to_findo17, strnstr(str_emptyo2, to_findo17, 15));

	char str_empty3[] = "";
	char to_find18[] = "";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_empty3, to_find18, ft_strnstr(str_empty3, to_find18, 4));
	char str_emptyo3[] = "";
	char to_findo18[] = "";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_emptyo3, to_findo18, strnstr(str_emptyo3, to_findo18, 4));


	char to_find19[] = "abcde";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find19, ft_strnstr(str, to_find19, 15));
	char to_findo19[] = "abcde";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo19, strnstr(str, to_findo19, 15));

	char to_find20[] = "abcde";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find20, ft_strnstr(str, to_find20, 4));
	char to_findo20[] = "abcde";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo20, strnstr(str, to_findo20, 4));


	char to_find21[] = "abcde123";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find21, ft_strnstr(str, to_find21, 15));
	char to_findo21[] = "abcde123";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo21, strnstr(str, to_findo21, 15));

	char to_find22[] = "abcde123";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_find22, ft_strnstr(str, to_find22, 4));
	char to_findo22[] = "abcde123";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str, to_findo22, strnstr(str, to_findo22, 4));

	char str_franc[] = "abcdefgh";
	char to_find23[] = "abc";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_franc, to_find23, ft_strnstr(str_franc, to_find23, 2));
	char str_franco[] = "abcdefgh";
	char to_findo23[] = "abc";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_franco, to_findo23, strnstr(str_franco, to_findo23, 2));

	char str_franc1[] = "abcdefgg";
	char to_find24[] = "bc";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_franc1, to_find24, ft_strnstr(str_franc1, to_find24, 2));
	char str_franco1[] = "abcdefgg";
	char to_findo24[] = "bc";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_franco1, to_findo24, strnstr(str_franco1, to_findo24, 2));

	char str_franc2[] = "aaxx";
	char to_find25[] = "xx";
printf("Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_franc2, to_find25, ft_strnstr(str_franc2, to_find25, 3));
	char str_franco2[] = "aaxx";
	char to_findo25[] = "xx";
printf("ORIGINAL - Find in this str: '%s' this str: '%s' Pointer returned:
 '%s'\n", str_franco2, to_findo25, strnstr(str_franco2, to_findo25, 3));
}
*/