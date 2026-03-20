/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_lucas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:58:43 by lgruner           #+#    #+#             */
/*   Updated: 2024/10/09 18:59:17 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include "C02/ex00/ft_strcpy.c"
void	ex00(void)
{
	char source1[] = "12345";
	char dest1[] = "XXXXXXXXX";
	ft_strcpy(dest1, source1);
	printf("%s\n", dest1);

	char source2[] = "123456789";
	char dest2[] = "YYYYYYYYYYYYYYYYYYYYYYYYY";
	printf("%s\n", ft_strcpy(dest2, source2));
}

#include "C02/ex01/ft_strncpy.c"
void	ex01(void)
{
	char source1[] = "123456789";
	char dest1[] = "XXXXXXXXX";
	ft_strncpy(dest1, source1, 10);
	printf("%s\n", dest1);
	printf("dest[9]: %d\n", dest1[9]);

	char source2[] = "123456789123456789";
	char dest2[] = "YYYYYYYY";
	printf("%s\n", ft_strncpy(dest2, source2, 3));
	printf("dest2[3]: %d\n", dest2[3]);

	char source3[] = "123456789123456789";
	char dest3[] = "YYYYYYYY";
	printf("%s\n", ft_strncpy(dest3, source3, 10));
	printf("dest3[3]: %d\n", dest3[3]);

	char source4[] = "123456789123456789";
	char dest4[8];
	printf("%s\n", ft_strncpy(dest4, source4, 8));
	printf("%c\n", dest4[7]);

	char source5[] = "12345";
	char dest5[8];
	printf("%s\n", ft_strncpy(dest5, source5, 8));
	printf("%d\n", dest5[4]);
	printf("%d\n", dest5[5]);
	printf("%d\n", dest5[6]);
	printf("%d\n", dest5[7]);
}

#include "C02/ex02/ft_str_is_alpha.c"
void	ex02(void)
{
	char *string0 = "";
	char *string1 = "AlphaBet";
	char *string2 = "Hello world";
	char *string3 = "1234nums";
	char *string4 = "\twhitespace lkj";
	char *string5 = "[{(punct)}]!";
	
	printf("%s : %d\n", string0, ft_str_is_alpha(string0));
	printf("%s : %d\n", string1, ft_str_is_alpha(string1));
	printf("%s : %d\n", string2, ft_str_is_alpha(string2));
	printf("%s : %d\n", string3, ft_str_is_alpha(string3));
	printf("%s : %d\n", string4, ft_str_is_alpha(string4));
	printf("%s : %d\n", string5, ft_str_is_alpha(string5));
}

#include "C02/ex03/ft_str_is_numeric.c"
void	ex03(void)
{
	char *string0 = "";
	char *string1 = "123456789";
	char *string2 = "1234nums";
	char *string3 = "123 ";
	char *string4 = "\t1352321";
	char *string5 = "[213213!";
	
	printf("%s : %d\n", string0, ft_str_is_numeric(string0));
	printf("%s : %d\n", string1, ft_str_is_numeric(string1));
	printf("%s : %d\n", string2, ft_str_is_numeric(string2));
	printf("%s : %d\n", string3, ft_str_is_numeric(string3));
	printf("%s : %d\n", string4, ft_str_is_numeric(string4));
	printf("%s : %d\n", string5, ft_str_is_numeric(string5));
}

#include "C02/ex04/ft_str_is_lowercase.c"
void	ex04(void)
{
	char *string0 = "";
	char *string1 = "abcdefghijklmnopqrstuvwxyz";
	char *string2 = "Capitalized";
	char *string3 = "space between";
	char *string4 = "nums234";
	char *string5 = "[punct!";
	
	printf("%s : %d\n", string0, ft_str_is_lowercase(string0));
	printf("%s : %d\n", string1, ft_str_is_lowercase(string1));
	printf("%s : %d\n", string2, ft_str_is_lowercase(string2));
	printf("%s : %d\n", string3, ft_str_is_lowercase(string3));
	printf("%s : %d\n", string4, ft_str_is_lowercase(string4));
	printf("%s : %d\n", string5, ft_str_is_lowercase(string5));
}

#include "C02/ex05/ft_str_is_uppercase.c"
void	ex05()
{
	char *string0 = "";
	char *string1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *string2 = "Capitalized";
	char *string3 = "SPACE BETWEEN";
	char *string4 = "NUMS123";
	char *string5 = "[PUNCT!";
	
	printf("%s : %d\n", string0, ft_str_is_uppercase(string0));
	printf("%s : %d\n", string1, ft_str_is_uppercase(string1));
	printf("%s : %d\n", string2, ft_str_is_uppercase(string2));
	printf("%s : %d\n", string3, ft_str_is_uppercase(string3));
	printf("%s : %d\n", string4, ft_str_is_uppercase(string4));
	printf("%s : %d\n", string5, ft_str_is_uppercase(string5));
}

#include "C02/ex06/ft_str_is_printable.c"
void	ex06()
{
	char *string0 = "";
	char *string1 = "abcdefghijklMNOPQRSTUVWXYZ";
	char *string2 = "Capitalized with space";
	char *string3 = "\ttab and\nline feed";
	char *string4 = "123456789";
	char *string5 = "[PUNCT!-_*&%$#@";
	
	printf("%s : %d\n", string0, ft_str_is_printable(string0));
	printf("%s : %d\n", string1, ft_str_is_printable(string1));
	printf("%s : %d\n", string2, ft_str_is_printable(string2));
	printf("%s : %d\n", string3, ft_str_is_printable(string3));
	printf("%s : %d\n", string4, ft_str_is_printable(string4));
	printf("%s : %d\n", string5, ft_str_is_printable(string5));
}

#include "C02/ex07/ft_strupcase.c"
void	ex07()
{
	char string0[] = "";
	char string1[] = "abcdefghijklMNOPQRSTUVWXYZ";
	char string2[] = "Capitalized with space";
	char string3[] = "\ttab and\nline feed";
	char string4[] = "123456789";
	char string5[] = "[punct!-_*&%$#@";
	
	printf("%s\n", string0);
	ft_strupcase(string0);
	printf("%s\n", string0);

	printf("%s\n", string1);
	ft_strupcase(string1);
	printf("%s\n", string1);

	printf("%s\n", string2);
	ft_strupcase(string2);
	printf("%s\n", string2);

	printf("%s\n", string3);
	ft_strupcase(string3);
	printf("%s\n", string3);

	printf("%s\n", string4);
	ft_strupcase(string4);
	printf("%s\n", string4);

	printf("%s\n", string5);
	ft_strupcase(string5);
	printf("%s\n", string5);
}

#include "C02/ex08/ft_strlowcase.c"
void	ex08()
{
	char string0[] = "";
	char string1[] = "abcdefghijklMNOPQRSTUVWXYZ";
	char string2[] = "Capitalized WITH SPACE";
	char string3[] = "\tTAB and\nLINE FEED";
	char string4[] = "123456789";
	char string5[] = "[PUNCT!-_*&%$#@";
	
	printf("%s\n", string0);
	ft_strlowcase(string0);
	printf("%s\n", string0);

	printf("%s\n", string1);
	ft_strlowcase(string1);
	printf("%s\n", string1);

	printf("%s\n", string2);
	ft_strlowcase(string2);
	printf("%s\n", string2);

	printf("%s\n", string3);
	ft_strlowcase(string3);
	printf("%s\n", string3);

	printf("%s\n", string4);
	ft_strlowcase(string4);
	printf("%s\n", string4);

	printf("%s\n", string5);
	ft_strlowcase(string5);
	printf("%s\n", string5);
}

#include "C02/ex09/ft_strcapitalize.c"
void	ex09(void)
{
	char string0[] = "";
	char string1[] = "abcdefg";
	char string2[] = " leading space";
	char string3[] = "425 some SENTENCE with UPPERCASE";
	char string4[] = "123456789";
	char string5[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	
	printf("%s\n", string0);
	ft_strcapitalize(string0);
	ft_strcapitalize(string0);
	printf("%s\n", string0);

	printf("%s\n", string1);
	ft_strcapitalize(string1);
	printf("%s\n", string1);

	printf("%s\n", string2);
	ft_strcapitalize(string2);
	printf("%s\n", string2);

	printf("%s\n", string3);
	ft_strcapitalize(string3);
	printf("%s\n", string3);

	printf("%s\n", string4);
	ft_strcapitalize(string4);
	printf("%s\n", string4);

	printf("%s\n", string5);
	ft_strcapitalize(string5);
	printf("%s\n", string5);
}

#include "C02/ex10/ft_strlcpy.c"
void	ex10(void)
{
	char src1[] = "0123456789";
	char dest1[] = "xxxxxxxxxx";
	int return1 = ft_strlcpy(dest1, src1, sizeof(dest1));
	printf("source:'%s'\ndest:'%s'\nreturn: %d\n-\n", src1, dest1, return1);

	char src2[] = "Hello world";
	char dest2[5];
	int return2 = ft_strlcpy(dest2, src2, 4);
	printf("source:'%s'\ndest:'%s'\nreturn: %d\n-\n", src2, dest2, return2);

	char src3[] = "abcdefghijk";
	char dest3[] = "xxxxxxxxxxxxxxxxxxxxxxx";
	int return3 = ft_strlcpy(dest3, src3, 8);
	printf("source:'%s'\ndest:'%s'\nreturn: %d\n-\n", src3, dest3, return3);

	char src4[] = "Hello";
	char dest4[] = "xxxx";
	int return4 = ft_strlcpy(dest4, src4, sizeof(dest4));
	printf("source:'%s'\ndest:'%s'\nreturn: %d\n-\n", src4, dest4, return4);
}

#include "C02/ex11/ft_putstr_non_printable.c"
void	ex11(void)
{
	char str1[] = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str1);
	write(1, "\n", 1);

	char str2[40];
	int i  = 0;
	while (i < 39)
	{
		str2[i] = i + 1;
		i++;
	}
	str2[i] = '\0';
	ft_putstr_non_printable(str2);
	
}

void	print_sep(int ex_num)
{
	printf("\n*--- ex%02d\n", ex_num);
}


int	main(void)
{
	print_sep(0);
	ex00();
	print_sep(1);
	ex01();
	print_sep(2);
	ex02();
	print_sep(3);
	ex03();
	print_sep(4);
	ex04();
	print_sep(5);
	ex05();
	print_sep(6);
	ex06();
	print_sep(7);
	ex07();
	print_sep(8);
	ex08();
	print_sep(9);
	ex09();
	print_sep(10);
	ex10();
	print_sep(11);
	ex11();
}